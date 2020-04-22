
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_BATTLESHIP_PLAYERS				2
#define GS_BATTLESHIP_BOARD_WIDTH			10
#define GS_BATTLESHIP_BOARD_HEIGHT			10


enum gs_battleship_space_state
{
	// invalid space state
	gs_battleship_space_invalid = -1,

	// states visible to both players
	gs_battleship_space_open,			// space is open and unguessed
	gs_battleship_space_miss,			// space was guessed and missed
	gs_battleship_space_hit,			// space was guessed and hit

	// states hidden from opponent player
	gs_battleship_space_patrol2,		// 2-unit patrol boat
	gs_battleship_space_submarine3,		// 3-unit submarine
	gs_battleship_space_destroyer3,		// 3-unit destroyer
	gs_battleship_space_battleship4,	// 4-unit battleship
	gs_battleship_space_carrier5,		// 5-unit carrier
};
#ifndef __cplusplus
typedef		enum gs_battleship_space_state	gs_battleship_space_state;
#endif	// !__cplusplus

// battleship game state
typedef		unsigned char					gs_battleship_index;
typedef		gs_battleship_space_state		gs_battleship[GS_BATTLESHIP_PLAYERS][GS_BATTLESHIP_BOARD_WIDTH][GS_BATTLESHIP_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,z,w,h,d)		(x < w && y < h && z < d)
#define GS_BATTLESHIP_VALID(p,x,y)				GS_VALIDATE_COORDINATE(x,y,p,GS_BATTLESHIP_BOARD_WIDTH,GS_BATTLESHIP_BOARD_HEIGHT,GS_BATTLESHIP_PLAYERS)


inline gs_battleship_space_state gs_checkers_getSpaceState(gs_battleship const game, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos]);
	return gs_battleship_space_invalid;
}

inline gs_battleship_space_state gs_checkers_setSpaceState(gs_battleship game, gs_battleship_space_state const state, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos] = state);
	return gs_battleship_space_invalid;
}

inline gs_battleship_index gs_battleship_reset(gs_battleship game)
{
	gs_battleship_index player, xpos, ypos, total;
	for (player = 0; player < GS_BATTLESHIP_PLAYERS; ++player)
		for (xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; ++xpos)
			for (ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ++ypos)
				game[player][xpos][ypos] = gs_battleship_space_open;
	total = (player * xpos * ypos);
	cout << (int)player << endl;
	//battleshipPlayerPoints[0] = 0;
	//battleshipPlayerPoints[1] = 0;

	return total;
}



//2gs_battleship_space_state testForHit(gs_battleship_space_state cell);
void displayGameBoard(gs_battleship game, gs_battleship_index player);
gs_battleship_index input(gs_battleship_index plr, gs_battleship game);
int battleshipAskForColoum();
int battleshipAskForRow();
bool playItem(gs_battleship_index plr, gs_battleship game);
bool testForHit(gs_battleship game, int row, int col, gs_battleship_index plr);
void winOutput(gs_battleship_index player);
int launchBattleship();
void setUpShips(gs_battleship game, gs_battleship_index player);
bool askIfHorizontal();
bool placeShip(int col, int row, bool isHorizontal, 
	gs_battleship_space_state ship, int sizeOfShip, 
	gs_battleship game, gs_battleship_index player);
void displayOpposingBoard(gs_battleship game, gs_battleship_index player);


const string BATTLESHIP_PAGE_WIDTH = "----------------------------------------";
const string BATTLESHIP_HIT_DISPLAY = " X ";
const string BATTLESHIP_MISS_DISPLAY = " O ";
const string BATTLESHIP_OPEN_DISPLAY = "[ ]";
const string BATTLESHIP_PATROL_DISPLAY = " P ";
const string BATTLESHIP_SUBMARINE_DISPLAY = " S ";
const string BATTLESHIP_DESTROYER_DISPLAY = " D ";
const string BATTLESHIP_BATTLESHIP_DISPLAY = " B ";
const string BATTLESHIP_CARRIER_DISPLAY = " C ";
const int MAX_POINTS = 17;


