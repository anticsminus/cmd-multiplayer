#pragma once

#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

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
		PlayerOne = LocalPlayerOne;
		PlayerTwo = LocalPlayerTwo;
	}
	void startGame();
	void checkForWinner();
	int processTurn();
	void displayBoard();


};

