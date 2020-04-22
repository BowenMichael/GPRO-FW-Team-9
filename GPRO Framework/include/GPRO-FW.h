#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

int ageGuesser(string input, int guess);
int menu();
void printMenu();
void printListItem(string outputText);

const int PAGE_WIDTH = 10;