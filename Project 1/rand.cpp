
// System Libraries
#include <iostream>
#include <string> 
#include <iomanip> 

// User Libraries
// Global Constants
// Function Prototypes

using namespace std;

int main() {

/*** Random generator ***/ 
	unsigned seed;
	short rand_comp; 

	cout << "Enter a seed value: " << endl; 
	cin >> seed; 

	srand(seed); 
	rand_comp = 1 + rand() % 2; // randomly picks which hand to use and attack
	/*** End of Random generator ***/ 

	cout << rand_comp << endl; 

return 0; 
}