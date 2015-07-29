
// ****
/* FIX BOOLEAN FUNCTION 
AND FIX "do you want to play again?"
it goes with the boolean function */ 

// if user picks Y --> game automatically restarts
// if user picks N --> it goes to the menu again 

// also fix files and "best score" 
// it keeps displaying 0 so its not reading file?? 

/* 
 * File:   proj.cpp
 * Author: Bryanna Phan
 * Purpose: Play chopsticks with the computer
 * PROJECT #1
 * Created on July 14, 2015, 12:14 AM
 */

// System Libraries
#include <iostream>
#include <string> 
#include <iomanip> 
#include <fstream> 
#include <vector> 

using namespace std; 

// user libraries
struct UserInfo
{
	string name; // user name
	string date; // date played
	string time; // time played
};

// global constants
// function prototypes 
void menu(ofstream &outputFile, fstream &file); // outputs menu and switch function 
void direct(); // void function to output instructions on how to play
void game(ofstream &outputFile, fstream &file); // void function for the game 
void chart(short fingers[][2]); // function for the actual game
bool isAgain(); 

// exeuction for main begins here: 
int main() {
	
	short moves; 
	fstream file("moves.txt", ios::in | ios::out | ios::app);

	if (!file)
	{
		cout << "Error in opening the file.";
		return 0;
	}

	// opening a file to write INTO
	ofstream outputFile; 
	outputFile.open("info.txt", ios::out | ios::app);

	if (!outputFile)
	{
		cout << "Error in opening the file.";
		return 0; 
	}

	// asking for user information to write to file
	UserInfo user; // user is a UserInfo structure
	cout << "Please enter the following information." << endl;
	cout << "Name: ";
	getline(cin, user.name);
	outputFile << "Name: " << user.name << endl; 

	cout << "Date (ex: 07/02/12): ";
	getline(cin, user.date); 
	outputFile << "Date: " << user.date << endl; 

	cout << "Time (ex: 12:03 AM): ";
	getline(cin, user.time); 
	outputFile << "Time: " << user.time << endl; 

	menu(outputFile,file);
    cin.ignore(); 

file.close(); 
outputFile.close();	
return 0; 
}


void menu(ofstream &outputFile, fstream &file) 
{	// Declare Variables
	char choice(0); // used for switch statement
	// int best(0); // best score 
	// int lowest; // lowest score aka best score  
	
	// 1-D array and vectors
	short NUM_MOVES = 5; 
	vector<short>moves(NUM_MOVES); 

	// introduction 
	cout << "Welcome to Chopsticks!" << endl << endl;

	while (choice != 4)
	{
		cout << "1. Start Game" << endl;
		cout << "2. How To Play" << endl;
		cout << "3. Display Best Score" << endl;  
		cout << "4. Quit" << endl; 
		cout << "Pick your option: "; 
		cin >> choice;; 

		switch(choice) // switch statement for the menu 
		{
			case '1': {
				game(outputFile, file);
				break; 
			}

			case '2': {
				direct(); 
				break; 
			}

			case '3': {
				// while (!file.eof())
				for (int i=0; i<NUM_MOVES; i++)
				{
					file >> best;
					if (best < lowest)
						lowest = best; 
					//else if (file.eof())
						//cout << "End of file." << endl; 
				}
				cout << "Your best score is: " << lowest << endl; 
				break;
			}

			case '4': {
				cout << "The game has ended." << endl;
				return; 
				break; 
			}
			default: cout << "You didn't enter an option between 1-3. Please try again." << endl;
		}
	}
}

void direct() // output directions to play
{ 
	cout << "1. Both you and your opponent must hold out one finger from each hand." << endl << endl;
	cout << "2. You start first." << endl << endl; 
	cout << "3. Tap one of your opponent's hands with one of your fingers. Your opponent must then hold out one additional finger on the hand you tapped (for a total of two) because the hand you used to tap them with had one finger held out." << endl << endl;
	cout << "4. Let your opponent tap one of your hands." << endl << endl; 
	cout << "	- If they tap you with the hand that has one finger held out," << endl;
	cout << "	you must hold out one additional finger on your hand that they tapped" << endl; 
	cout << "	(totaling two)." << endl; 
	cout << "	- If they tap you with their hand that has two fingers held out," << endl;
	cout << "	then you must add two fingers to your hand that they tapped" << endl;
	cout << "	(totaling three)." << endl << endl;
	cout << "5. Keep taking turns tapping hands and adding fingers, but when a hand has five fingers held out, that is called a 'dead hand'." << endl;
	cout << "Put dead hands behind the player's back. The person who reaches two dead hands first loses." << endl << endl;
}


// function to display the chart of fingers in each player's hand
void chart(short fingers[][2])
{	// declare variables 
	int COMP = 2; // computer's hands
	int PERS = 2; // person's hands
	// chart to display initial fingers 
	cout << '\t'  << "Left Hand     Right Hand" << endl;
	cout << "Player:   "; 
	for (int row=0; row<PERS; row++)
	{
		for (int col=0; col<COMP; col++)
			{
				if (fingers[row][col] >= 5) 
					cout << "Dead" << '\t' << '\t';  
				else
					cout << fingers[row][col] << '\t' << '\t'; 
			}
		cout << endl;
		if (row < 1)
			cout << "Computer: ";  
	}
cout << endl; 
}

bool isAgain(char again)
{
	bool status; 

	if (again == 'y')
		status = true; 

	else if (again == 'n')
		status = false; 
return status; 
}

void game(ofstream &outputFile, fstream &file) { // function for the game
	
	// declare array size
	const int SIZE = 2; 

	// declare 2D array
	short fingers[][SIZE] = {{1,1}, {1,1}}; // initialize fingers to one on each hand

	// variables for program
	char use_hand, // hand player uses to attack
	attack; // the opponent's hand being attacked by player
	short moves(0); // number of moves
	char again; // ask if user wants to play again or not
	
	chart(fingers); // calling in chart function to display chart


	while (fingers[0][0] < 5 || fingers[0][1] < 5 || fingers[1][0] < 5 || fingers[1][1] < 5)
	{

		if (fingers[0][0] >= 5 && fingers[0][1] >= 5)
		{
			cout << "You lose." << endl; 
			outputFile << "You lost in: " << moves << " moves" << endl;
			cout << "Do you want to play again? (y/n): ";
			cin >> again;  
			if (isAgain(again))
				menu(outputFile, file); 
			else if (!isAgain(again))
				return; break;
		}
		else if (fingers[1][0] >= 5 && fingers[1][1] >= 5)
		{
			cout << "You win!" << endl;
			outputFile << "You won in: " << moves << " moves" << endl;
			file << moves << endl; 
			cout << "Do you want to play again? (y/n): ";
			cin >> again;  			
			if (isAgain(again))
				menu(outputFile, file); 
			else if (!isAgain(again))
				return; break; 
		}

		// getting user input 
		cout << "Do you want to use your L or R hand to attack? ";
		cin >> use_hand; 
		use_hand = tolower(use_hand);
		
		if (use_hand == 'l' && fingers[0][0] >= 5)
		{
			while (use_hand == 'l')
			{
				cout << "That hand is dead. Please choose your right hand to attack: ";
				cin >> use_hand;
				use_hand = tolower(use_hand);
			}
		}

		if (use_hand == 'r' && fingers[0][1] >= 5)
		{
			while (use_hand == 'r')
			{
				cout << "That hand is dead. Please choose your left hand to attack: ";
				cin >> use_hand;
				use_hand = tolower(use_hand);
			}
		}

		cout << "Do you want to attack the computer's L or R hand? ";
		cin >> attack; 
		attack = tolower(attack);

		if (attack == 'l' && fingers[1][0] >= 5)
		{
			while (attack == 'l')
			{
				cout << "That hand is already dead. Please choose to attack the Computer's right hand: ";
				cin >> attack;
				use_hand = tolower(use_hand);
			}
		}

		else if (attack == 'r' && fingers[1][1] >= 5)
		{
			while (attack == 'r')
			{
				cout << "That hand is already dead. Please choose to attack the Computer's left hand: ";
				cin >> attack;
				use_hand = tolower(use_hand);
			}
		}

		//human left: 	[0][0]
		//human right: 	[0][1]
		//comp left:	[1][0]
		//comp right: 	[1][1]	

		if (use_hand == 'l')
		{
			if (attack == 'l')
				fingers[1][0] += fingers[0][0]; 

			else if (attack == 'r')
				fingers[1][1] += fingers[0][0];
		}

		else if (use_hand == 'r')
		{
			if (attack == 'l')
				fingers[1][0] += fingers[0][1];

			else if (attack == 'r')
				fingers[1][1] += fingers[0][1];
		}

		chart(fingers); // output updated chart of fingers 

		if (fingers[0][0] >= 5 && fingers[0][1] >= 5)
		{
			cout << "You lose." << endl;
			outputFile << "You lost in: " << moves << " moves" << endl;
			cout << "Do you want to play again? (y/n): ";
			cin >> again;  
			if (isAgain(again))
				menu(outputFile, file);
			else if (!isAgain(again))
				return; break; 
		}
		else if (fingers[1][0] >= 5 && fingers[1][1] >= 5)
		{
			cout << "You win!" << endl;
			outputFile << "You won in: " << moves << " moves" << endl; 
			file << moves << endl; 
			cout << "Do you want to play again? (y/n): ";
			cin >> again;  			
			if (isAgain(again))
				menu(outputFile, file); 
			else if (!isAgain(again))
				return; break; 
		}		

		// computer's moves 
		cout << '\t' << "Computer's turn!" << '\t' << endl; 


		//human left: 	[0][0]
		//human right: 	[0][1]
		//comp left:	[1][0]
		//comp right: 	[1][1]	

		// if 1 C-hand = dead & 1 P-hand = dead
		if (fingers[1][0] >= 5 && fingers[0][1] >= 5)
			fingers[0][0] += fingers[1][1];
		
		else if (fingers[1][1] >= 5 && fingers[0][0] >= 5)
			fingers[0][1] += fingers[1][0];
		
		else if (fingers[0][0] >= 5 && fingers[1][0] >= 5)
			fingers[0][1] += fingers[1][1]; 
		
		else if (fingers[0][1] >= 5 && fingers[1][1] >= 5)
			fingers[0][0] += fingers[1][0]; 

		// if only one hand is dead 
		else if (fingers[0][0] >= 5 && fingers[1][1] < 5 && fingers[1][0] < 5 && fingers[0][1] < 5 )
		{
			if (fingers[1][1] > fingers[1][0])
				fingers[0][1] += fingers[1][1]; 

			else if (fingers[1][0] >= fingers[1][1])
				fingers[0][1] += fingers[1][0];
		}

		else if (fingers[0][1] >= 5 && fingers[1][1] < 5 && fingers[1][0] < 5 && fingers[0][0] < 5)
		{
			if (fingers[1][1] > fingers[1][0])
				fingers[0][0] += fingers[1][1]; 

			else if (fingers[1][0] >= fingers[1][1])
				fingers[0][0] += fingers[1][0];
		}

		else if (fingers[1][0] >= 5 && fingers[0][1] < 5 && fingers[0][0] < 5 && fingers[1][1] < 5)
		{
			if (fingers[0][0] > fingers[0][1])
				fingers[0][0] += fingers[1][1]; 
			
			else if (fingers[0][1] >= fingers[0][0])
				fingers[0][1] += fingers[1][1];	
		}

		else if (fingers[1][1] >= 5 && fingers[0][1] < 5 && fingers[0][0] < 5 && fingers[1][0] < 5)
		{
			if (fingers[0][0] > fingers[0][1])
				fingers[0][0] += fingers[1][0]; 
			
			else if (fingers[0][1] >= fingers[0][0])
				fingers[0][1] += fingers[1][0];	
		}


		// computer's first move
		else if (fingers[0][0] == 1 && fingers[0][1] == 1 && fingers[1][0] == 1)
		{
			if (fingers[1][0] > fingers[1][1])
				fingers[0][0] += fingers[1][1]; 

			else if (fingers[1][1] > fingers[1][0])
				fingers[0][0] += fingers[1][0]; 
		}
		
		else if (fingers[0][0] == 1 && fingers[0][1] == 1 && fingers[1][1] == 1)
		{
			if (fingers[1][0] > fingers[1][1])
				fingers[0][1] += fingers[1][1];

			else if (fingers[1][1] > fingers[1][0])
				fingers[0][1] += fingers[1][0]; 
		}

		// if all fingers are in play 
		else if (fingers[0][0] < 5 && fingers[0][1] < 5 && fingers[1][0] < 5 && fingers[1][1] < 5)
		{
			if (fingers[0][0] >= 2 && fingers[0][1] < 2)
			{
				if (fingers[1][0] >= 2)
					fingers[0][0] += fingers[1][0]; 

				else if (fingers[1][1] >= 2)
					fingers[0][0] += fingers[1][1];
			}
			else if (fingers[0][1] >= 2 && fingers[0][0] < 2)
			{
				if (fingers[1][0] >= 2)
					fingers[0][1] += fingers[1][0]; 

				else if (fingers[1][1] >= 2)
					fingers[0][1] += fingers[1][1]; 
			}

			else if (fingers[0][0] == 1 && fingers[0][1] != 1)
			{
				if (fingers[1][0] >= 4)
				{
					if (fingers[0][1] > fingers[0][0])
						fingers[0][1] += fingers[1][0];

					else if (fingers[0][0] > fingers[0][1])
						fingers[0][0] += fingers[1][0];
				}

				else if (fingers[1][1] >= 4)
				{
					if (fingers[0][1] > fingers[0][0])
						fingers[0][1] += fingers[1][1];

					else if (fingers[0][0] > fingers[0][1])
						fingers[0][0] += fingers[1][1];
				}
				
				else if (fingers[1][0] < 4 && fingers[1][1] < 4)
				{
					if (fingers[1][0] > fingers[1][1])
						fingers[0][0] += fingers[1][0];

					else if (fingers[1][1] > fingers[1][0])
						fingers[0][0] += fingers[1][1]; 
				}
			}

			else if (fingers[0][1] == 1 && fingers[0][0] != 1)
			{
				if (fingers[1][0] >= 4)
					fingers[0][1] += fingers[1][0]; 
				
				else if (fingers[1][1] >= 4)
					fingers[0][1] += fingers[1][1]; 
				
				else if (fingers[1][0] < 4 && fingers[1][1] < 4)
				{
					if (fingers[1][0] > fingers[1][1])
						fingers[0][1] += fingers[1][0];

					else if (fingers[1][1] > fingers[1][0])
						fingers[0][1] += fingers[1][1]; 
				}
			}
		}

		chart(fingers); 
		moves++;
		cout << "Moves so far: " << moves;
		cout << endl;	
	}
}
