#include "GPRO-FW-Battleship.h"
#include <stdio.h>
int battleshipPlayerPoints[GS_BATTLESHIP_PLAYERS];
//-----------------------------------------------------------------------------
// DEFINITIONS

void displayGameBoard(gs_battleship game, gs_battleship_index player) {
	cout << "This is player " << (int)player << "'s board" << endl;
	cout << endl << BATTLESHIP_PAGE_WIDTH << endl;
	for (int xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; ++xpos) {
		for (int ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ++ypos) {
			string display = "ERROR";
			if (game[player][xpos][ypos] == gs_battleship_space_open) {
				display = BATTLESHIP_OPEN_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_hit) {
				display = BATTLESHIP_HIT_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_miss) {
				display = BATTLESHIP_MISS_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_patrol2) {
				display = BATTLESHIP_PATROL_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_submarine3) {
				display = BATTLESHIP_SUBMARINE_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_destroyer3) {
				display = BATTLESHIP_DESTROYER_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_battleship4) {
				display = BATTLESHIP_BATTLESHIP_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_carrier5) {
				display = BATTLESHIP_CARRIER_DISPLAY;
			}
			if (game[player][xpos][ypos] == gs_battleship_space_invalid) {
				display = "invalid";
			}
			cout << display << "|";
		}
		cout << endl <<  BATTLESHIP_PAGE_WIDTH << endl;
	}
}

void displayOpposingBoard(gs_battleship game, gs_battleship_index player) {
	cout << "This is Your opponents Board with what you know" << endl;
	cout << endl << BATTLESHIP_PAGE_WIDTH << endl;
	for (int xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; ++xpos) {
		for (int ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ++ypos) {
			string display = "ERROR";
			if (game[player][xpos][ypos] == gs_battleship_space_hit) {
				display = BATTLESHIP_HIT_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_miss) {
				display = BATTLESHIP_MISS_DISPLAY;
			}
			else if (game[player][xpos][ypos] == gs_battleship_space_invalid) {
				display = "invalid";
			}
			else {
				display = BATTLESHIP_OPEN_DISPLAY;
			}
			cout << display << "|";
		}
		cout << endl << BATTLESHIP_PAGE_WIDTH << endl;
	}
}

gs_battleship_index input(gs_battleship_index plr, gs_battleship game) {
	
	if (plr == 0) {
		cout << "It is player 1's turn." << endl;
		if (playItem(1, game))
			plr = 1;
		else
			cout << endl << "ERROR: That Cell is full for doesn't exist please try another." << endl;
	}
	else if (plr == 1) {
		cout << "it is player 2's Turn." << endl;
		if (playItem(0, game))
			plr = 0;
		else
			cout << "That Cell is full for doesn't exisit please try another." << endl;
	}
	return plr;
}

bool playItem(gs_battleship_index plr, gs_battleship game)
{
	int col = battleshipAskForColoum();
	int row = battleshipAskForRow();
	if (row >= 0 && row < GS_BATTLESHIP_BOARD_HEIGHT && col >= 0 && col < GS_BATTLESHIP_BOARD_WIDTH) {
		return testForHit(game, row, col, plr);
	}
	return false;

}

bool testForHit(gs_battleship game, int row, int col, gs_battleship_index plr) {
	if (game[plr][row][col] != gs_battleship_space_hit && game[plr][row][col] != gs_battleship_space_miss) {
		//hit patrol
		if (game[plr][row][col] == gs_battleship_space_patrol2) {
			cout << "HIT their patrol!" << endl;
			system("pause");
			system("CLS");
			//Points increase for player by 1;
			battleshipPlayerPoints[plr]++;
			game[plr][row][col] = gs_battleship_space_hit;
			return true;
		}
		//hit sub
		if (game[plr][row][col] == gs_battleship_space_submarine3) {
			cout << "HIT their submarine!" << endl;
			system("pause");
			system("CLS");
			//Points increase for player by 1;
			battleshipPlayerPoints[plr]++;
			game[plr][row][col] = gs_battleship_space_hit;
			return true;
		}
		//hit destroyer
		if (game[plr][row][col] == gs_battleship_space_destroyer3) {
			cout << "HIT their destroyer!" << endl;
			system("pause");
			system("CLS");
			//Points increase for player by 1;
			battleshipPlayerPoints[plr]++;
			game[plr][row][col] = gs_battleship_space_hit;
			return true;
		}
		//hit battleship
		if (game[plr][row][col] == gs_battleship_space_battleship4) {
			cout << "HIT their battleship!" << endl;
			system("pause");
			system("CLS");
			//Points increase for player by 1;
			battleshipPlayerPoints[plr]++;
			game[plr][row][col] = gs_battleship_space_hit;
			return true;
		}
		//hit carrier
		if (game[plr][row][col] == gs_battleship_space_carrier5) {
			cout << "HIT their carrier!" << endl;
			system("pause");
			system("CLS");
			//Points increase for player by 1;
			battleshipPlayerPoints[plr]++;
			game[plr][row][col] = gs_battleship_space_hit;
			return true;
		}
		game[plr][row][col] = gs_battleship_space_miss;
		cout << "Miss" << endl;
		system("pause");
		system("CLS");
		return true;
	}
	cout << "you have already played there!" << endl;
	system("pause");
	system("CLS");
	return false;
}

bool checkForWin(gs_battleship game, gs_battleship_index player) {
	if (battleshipPlayerPoints[player] >= MAX_POINTS) {
		winOutput(player);
		return true;
	}
	return false;
}

int battleshipAskForColoum()
{
	int col;
	cout << "What coloum would you like to play?" << endl;
	cin >> col;
	return col;
}

int battleshipAskForRow()
{
	int row;
	cout << "What row would you like to play?" << endl;
	cin >> row;
	return row;
}

void winOutput(gs_battleship_index player)
{
	cout << "Winner Winner!!! Player "<< (int)player << " WINS!" << endl;
}

int launchBattleship()
{
	gs_battleship game;

	gs_battleship_reset(game);
	system("CLS");
	cout << endl  << "Battleship has been launched" << endl << endl;
	setUpShips(game, 0);
	setUpShips(game, 1);
	bool active = true;
	gs_battleship_index player = 0;

	while (active) {
		if (checkForWin(game, 0) || checkForWin(game, 1)) {
			active = false;
			break;
		}
		if (player == 0) {
			displayOpposingBoard(game, 1);
		}
		else if (player == 1) {
			displayOpposingBoard(game, 0);
		}
		player = input(player, game);

	}
	displayGameBoard(game, 0);
	displayGameBoard(game, 1);
	cout << "Congradulations You Win!" << endl;
	

	return 0;
}

void setUpShips(gs_battleship game, gs_battleship_index player)
{
	cout << "It is player " << (int)player << "'s turn to set up their ships." << endl << endl;
	bool placed;
	do {
		displayGameBoard(game, player);
		cout << "Lets start with the patrol ship." << endl;
		placed = placeShip(battleshipAskForColoum(), battleshipAskForRow(), 
			askIfHorizontal(), gs_battleship_space_patrol2, 2, game, player);
	} while (!placed);
	system("CLS");
	do {
		displayGameBoard(game, player);
		cout << "Next the Submarine ship." << endl;
		placed = placeShip(battleshipAskForColoum(), battleshipAskForRow(),
			askIfHorizontal(), gs_battleship_space_submarine3, 3, game, player);
	} while (!placed);
	system("CLS");
	do {
		displayGameBoard(game, player);
		cout << "Next the destroyer ship." << endl;
		placed = placeShip(battleshipAskForColoum(), battleshipAskForRow(),
			askIfHorizontal(), gs_battleship_space_destroyer3, 3, game, player);

	} while (!placed);
	system("CLS");
	do {
		displayGameBoard(game, player);
		cout << "Next the battleship ship." << endl;
		placed = placeShip(battleshipAskForColoum(), battleshipAskForRow(),
			askIfHorizontal(), gs_battleship_space_battleship4, 4, game, player);
	} while (!placed);
	system("CLS");
	do {
		displayGameBoard(game, player);
		cout << "Finally the carrier ship?" << endl;
		placed = placeShip(battleshipAskForColoum(), battleshipAskForRow(),
			askIfHorizontal(), gs_battleship_space_carrier5, 5, game, player);
	} while (!placed);
	system("CLS");


}

bool askIfHorizontal()
{
	string input;
	cout << "Would you like your ship horizontal?" << endl;
	cin >> input;
	if (input.at(0) == 'y') {
		return true;
	}
	return false;
}

bool placeShip(int col, int row, bool isHorizontal, gs_battleship_space_state ship, int sizeOfShip, gs_battleship game, gs_battleship_index player)
{
	cout << endl;
	if (gs_checkers_getSpaceState(game, player, row, (col + (sizeOfShip - 1))) == gs_battleship_space_invalid && isHorizontal) {
		cout << "The ship will not fit" << endl;
		return false;
	}
	else if (gs_checkers_getSpaceState(game, player, (row + (sizeOfShip - 1)), col) == gs_battleship_space_invalid && !isHorizontal) {
		cout << "The ship will not fit" << endl;
		return false;
	}
	for (int i = 0; i < sizeOfShip; i++) {
		if (isHorizontal) {
			if (gs_checkers_getSpaceState(game, player, row, col + i) == gs_battleship_space_patrol2 ||
				gs_checkers_getSpaceState(game, player, row, col + i) == gs_battleship_space_submarine3 ||
				gs_checkers_getSpaceState(game, player, row, col + i) == gs_battleship_space_destroyer3 ||
				gs_checkers_getSpaceState(game, player, row, col + i) == gs_battleship_space_battleship4 ||
				gs_checkers_getSpaceState(game, player, row, col + i) == gs_battleship_space_carrier5) {
				cout << "There is a ship in the way" << endl;
				return false;
			}
		}
		else {
			if (gs_checkers_getSpaceState(game, player, row + i, col) == gs_battleship_space_patrol2 ||
				gs_checkers_getSpaceState(game, player, row + i, col) == gs_battleship_space_submarine3 ||
				gs_checkers_getSpaceState(game, player, row + i, col) == gs_battleship_space_destroyer3 ||
				gs_checkers_getSpaceState(game, player, row + i, col) == gs_battleship_space_battleship4 ||
				gs_checkers_getSpaceState(game, player, row + i, col) == gs_battleship_space_carrier5) {
				cout << "There is a ship in the way" << endl;
				return false;
			}
		}
	}

		
	
	for (int i = 0; i < sizeOfShip; i++) {
		if (isHorizontal) {
			gs_checkers_setSpaceState(game, ship, player, row, col + i);
		}
		else {
			gs_checkers_setSpaceState(game, ship, player, row + i, col);
		}
	}
	return true;
}


//-----------------------------------------------------------------------------
