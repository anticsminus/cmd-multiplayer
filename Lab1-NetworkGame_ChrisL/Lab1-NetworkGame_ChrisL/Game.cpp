#include "Game.h"

enum column
{

};

void Game::startGame()
{
	//reset player two
	LocalPlayerOne->bHasAttacked = false;
	LocalPlayerOne->bHasMoved = false;
	LocalPlayerOne->bIsActivePiece = false;
	//reset player one
	LocalPlayerTwo->bHasAttacked = false;
	LocalPlayerTwo->bHasMoved = false;
	LocalPlayerTwo->bIsActivePiece = false;
}

int Game::processTurn(Player* WhatPlayer)
{
	cout << "\n\nPlease choose one of the following actions" << endl;
	cout << "[0] Choose Attack Coordinates\n[1]End Turn" << endl;

	if (WhatPlayer->playerinput == ATTACK)
	{
		int col = enterColPosition();
		int row = enterRowPosition();
	}
	if (WhatPlayer->playerinput == ENDTURN)
	{

	}
	return 0;

}

int Game::enterRowPosition()
{
	int row = 0;
	do
	{
		cout << "Enter row (from 0-5): ";
		cin >> row;
	} while (row < 0 || row >= 5);

	return row;
}

int Game::enterColPosition()
{
	char col;
		cout << "Enter column (A,B,C,D,E): ";
		char A = 1;

		cin >> col;
	return col;
}


void Game::displayBoard(Player* WhatPlayer)
{
	cout << "It is now " << WhatPlayer->getNames() << "'s turn \n" << endl;
	cout << "    A    B    C    D    E\n\n";

	for (int row = 0; row < 5; row++)
	{
		cout << row + 1;
		for (int col = 0; col < 5; col++)
		{
			cout << " ";

			// print data here or -
			if (/*check something*/ 0)
			{
				// cout x or s or whatever
			}
			else
			{
				cout << "  ~ ";
			}
		}
		cout << endl;
	}

	cout << "\n\n" << LocalPlayerOne->getNames() << "\t	" << LocalPlayerTwo->getNames() << endl;
	cout << "SMALL SHIPS: " << LocalPlayerOne->iPiece << "\tSMALL SHIPS: " << LocalPlayerTwo->iPiece << endl;
	if(LocalPlayerOne->playerinput < LocalPlayerTwo->playerinput ? processTurn(LocalPlayerOne) : processTurn(LocalPlayerTwo));
}

void Game::checkForWinner()
{
	if (LocalPlayerOne->iPiece == 0)
	{
		//win condition for player one
	}
	else if (LocalPlayerTwo->iPiece == 0)
	{
		//win condition for player one
	}

}

Game::Game()
{
}


Game::~Game()
{
}


