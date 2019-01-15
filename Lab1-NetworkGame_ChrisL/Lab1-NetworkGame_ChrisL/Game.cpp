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

int Game::processTurn()
{
	cout << "\n\nPlease choose one of the following actions" << endl;
	cin >> playerinput;
	if (playerinput == ATTACK)
	{

	}
	if (playerinput == ENDTURN)
	{

	}
	return 0;

}

int enterRowPosition()
{
	int row = 0;
	do
	{
		cout << "Enter row: ";
		cin >> row;
	} while (row < 0 || row >= 5);

	return row;
}

int enterColPosition()
{
	char col;
		cout << "Enter column (A,B,C,D,E): ";
		char A = 1;

		cin >> col;
	return col;
}


void Game::displayBoard()
{
	int board[5][5];
	cout << "It is now " << LocalPlayerOne->getNames() << "'s turn \n" << endl;
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
	processTurn();
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


