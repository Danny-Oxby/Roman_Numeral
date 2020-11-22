#include "RomanNum.h"

RomanNum::RomanNum() //constructor
{

} //end of constructor

RomanNum::~RomanNum()  //destructor
{

} //end of destructor


void RomanNum::checkStringIsRoman(const string& romanNumerals) // passed by pointer, const as the string dose not change
{
	bool invalidValue(false); // use to find if the user has entered an invalid charactor
	for (int i(0); i < romanNumerals.length(); i++) // repaet until all the string has been checked
	{
		switch (romanNumerals[i]) // checks the value in each string possition
		{
			//input is 1 
		case 'I':
		case 'i':
			//for use in the addition function later
			numbValue.push_back(1);
			break;
			//input is 5 
		case 'V':
		case 'v':
			numbValue.push_back(5);
			break;
			//input is 10
		case 'X':
		case 'x':
			numbValue.push_back(10);
			break;
			//input is 50 
		case 'L':
		case 'l':
			numbValue.push_back(50);
			break;
			//input is 100
		case 'C':
		case 'c':
			numbValue.push_back(100);
			break;
			//input is 500 
		case 'D':
		case 'd':
			numbValue.push_back(500);
			break;
			//input is 1000 
		case 'M':
		case 'm':
			numbValue.push_back(1000);
			break;
		default:
			invalidValue = true;
			break;
		}
	}

	if (invalidValue == true)
	{
		cout << "this is not a valid Roman numeral. Next time enter either: I, V, X, L, C, D, M\n";
	}
	else
	{
		numbValue.push_back(0);//ending value for the vetor
		addingNumbs();//go to adding formaular 
	}
}//end of checker

void RomanNum::addingNumbs()
{
	int prefixNumbValue (0); //holds the current value of 1's before the subtractor occurs

	for (int i(0); i < numbValue.size() -1;  i++) // size - 1 so the loops stops at the last vector value, rather than one after it
	{
		int j = i + 1; //for ease of use
		//used to see if the user has followed the ordering rules for roman numerals
		if (numbValue[i] < numbValue[j] && j < numbValue.size()) //if the current value is smaller than the next one and next value sint the end of vector
		{
			//note to self, there can only be one prifix value at a time so no '3' prefix
			if (numbValue[i] == 5 || prefixNumbValue !=0 ) // this is to find if there is a prefix value (e.g. IX for 9 ) as 'V'/'5' is not a valid prefix value
			{
				cout << "This is not a valid roman numeral, please enter a valid numeral\n";
				break;
			}
			else // if the current value is a valid prefix
			{
				prefixNumbValue = numbValue[i]; // copys the current value to prefixNumbvalue
			}
		}
		else
		{
			convertedValue += numbValue[i] - prefixNumbValue; //removes the prefix value from current value, then adds that number to the converted value
			prefixNumbValue = 0; //resets the prefix's value
		}

	}

}
