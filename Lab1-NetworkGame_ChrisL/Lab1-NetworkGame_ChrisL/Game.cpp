#include "Game.h"
void displayBoard(Player* WhatPlayer);

void Game::startGame()
{
	//reset player two
	LocalPlayerOne->bHasAttacked = false;
	LocalPlayerOne->bIsActivePiece = false;
	LocalPlayerOne->bcompletedSetup = false;
	//reset player one
	LocalPlayerTwo->bHasAttacked = false;
	LocalPlayerTwo->bIsActivePiece = false;
	LocalPlayerTwo->bcompletedSetup = false;
	LocalPlayerTwo->iAmountOfTurns = 1;
}

int Game::displayTurn(Player* WhatPlayer)
{

	int i;
	if (WhatPlayer == LocalPlayerOne)
	{
		if (LocalPlayerOne->iAmountOfTurns == 0)
		{
			cout << "\n\n" << LocalPlayerOne->getNames() << endl;
			cout << "SMALL SHIPS: " << LocalPlayerOne->iPiece + 1 << endl;
			cout << "Please place 4 ships on the map" << endl;
			do
			{
				int col = enterColPosition();
				int row = enterRowPosition();
				displayBoard(LocalPlayerOne);
				i = 0;
				board[col][row][i] = HitCheck::SHIP;
				LocalPlayerOne->iPlacedPieces++;


			} while (LocalPlayerOne->iPlacedPieces < 4);
			system("cls");
			return i;
		}
		else
		{
			cout << "\n\nPlease choose one of the following actions" << endl;
			cout << "[0] Choose Attack Coordinates\n[1]End Turn" << endl;
			i = 1;
		}
	}
	if (WhatPlayer == LocalPlayerTwo)
	{
		if (LocalPlayerTwo->iAmountOfTurns == 1)
		{
			cout << "\n\n" << LocalPlayerTwo->getNames() << endl;
			cout << "SMALL SHIPS: " << LocalPlayerTwo->iPiece + 1 << endl;
			do {
				int col = enterColPosition();
				int row = enterRowPosition();
				displayBoard(LocalPlayerOne);
				i = 1;
				board[col][row][i] = HitCheck::SHIP;
				LocalPlayerTwo->iPlacedPieces++;
			} while (LocalPlayerTwo->iPlacedPieces < 4);
		}
		else
		{
			cout << "\n\nPlease choose one of the following actions" << endl;
			cout << "[0] Choose Attack Coordinates\n[1]End Turn" << endl;
			i = 0;
		}
	}



	return i;
}

int Game::processTurn(Player* WhatPlayer)
{
	int i = displayTurn(WhatPlayer);
	cin >> WhatPlayer->playerinput;
	if (WhatPlayer->playerinput == ATTACK)
	{
		if (WhatPlayer->bHasAttacked == false)
		{
			int col = enterColPosition();
			int row = enterRowPosition();

			//col - 1;
			WhatPlayer->bHasAttacked = true;
			//			board[col][row][i] = HitCheck::HIT;
						// checkl to see if piece is at that location
						// if so // mark that peice as hit once
						// update the board at that location to show hitcheck::HIT
						// else it's a miss but still update board
			if (board[row][col][i] == HitCheck::WATER)
			{
				board[col][row][i] = HitCheck::MISS;
			}
			if (board[row][col][i] == HitCheck::SHIP)
			{
				board[col][row][i] = HitCheck::HIT;
			}
			LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? displayBoard(LocalPlayerOne) : displayBoard(LocalPlayerTwo);
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

		WhatPlayer->iAmountOfTurns += 1;
		WhatPlayer->bHasAttacked = false;
		LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? displayBoard(LocalPlayerOne) : displayBoard(LocalPlayerTwo);
	}

	return 0;
}

int Game::enterRowPosition()
{
	int row = 0;
	do
	{
		cout << "Enter row (from 1-5): ";
		cin >> row;
		if (row < 1 || row > 6)
		{
			enterRowPosition();
		}
	} while (row < 1 || row >= 6);

	return row - 1;
}

int Game::enterColPosition()
{
	char col;
	int column = 0;
	cout << "Enter column (A,B,C,D,E): ";
	cin >> col;
	if (col != 'A' && col != 'B' && col != 'C' && col != 'D' && col != 'E')
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
	else {
		enterColPosition();
	}
	return column;
}


void Game::displayBoard(Player* WhatPlayer)
{
	system("cls");
	cout << "It is now " << WhatPlayer->getNames() << "'s turn \n" << endl;
	cout << "    A    B    C    D    E\n\n";
	int i;
	if (WhatPlayer->bcompletedSetup == false)
	{
		if (WhatPlayer == LocalPlayerOne)
		{
			i = 0;
		}
		if (WhatPlayer == LocalPlayerTwo)
		{
			i = 1;
		}
	}
	if (WhatPlayer->bcompletedSetup == true)
	{
		if (WhatPlayer == LocalPlayerOne)
		{
			i = 1;
		}
		if (WhatPlayer == LocalPlayerTwo)
		{
			i = 0;
		}
	}
	for (int row = 0; row < 5; row++)
	{
		cout << row + 1;
		for (int col = 0; col < 5; col++)
		{
			//
			cout << " ";

			cout << "  " << board[col][row][i] << " ";

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
