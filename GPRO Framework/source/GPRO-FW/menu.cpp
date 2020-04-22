#include "GPRO-FW.h"


int menu() {
	int input;
	printMenu();
	cin >> input;
	return input;
}

void printMenu() {
	printListItem("Menu");
	printListItem("[1] Play Tic-Tac-Toe");
	printListItem("[2] Play Checkers");
}

void printListItem(string outputText)
{
	cout << setw(PAGE_WIDTH) << right << " " << setw(PAGE_WIDTH) << left << outputText << endl;
}
