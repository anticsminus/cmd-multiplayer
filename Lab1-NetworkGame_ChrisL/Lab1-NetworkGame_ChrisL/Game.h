#pragma once

#include <string>
#include <iostream>
#include "Player.h"

using namespace std;


enum battle
{
		ATTACK,
		ENDTURN,
		PLACESHIPS
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
				for (int i = 0; i < 2; i++)
				{
					board[col][row][i] = HitCheck::WATER;
				}
			}
		}
	}
	char board[5][5][1];


	void startGame();
	int displayTurn(Player * WhatPLayer);
	void checkForWinner();
	int processTurn(Player* WhatPlayer);
	void displayBoard(Player* WhatPlayer);
	int enterRowPosition();
	int enterColPosition();
};

