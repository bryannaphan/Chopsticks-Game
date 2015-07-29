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

// User Libraries
// Global Constants
// Function Prototypes
void game(); // void function for the game 
void direct(); // void function to output instructions on how to play

using namespace std;

int main() {
	// Declare Variables
	char choice(0); // used for switch statement
	
	// introduction 
	cout << "Welcome to Chopsticks!" << endl << endl;

	while (choice != 3)
	{
		cout << "1. Start Game" << endl;
		cout << "2. How To Play" << endl; 
		cout << "3. Quit" << endl; 
		cout << "Pick your option: "; 
		cin >> choice;; 

		switch(choice) // switch statement for the menu 
		{
			case '1':
			{
				game();
				break; 
			}
			
			case '2': 
			{
				direct(); 
				break; 
			}

			case '3':
			{
				cout << "The game has ended." << endl;
				return 0; 
				break; 
			}

			default: cout << "You didn't enter an option between 1-3. Please try again." << endl;
		}
	}
return 0; 
}


void direct() { // output directions to play

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


void game() // function for the game
{
	short l_person(1), r_person(1), // player's left and right hand
	l_comp(1), r_comp(1); 		// computer's left and right hand
	char use_hand, 	// which hand the user is using to attack computer 
	attack(1);			// which computer hand user wants to attack 

	ofstream outputFile; 
	// open input file to show how many moves each game was 
	outputFile.open("moves.txt", ios::out | ios::app);

	float count(0); 

	while (r_person <= 5 && l_person <=5 && r_comp <= 5 && l_comp <= 5)
	{
		for (int i=0; i<5; i++) // count how many moves 
		{
			count++;
			outputFile << "Total moves: " << count << endl;
		}
		
		if (l_person >= 5 && r_person >= 5)
		{ 
			cout << "You lose." << endl; 
		}

		else if (l_comp >= 5 && r_comp >= 5)
		{
			cout << "You win!." << endl;
		}

		// display amount of fingers each player has 
		cout << "Your Hand" << '\t' << "Computer's Hand" << endl;
		cout << "_________" << '\t' << "_______________" << endl; 
		cout << "Left:" << '\t';

		// output statements to show which hands are "dead"
		if (l_person >= 5)
			cout << "Dead" << '\t';
		else
			cout << l_person << '\t';

		cout << "Left:" << '\t';
		
		if (l_comp >= 5)
			cout << "Dead" << endl;
		else
			cout << l_comp << endl;
			
		cout << "Right:" << '\t';
		
		if (r_person >= 5)
			cout << "Dead" << '\t';
		else
			cout << r_person << '\t';

		cout << "Right:" << '\t';
		
		if (r_comp >= 5)
			cout << "Dead" << endl;
		else
			cout << r_comp << endl << endl;;

		// user's turn 
		cout << '\t' << "Your turn!" << '\t' << endl; 

		// user input 
		cout << "Do you want to use your L or R hand to attack? ";
		cin >> use_hand; 
		use_hand = tolower(use_hand);
		cout << "Do you want to attack the computer's L or R hand? ";
		cin >> attack; 
		attack = tolower(attack);

		// determining person's moves 
		if (use_hand == 'l' && l_person >= 5)
		{
			while (use_hand == 'l')
			{
				cout << "That hand is dead. Please choose another." << endl;
				cin >> use_hand;
				use_hand = tolower(use_hand);
			}
		}
		else if (use_hand == 'l' && l_person < 5)
		{
			if (attack == 'l')
				l_comp += l_person;
			else if (attack == 'r')
				r_comp += l_person;
		}
	
		if (use_hand == 'r' && r_person >= 5)
		{
			while (use_hand == 'r')
			{
				cout << "That hand is dead. Please choose another." << endl;
				cin >> use_hand;
				use_hand = tolower(use_hand);
			}
		}
		else if (use_hand == 'r' && r_person < 5)
		{
			if (attack == 'l')
				l_comp += r_person; 
			else if (attack == 'r')
				r_comp += r_person; 
		}

		// display amount of fingers each player has 
		cout << "Your Hand" << '\t' << "Computer's Hand" << endl;
		cout << "_________" << '\t' << "_______________" << endl; 
		cout << "Left:" << '\t' << l_person << '\t' << "Left:" << '\t' << l_comp << endl;
		cout << "Right:" << '\t' << r_person << '\t' << "Right:" << '\t' << r_comp << endl << endl; 
		cout << '\t' << "Computer's turn!" << '\t' << endl; 


		if (r_comp >= 3 && r_comp < 5)
		{
			if (r_person >= 2 && r_person <= 5)
				r_person += r_comp; 
			else if (l_person >= 2 && l_person <= 5)
				l_person += r_comp; 
		}

		else if (l_comp >= 3 && l_comp < 5)
		{
			if (r_person >= 2 && r_person <= 5)
				r_person += l_comp; 
			else if (l_person >= 2 && r_person <= 5)
				l_person += l_comp; 
		}

		else if (l_comp == 1 && r_person == 1 && l_person == 1)
		{
			if (r_person == 1)
				r_person += l_comp; 
			else if (l_person == 1)
				l_person += l_comp; 
		}

		else if (r_comp == 1 && r_person == 1 && l_person == 1)
		{
			if (r_person == 1)
				r_person += r_comp; 
			else if (l_person == 1)
				l_person += r_comp; 
		}

		else if (l_comp > 1 && l_comp < 5)
			r_person += l_comp; 
		else if (r_comp > 1 && r_comp < 5)
			l_person += r_comp;
	}
outputFile.close();

}



// maybe make a "switch" function with all of the menu options 

// make an option for player to choose if he wants to start first
// or if the computer should start first
// or if random choose 
