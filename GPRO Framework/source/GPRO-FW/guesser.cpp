#include "GPRO-FW.h"

int MAX_AGE = 150;
int MIN_AGE = 0;

int ageGuesser(string input, int guess) {
	cout << endl;
	switch (input.at(0)) {
	case 'h':
		cout << "Ok let me try again";
		MIN_AGE = guess;
		return guess + ((MAX_AGE - guess) / 2);
		break;
	case 'l':
		cout << "Ok let me try again";
		MAX_AGE = guess;
		return guess - ((guess - MIN_AGE) / 2);
		break;
	case 'c':
		cout << "Yes I am so smart!" << endl;
		MAX_AGE = 150;
		MIN_AGE = 0;
		return -1;
		break;
	default:
		cout << "Make sure the first letter is lowercase and correct." << endl;
		return guess;
	}

}