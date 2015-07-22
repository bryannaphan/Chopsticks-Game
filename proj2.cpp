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
short random(short); 

using namespace std;

int main() {
	// Declare Variables
	short l_person(1), r_person(1), // player's left and right hand
	l_comp(1), r_comp(1); 		// computer's left and right hand
	unsigned char use_hand, 	// which hand the user is using to attack computer 
	attack(1);			// which computer hand user wants to attack 

	char choice(0); // used for switch statement

	// introduction 
	cout << "Time to play chopsticks!" << endl; 
	cout << "You and the computer each start off with one chopstick in each hand." << endl << endl;

	while (attack != 0)
	{
		// display amount of fingers each player has 
		cout << "Your Hand" << '\t' << "Computer's Hand" << endl;
		cout << "_________" << '\t' << "_______________" << endl; 
		cout << "Left:" << '\t';
	
		if (l_person >= 5)
			cout << "Dead" << '\t';
		else
			cout << l_person << '\t';

		cout << "Left:" << '\t';
		
		if (l_comp >= 5)
			cout << "Dead" << '\t';
		else
			cout << l_comp << endl;
			
		cout << "Right:" << '\t';
		
		if (r_person >= 5)
			cout << "Dead" << '\t';
		else
			cout << r_person << '\t';

		cout << "Right:" << '\t';
		
		if (r_comp >= 5)
			cout << "Dead" << '\t';
		else
			cout << r_comp << endl << endl;;

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

		else if (l_comp == 1)
		{
			if (r_person == 1)
				r_person += l_comp; 
			else if (l_person == 1)
				l_person += l_comp; 
		}

		else if (r_comp == 1)
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


	if (l_person >= 5 && r_person >= 5)
	{ 
		cout << "You lose." << endl; 
	}

	else if (l_comp >= 5 && r_comp >= 5)
	{
		cout << "You win!." << endl; 
	}

return 0; 
}


// random number generator for computer moves 
// 1 == left, 2 == right
short random(short)
{	unsigned seed;
	short rand_comp; 

	cout << "Enter a seed value: "; 
	cin >> seed; 

	srand(seed); 
	rand_comp = 1 + rand() % 2; // randomly picks which hand to use and attack
	/*** End of Random generator ***/ 

	return rand_comp; 
}

char intro(char choice)
{
	cout << "Welcome to Chopsticks!" << endl << endl;

	while (choice != 3)
	{
		cout << "1. How To Play" << endl;
		cout << "2. Start Game" << endl; 
		cout << "3. Quit" << endl; 
		cout << "Pick your option: "; 
		cin >> choice;; 


	}



}



// maybe make a "switch" function with all of the menu options 

// make an option for player to choose if he wants to start first
// or if the computer should start first
// or if random choose 

// make a "Rules" function and include it into a switch statement 
// for the player to learn how to play 
// use online directions for easy typing