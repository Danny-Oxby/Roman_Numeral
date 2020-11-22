#pragma once
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class RomanNum
{
public:
	RomanNum(); //constructor 
	~RomanNum(); //destructor
	void display(); //user input screen
	void checkStringIsRoman(const string& romanNumerals); //checks the user input
	void addingNumbs(); // adds the checked values

private:
	vector<int> numbValue; //create a vector to hold the number values of the numberals
	string romanNumerals; //holds the user input
	int convertedValue = 0; //holds the converted user value
};

inline void RomanNum::display() //user input system
{
	cout << ".......................................\n" << "Please enter the desired Roman Numeral here.\n";
	cin >> romanNumerals; //gets the input from the user

	checkStringIsRoman(romanNumerals);

	cout << convertedValue << "\n"; // print out the users value in decimal

} //end of display

