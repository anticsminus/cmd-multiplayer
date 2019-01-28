#include "Game.h"
void displayBoard(Player* WhatPlayer);

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
	cin >> WhatPlayer->playerinput;

	WhatPlayer->iAmountOfTurns += 1;
	if (WhatPlayer->playerinput == ATTACK)
	{
		if (WhatPlayer->bHasAttacked == false)
		{
			int col = enterColPosition();
			int row = enterRowPosition();
			col - 1;
			WhatPlayer->bHasAttacked = true;
			board[col][row] = HitCheck::HIT;
			// checkl to see if piece is at that location
			// if so // mark that peice as hit once
			// update the board at that location to show hitcheck::HIT
			// else it's a miss but still update board
			if (board[row][col] == 0)
			{
				board[row][col] = HitCheck::MISS;
			}
			if (board[row][col] == 1)
			{
				board[row][col] = HitCheck::HIT;
			}
			displayBoard(WhatPlayer);

		}
		else
		{
			cout << "You have already attacked, please choose one of the following options\n" << endl;
			cout << "[1]End Turn" << endl;
			cin >> WhatPlayer->playerinput;
		}
	}

	if (WhatPlayer->playerinput == ENDTURN)
	{
		system("cls");
		WhatPlayer->bHasAttacked == false;
		LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? displayBoard(LocalPlayerOne) : displayBoard(LocalPlayerTwo);
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
		row - 1;
		if(row < 0 || row > 5)
		{ 
			enterRowPosition();
		}
	} while (row < 0 || row >= 5);

	return row;
}

int Game::enterColPosition()
{
	char col;
	int column = 0;
		cout << "Enter column (A,B,C,D,E): ";
		cin >> col;
		if (col != 'A' && col != 'B' && col != 'C' && col != 'D' && col != 'E' )
		{
			enterColPosition();
		}
		if (col = 'A')
		{
			column = 4;
		}
		if (col = 'B')
		{
			column = 3;
		}
		if (col = 'C')
		{
			column = 2;
		}
		if (col = 'D')
		{
			column = 1;
		}
		if (col = 'E')
		{
			column = 0;
		}
	return column;
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
			//
			cout << " ";

			cout << "  " << board[row][col] << " ";
			
		}
		cout << endl;
	}

	cout << "\n\n" << LocalPlayerOne->getNames() << "\t	" << LocalPlayerTwo->getNames() << endl;
	cout << "SMALL SHIPS: " << LocalPlayerOne->iPiece << "\tSMALL SHIPS: " << LocalPlayerTwo->iPiece << endl;
	LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? processTurn(LocalPlayerOne) : processTurn(LocalPlayerTwo);
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

void displayBoard(Player * WhatPlayer)
{
}
