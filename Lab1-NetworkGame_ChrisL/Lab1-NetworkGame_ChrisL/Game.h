#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Piece.h"

using namespace std;

//used for player input comparison
enum battle
{
	 	NUL,
		ATTACK,
		ENDTURN,
		PLACESHIPS
};

namespace HitCheck {
	const char WATER = '~';
	const char HIT = 'X';
	const char MISS = 'O';
	const char SHIP = 'S';
}

class Game
{
private:
	Player* LocalPlayerOne;
	Player* LocalPlayerTwo;



public:
	Game();
	~Game();

	Game(Player* PlayerOne, Player* PlayerTwo)
	{
		//attach player pointer to private pointers
		LocalPlayerOne = PlayerOne;
		LocalPlayerTwo = PlayerTwo;
		//print both boards 
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
					board[col][row] = HitCheck::WATER;
					board2[col][row] = HitCheck::WATER;
			}
		}
	}
	char board[5][5];
	char board2[5][5];

	void startGame(bool firstRun);
	void checkForWinner();
	void displayBoard(Player* &WhatPlayer);
	void notValid(Player* &WhatPlayer);

	bool setupBoard(Player * &WhatPayer);
	bool setupAIBoard(Player * &WhatPayer);
	bool GetGrid(int col, int row, Player* WhatPlayer);
	bool SetGrid(int col, int row, Player* WhatPlayer);
	int processTurn(Player* &WhatPlayer);

	int enterRowPosition();
	int enterColPosition();
};

