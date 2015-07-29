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
#include <cctype>

// User Libraries
// Global Constants
// Function Prototypes
void game(); // void function for the game 
void direct(); // void function to output instructions on how to play
bool isDead(short); 

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


void direct() {

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


void game()
{
	bool l_person(1), r_person(1), // player's left and right hand
	l_comp(1), r_comp(1); 		// computer's left and right hand
	char use_hand, 	// which hand the user is using to attack computer 
	attack(1);			// which computer hand user wants to attack 

	short leftp, rightp, leftc, rightc; 


	while (!isDead(l_person) && !isDead(r_person))
	{
		/* leftp = isDead(l_person);
		rightp = isDead(r_person);
		leftc = isDead(l_comp);
		rightc = isDead(r_comp); */ 

		/* if (isDead(l_person))
			cout << "Player Left: Dead" << endl; 
		else
			cout << "Player Left: " << l_person << endl;
		

		if (isDead(r_person))
			cout << "Player Right: Dead" << endl; 
		else
			cout << "Player Right: " << r_person << endl;


		if (isDead(l_comp))
			cout << "Comp Left: Dead" << endl; 
		else
			cout << "Comp Left: " << l_comp << endl;


		if (isDead(r_comp))
			cout << "Comp Right: Dead" << endl; 
		else
			cout << "Comp Right: " << r_comp << endl;

		*/

		 
		/* // display INITIAL AMT of fingers each player has 
		cout << "Your Hand" << '\t' << "Computer's Hand" << endl;
		cout << "_________" << '\t' << "_______________" << endl; 
		cout << "Left:" << '\t' << leftp << '\t' << "Left:" << '\t' << leftc<< endl;
		cout << "Right:" << '\t' << rightp << '\t' << "Right:" << '\t' << rightc << endl << endl; 
		*/ 

			// user's turn 
			cout << '\t' << "Your turn!" << '\t' << endl; 

			// user input 
			cout << "Do you want to use your L or R hand to attack? ";
			cin >> use_hand; 
			use_hand = tolower(use_hand);
			cout << "Do you want to attack the computer's L or R hand? ";
			cin >> attack; 
			attack = tolower(attack);

			if (use_hand == 'l')
			{
				if (attack == 'l')
					l_comp += l_person;

				else if (attack == 'r')
					r_comp += l_person;


			cout << "Person Left: "; isDead(r_person);
			cout << "Person Right: "; isDead(r_person);
			cout << "Computer Left: "; isDead(l_comp);
			cout << "Computer Right: "; isDead(r_comp); 
			}

			if (use_hand == 'r')
			{
				if (attack == 'l')
					l_comp += r_person; 
				else if (attack == 'r')
					r_comp += r_person; 

			cout << "Person Left: "; isDead(r_person);
			cout << "Person Right: "; isDead(r_person);
			cout << "Computer Left: "; isDead(l_comp);
			cout << "Computer Right: "; isDead(r_comp); 
			}


	}

}

bool isDead(short player)
{

	if (player < 5)
	{
		cout << player << endl;
		return 0; 
	}
	else
	{
		cout << "Dead" << endl; 
		return true; 
	}
}


// maybe make a "switch" function with all of the menu options 

// make an option for player to choose if he wants to start first
// or if the computer should start first
// or if random choose 

