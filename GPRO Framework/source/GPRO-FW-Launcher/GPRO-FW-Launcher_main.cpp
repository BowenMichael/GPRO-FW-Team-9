// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GPRO-FW.h"


int main()
{
	int guess = 50;
	string input = "y";
	cout << "I am going to guess your age Just tell me if I am higher or lower or correct." << endl;
	do {
		cout << endl << "I am think your age is: " << guess << "." << endl << "Is it higher lower or did I get it right?" << endl;
		cin >> input;
		guess = ageGuesser(input, guess);
		if (guess == -1) {
			cout << "Horray I got it! would you like to try another age I bet I could get it! Or to leave press 'l'. " << endl;
			cin >> input;
			guess = 50;

		}
	} while (input != "l");
	cout << "Ok Thanks for playing! Goodbye." << endl;
}



