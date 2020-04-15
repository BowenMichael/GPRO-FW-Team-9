// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX_AGE = 150;
const int MIN_AGE = 0;
int ageGuesser(string input, int guess);

int main()
{
	int guess = 50;
	string input = "y";
	cout << "I am going to guess your age Just tell me if I am higher or lower or correct." << endl;
	do {
		cout << "I am think your age is: " << guess << ". Is it higher lower or did I get it right?";
		cin >> input;
		guess = ageGuesser(input, guess);
	} while (input != "y");
}


int ageGusser(string input, int guess) {
	switch (input.at(0)) {
	case 'h':
		cout << "Ok let me try again";
		return guess + ((MAX_AGE - guess) / 2);
		break;
	case 'l':
		cout << "Ok let me try again";
		return guess - ((guess - MIN_AGE) / 2);
		break;
	case 'c':
		cout << "Yes I am so smart!" << endl;
		return -1;
		break;
	}
}
