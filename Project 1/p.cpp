/* VERSION THAT WORKS FOR THE MOST PART. JUST 
L L 
R L 
L L 
DOESN'T WORK PROPERLY.  */ 

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

using namespace std; 

// function prototypes 
void game();
void chart(short fingers[][2]);
void win_lose(short fingers[][2]);

int main() {
	game();

return 0; 
}

// function to display the chart of fingers in each player's hand
void chart(short fingers[][2])
{
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

void win_lose(short fingers[][2])
{
	if (fingers[0][0] >= 5 && fingers[0][1] >= 5)
	{
		cout << "You lose." << endl;
		return;
	}

	else if (fingers[1][0] >= 5 && fingers[1][1] >= 5)
	{
		cout << "You win!" << endl;
		return;
	}
}

void game() { // function for the game

	// declare array size
	const int SIZE = 2; 

	// declare 2D array
	short fingers[][SIZE] = {{1,1}, {1,1}}; // initialize fingers to one on each hand

	// variables for program
	char use_hand, // hand player uses to attack
	attack; // the opponent's hand being attacked by player
	short moves(0); // number of moves
	
	chart(fingers); 

	while (fingers[0][0] <= 5 && fingers[1][1] <=5)
	{

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

		chart(fingers); 
		win_lose(fingers); 


		// computer's moves 
		cout << '\t' << "Computer's turn!" << '\t' << endl; 


		//human left: 	[0][0]
		//human right: 	[0][1]
		//comp left:	[1][0]
		//comp right: 	[1][1]	

		if (fingers[1][0] < 5 && fingers[1][1] < 5)
		{
			if (fingers[1][0] >= 3)
			{
				if (fingers[0][0] >= fingers[0][1])
					{ cout << "line 177" << endl; 
					fingers[0][0] += fingers[1][0]; } 
				else if (fingers[0][1] >= fingers[0][0])
					{ cout << "line 180" << endl;
					fingers[0][1] += fingers[1][0];} 
			}
			else if (fingers[1][1] >= 3)
			{
				if (fingers[0][0] >= fingers[0][1])
					{ cout << "line 186" << endl;
					fingers[0][0] += fingers[1][1]; }
				else if (fingers[0][1] >= fingers[0][0])
					{ cout << "line 189" << endl;
					fingers[0][1] += fingers[1][1];}  
			}	
		}

		if (fingers[0][0] >= 3 && fingers[0][1] >= 3)
		{
			if (fingers[1][0] >= 5)
			{
				if (fingers[0][1] > 4)
					{ cout << "line 198" << endl;
					fingers[0][0] += fingers[1][1]; } 
				else if (fingers[0][0] > 4)
					{ cout << "line 201" << endl;
					fingers[0][1] += fingers[1][1]; }
			}
			else if (fingers[1][1] >= 5)
			{
				if (fingers[0][1] > 4)
					{ cout << "line 207" << endl;
					fingers[0][0] += fingers[1][0]; } 
				else if (fingers[0][0] > 4)
					{ cout << "line 210" << endl;
					fingers[0][1] += fingers[1][0]; } 
			}
		}

		if (fingers[0][0] >= 3 && fingers[0][1] < 2) // human's left hand >= 3
		{
			if (fingers[1][0] < 5) 
			{
				if (fingers[1][0] >= 2)
					{ cout << "line 220" << endl;
					fingers[0][0] += fingers[1][0]; }
				
				else if (fingers[1][1] >= 2)
					{ cout << "line 224" << endl;
					fingers[0][0] += fingers[1][1]; }
			}
			
			else if (fingers[1][0] >= 5)
				{ cout << "line 229" << endl;
				fingers[0][0] += fingers[1][1];  }
		}

		else if (fingers[0][1] >= 3 && fingers[0][0] < 2) // human's right hand >= 3
		{
			if (fingers[1][0] < 5 || fingers[1][1] < 5)
			{
				if (fingers[1][0] >= 2)
					{ cout << "line 238" << endl;
					fingers[0][1] += fingers[1][0];} 
				
				else if (fingers[1][1] >= 2)
					{ cout << "line 242" << endl;
					fingers[0][1] += fingers[1][1]; } 
			}

			else if (fingers[1][0] >= 5)
				{ cout << "line 247" << endl;
				fingers[0][1] += fingers[1][1]; }
			else if (fingers[1][1] >= 5)
				{ cout << "line 250" << endl;
				fingers[0][1] += fingers[1][0]; }
		} 

		if (fingers[1][0] >= 5 && fingers[0][1] >= 5)
			fingers[0][0] += fingers[1][1];
		else if (fingers[1][1] >= 5 && fingers[0][0] >= 5)
			fingers[0][1] += fingers[1][0];

		else if (fingers[0][0] < 3) // human's left hand < 3 
		{
			if (fingers[1][1] < 5)
			{
				if (fingers[0][1] == 1)
				{ cout << "line 260" << endl; 
					fingers[0][1] += fingers[1][1]; 
				}

				else if (fingers[0][0] >= 1)
					{	cout << "ling 266" << endl; 
					fingers[0][0] += fingers[1][1]; }
				
				else if (fingers[0][1] > 1)
				{ cout << "line 265" << endl; 
					fingers[0][0] += fingers[1][1];
				} 
			}

			else if (fingers[1][1] >= 5)
			{ cout << "line 271" << endl;
				fingers[0][1] += fingers[1][0];
			}
		}

		else if (fingers[0][1] < 3) // human's right hand < 3 
		{
			if (fingers[1][0] < 5)
			{
				if (fingers[0][1] == 1)
					{ cout << "line 281" << endl;
					fingers[0][1] += fingers[1][0]; } 
				
				else if (fingers[0][1] > 1)
					{ cout << "line 285" << endl;
					fingers[0][0] += fingers[1][0];} 
			}

			else if (fingers[1][0] >= 5)
				{ cout << "line 290" << endl;
				fingers[0][0] += fingers[1][1];} 
		}  

		chart(fingers); 
		moves++;
		cout << "Moves so far: " << moves; 
		cout << endl;
		win_lose(fingers); 

	}
}
