#include "RomanNum.h"

int main()
{
	char goAgain; //used to for extra inpute trys by the user
	do {

		RomanNum* inputed = new RomanNum(); //creates a new object

		inputed->display(); //calls an object function

		delete inputed; // removes inputed data from the stack

		cout << "Do you want to enter a new number to convert? Enter Y to try again\n";
		cin >> goAgain;

	} while (goAgain == 'Y' || goAgain == 'y');

	return 0;
} //end of main

