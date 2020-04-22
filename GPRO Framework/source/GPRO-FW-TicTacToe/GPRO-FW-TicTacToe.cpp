#pragma once
#include "GPRO-FW-TicTacToe.h"


//-----------------------------------------------------------------------------
// DEFINITIONS



void displayGameBoard(gs_tictactoe game) {
	cout << endl << "-----------" << endl;
	for (int xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos){
		for (int ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos){
			string display = "ERROR";
			if (game[xpos][ypos] == gs_tictactoe_space_open) {
				display = OPEN_DISPLAY;
			}
			else if (game[xpos][ypos] == gs_tictactoe_space_x) {
				display = X_DISPLAY;
			}
			else if (game[xpos][ypos] == gs_tictactoe_space_o) {
				display = O_DISPLAY;
			}
			 cout << display << "|";
		}
		cout << endl << "-----------" << endl;
	}
}

gs_tictactoe_space_state input(gs_tictactoe_space_state plr, gs_tictactoe game) {
	if (plr == gs_tictactoe_space_x) {
		cout << "It is X's turn." << endl;
		if (playItem(plr, game))
			plr = gs_tictactoe_space_o;
		else
			cout << endl << "ERROR: That Cell is full for doesn't egsit please try another." << endl;
	}
	else if (plr == gs_tictactoe_space_o) {
		cout << "it is O's Turn." << endl;
		if (playItem(plr, game))
			plr = gs_tictactoe_space_x;
		else
			cout << "That Cell is full for doesn't egsit please try another." << endl;
	}
	return plr;
}

bool checkForWin(gs_tictactoe game, gs_tictactoe_space_state player) {
	if (checkHorizontal(game, player) || checkVectical(game, player) || checkDiagonal(game, player)) {
		return true;
	}
	return false;
}

int askForColoum()
{
	int col;
	cout << "What coloum would you like to play?" << endl;
	cin >> col;
	return col;
}

int askForRow()
{
	int row;
	cout << "What row would you like to play?" << endl;
	cin >> row;
	return row;
}

bool playItem(gs_tictactoe_space_state turnState, gs_tictactoe game)
{
	int col = askForColoum();
	int row = askForRow();
	if (game[row][col] == gs_tictactoe_space_open && row >= 0 && row < GS_TICTACTOE_BOARD_HEIGHT && col >= 0 && col < GS_TICTACTOE_BOARD_WIDTH) {
		game[row][col] = turnState;
		return true;
	}
	return false;

}

bool checkHorizontal(gs_tictactoe game, gs_tictactoe_space_state player)
{
	for (int xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos) {
		int winPoints = 0;
		for (int ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos) {
			if (game[xpos][ypos] == player) {
				winPoints++;
			}
		}
		if (winPoints == POINTS_TO_WIN) {
			winOutput(player);
			return true;
		}
	}
	return false;
}

bool checkVectical(gs_tictactoe game, gs_tictactoe_space_state player)
{
	for (int ypos = 0; ypos < GS_TICTACTOE_BOARD_WIDTH; ++ypos) {
		int winPoints = 0;
		for (int xpos = 0; xpos < GS_TICTACTOE_BOARD_HEIGHT; ++xpos) {
			if (game[xpos][ypos] == player) {
				winPoints++;
			}
		}
		if (winPoints == POINTS_TO_WIN) {
			winOutput(player);
			return true;
		}
	}
	return false;
	return false;
}

bool checkDiagonal(gs_tictactoe game, gs_tictactoe_space_state player)
{
	if (game[0][0] == player && game[1][1] == player && game[2][2] == player) {
		winOutput(player);
		return true;
	}
	else if (game[0][2] == player && game[1][1] == player && game[2][0] == player) {
		winOutput(player);
		return true;
	}
	return false;
}

void winOutput(gs_tictactoe_space_state player)
{
	cout << "Winner Winner!!!" << endl;
}

int launchTicTacToe()
{
	gs_tictactoe game;

	gs_tictactoe_reset(game);

	cout << "Tic Tac Toe has been launched" << endl;
	bool active = true;
	gs_tictactoe_space_state player = gs_tictactoe_space_x;
	
	while (active) {
		if (checkForWin(game, gs_tictactoe_space_x) || checkForWin(game, gs_tictactoe_space_o)) {
			active = false;
			break;
		}
		displayGameBoard(game);
		player = input(player, game);

	}
	displayGameBoard(game);

	return 0;
}



//-----------------------------------------------------------------------------
