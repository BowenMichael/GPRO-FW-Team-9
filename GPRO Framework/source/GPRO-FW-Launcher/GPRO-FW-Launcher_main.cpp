// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GPRO-FW.h"
#include "GPRO-FW-TicTacToe.h"

using namespace std;

int main()
{
	cout << "Welcome to the game selection menu" << endl;
	bool active = true;
	int num;
	do {
		switch (menu())
		{
		case 1:
			num = launchTicTacToe();
		default:
			break;
		}
	} while (active == true);



		
}



