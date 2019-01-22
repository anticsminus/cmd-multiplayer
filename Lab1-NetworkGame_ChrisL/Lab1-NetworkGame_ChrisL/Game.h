#pragma once

#include <string>
#include <iostream>
#include "Player.h"

using namespace std;


enum battle
{
		ATTACK,
		ENDTURN
};

enum SlotNotation
{
	water = 0,
	occupied = 1,
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
		LocalPlayerOne = PlayerOne;
		LocalPlayerTwo = PlayerTwo;
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				board[col][row] = HitCheck::WATER;
			}
		}
	}

	char board[5][5];

	void startGame();
	void checkForWinner();
	int processTurn(Player* WhatPlayer);
	void displayBoard(Player* WhatPlayer);

	int enterRowPosition();
	int enterColPosition();
};

