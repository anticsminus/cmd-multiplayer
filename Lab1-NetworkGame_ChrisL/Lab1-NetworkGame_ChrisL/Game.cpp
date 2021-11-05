#include "Game.h"  


int processTurn(Player* &WhatPlayer);
void displayBoard(Player* WhatPlayer);

int colTracker[2][4];
int rowTracker[2][4];

Piece* p1pieces = new Piece[4];
Piece* p2pieces = new Piece[4];


void Game::startGame(bool firstRun)
{
	delete[] p1pieces;
	delete[] p2pieces;

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			board[col][row] = HitCheck::WATER;
			board2[col][row] = HitCheck::WATER;
		}
	}
	//for (int x = 0; x < 5; x++)
	//{
	//	for (int y = 0; y < 5; y++)
	//	{
	//		SetGrid(x,y,LocalPlayerOne);
	//		SetGrid(x,y,LocalPlayerTwo);
	//	}

	//}
	//reset player two
	p1pieces[colTracker[0][0]].x = 0;
	p1pieces[rowTracker[0][0]].y = 0;
	p2pieces[colTracker[1][0]].x = 0;
	p2pieces[rowTracker[1][0]].y = 0;
	LocalPlayerOne->bHasAttacked = false;
	LocalPlayerOne->bIsActivePiece = false;
	LocalPlayerOne->bcompletedSetup = false;
	LocalPlayerTwo->iGamesPlayed++;
	//reset player one
	LocalPlayerTwo->bHasAttacked = false;
	LocalPlayerTwo->bIsActivePiece = false;
	LocalPlayerTwo->bcompletedSetup = false;
	LocalPlayerTwo->iGamesPlayed++;
	LocalPlayerTwo->iAmountOfTurns = 1;
	Piece* p1pieces = new Piece[4];
	Piece* p2pieces = new Piece[4];
	if (firstRun == false)
	{
		setupBoard(LocalPlayerOne);
		setupBoard(LocalPlayerTwo);
		displayBoard(LocalPlayerOne);
	}
}

int Game::enterRowPosition()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.clear();
	int row = 0;
	//do
	//{
		cout << "Enter row (from 1-5): ";
		cin >> row;
		if (cin)
		{
			if (row > 0 && row < 6)
			{
				return row - 1;
			}
		}
		else 
		{
			enterRowPosition();
		}
	//} while (row < 1 || row >= 6);


}

//function for getting col coord from player
int Game::enterColPosition()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.clear();
	char col;
	int column = 0;
	cout << "Enter column (A,B,C,D,E): ";
	cin >> col;
	if (cin)
	{
		switch (toupper(col))
		{
		default:
			enterColPosition();
			break;
		case'A':
			column = 0;
			break;
		case'B':
			column = 1;
			break;
		case'C':
			column = 2;
			break;
		case'D':
			column = 3;
			break;
		case'E':
			column = 4;
			break;
		}
	}
	else
	{
		enterColPosition();
	}
	return column;
}

//after each turn we check to see if win conditions have been met, if they have then let the player decide 

void Game::checkForWinner()
{
	int iInput;

	if (LocalPlayerOne->iPiece == 0)
	{
		cout << endl;
		LocalPlayerTwo->iWins++;
		cout << LocalPlayerTwo->getNames() << " has won! \n\nType [0] to end game or [1] to restart ";
		cin >> iInput;

		if (iInput == 0)
		{
			delete LocalPlayerOne;
			delete LocalPlayerTwo;
			delete[] p1pieces;
			delete[] p2pieces;

			system("exit");
		}

		if (iInput == 1)
		{
			startGame(false);
		}

	}

	else if (LocalPlayerTwo->iPiece == 0)
	{
		cout << endl;
		LocalPlayerOne->iWins++;
		cout << LocalPlayerOne->getNames() << " has won! \n\nType: \n[0] End game \n[1] Restart ";
		cin >> iInput;

		if (iInput == 0)
		{
			delete LocalPlayerOne;
			delete LocalPlayerTwo;
			delete[] p1pieces;
			delete[] p2pieces;
			system("exit");
		}

		if (iInput == 1)
		{
			startGame(false);
		}

		else
		{
			cout << "Not a valid command!" << endl;
		}

	}
}


//check if grid corresponds with piece
bool Game::GetGrid(int col, int row, Player* WhatPlayer)
{
	if (WhatPlayer == LocalPlayerOne)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{

				if (col == p2pieces[x].x)
				{
					if (row == p2pieces[y].y)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
	if (WhatPlayer == LocalPlayerTwo)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{

				if (col == p1pieces[x].x)
				{
					if (row == p1pieces[y].y)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
	else
	{
		return true;
	}
}

bool Game::SetGrid(int col, int row, Player* WhatPlayer)
{
	if (WhatPlayer == LocalPlayerOne)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{

				if (p1pieces[x].x == col)
				{
					if (p1pieces[y].y == row)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
	if (WhatPlayer == LocalPlayerTwo)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{

				if (p2pieces[x].x== col)
				{
					if (p2pieces[y].y == row)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
}



bool Game::setupBoard(Player* &WhatPlayer)
{
	bool isOccupiedByYourOwnShip = false; 
	int col, row = 0;
	if (WhatPlayer == LocalPlayerOne)
	{
		if (WhatPlayer->iAmountOfTurns == 0)
		{
			for (LocalPlayerOne->iPlacedPieces; LocalPlayerOne->iPlacedPieces < LocalPlayerOne->iPiece; LocalPlayerOne->iPlacedPieces++)
			{
				int i = 0;
				cout << "\n" << LocalPlayerOne->getNames() << " " << endl;
				cout << "Welcome to the introduction!\nFirst we have to identify where the ships are in the water.\n\nSymbols:\n-X's represent hit's on the enemies board\n-O's represent misses\n-~ represents unknown waters\n\nPlease start by placing the remaining amount of ships on the board: " << LocalPlayerOne->iPiece - LocalPlayerOne->iPlacedPieces << endl;
				col = enterColPosition(); row = enterRowPosition();
				isOccupiedByYourOwnShip = SetGrid(col, row, LocalPlayerOne);
				if (isOccupiedByYourOwnShip == false)
				{
					colTracker[0][i] = col; rowTracker[0][i] = row;
					p1pieces[LocalPlayerOne->iPlacedPieces].x = col;
					p1pieces[LocalPlayerOne->iPlacedPieces].y = row;
					i++; 
					system("cls");
				}
				else
				{
					system("cls");
					cout << "===============================================================\nERROR: YOU HAVE ALREADY PLACED A SHIP THERE TRY AGAIN!\n===============================================================\n\n";
					system("PAUSE");
					system("cls");
					setupBoard(WhatPlayer);
				}
			}
			LocalPlayerOne->iAmountOfTurns++;

		}
	}
	if (WhatPlayer == LocalPlayerTwo)
	{
		if (WhatPlayer->iAmountOfTurns == 1)
		{

			for (LocalPlayerTwo->iPlacedPieces; LocalPlayerTwo->iPlacedPieces < LocalPlayerTwo->iPiece; LocalPlayerTwo->iPlacedPieces++)
			{
				int i = 0;
				cout << "\n" << LocalPlayerTwo->getNames() << " " << endl;
				cout << "Welcome to the introduction!\nFirst we have to identify where the ships are in the water.\n\nSymbols:\n-X's represent hit's on the enemies board\n-O's represent misses\n-~ represents unknown waters\n\nPlease start by placing the remaining amount of ships on the board: " << LocalPlayerTwo->iPiece - LocalPlayerTwo->iPlacedPieces << endl;
				col = enterColPosition(); row = enterRowPosition();
				isOccupiedByYourOwnShip = SetGrid(col, row, LocalPlayerTwo);
				if (isOccupiedByYourOwnShip == false)
				{
					colTracker[1][i] = col; rowTracker[1][i] = row;
					p2pieces[LocalPlayerTwo->iPlacedPieces].x = col;
					p2pieces[LocalPlayerTwo->iPlacedPieces].y = row;
					i++; 
					system("cls");
				}
				else 
				{
					system("cls");

					cout << "===============================================================\nERROR: YOU HAVE ALREADY PLACED A SHIP THERE TRY AGAIN!\n===============================================================\n\n";
					system("PAUSE");
					system("cls");
					setupBoard(WhatPlayer);
				}
			}
			//LocalPlayerOne->iAmountOfTurns = 0;
			//LocalPlayerTwo->iAmountOfTurns = 1;

		}
	}
	return true;
}


bool Game::setupAIBoard(Player* &WhatPlayer)
{
	bool isOccupiedByYourOwnShip = false;
	int col, row = 0;
	WhatPlayer->bisAI = true;
	if (WhatPlayer == LocalPlayerTwo)
	{
		if (WhatPlayer->iAmountOfTurns == 1)
		{
			for (LocalPlayerTwo->iPlacedPieces; LocalPlayerTwo->iPlacedPieces < LocalPlayerTwo->iPiece; LocalPlayerTwo->iPlacedPieces++)
			{

					col = rand() % 4 + 0; row = rand() % 5 + 1;
					isOccupiedByYourOwnShip = SetGrid(col, row, LocalPlayerTwo);
					if (isOccupiedByYourOwnShip == false)
					{
						p2pieces[LocalPlayerTwo->iPlacedPieces].x = col;
						p2pieces[LocalPlayerTwo->iPlacedPieces].y = row;

						system("cls");
					}
					else
					{
						setupBoard(WhatPlayer);
					}
				LocalPlayerOne->iAmountOfTurns = 0;
				LocalPlayerTwo->iAmountOfTurns = 1;
			}
		}
	}
	return true;
}

void Game::notValid(Player* &WhatPlayer)
{
	cout << "NOT A VALID OPTION!\nEnding the game now\n";
	processTurn(WhatPlayer);
}
//			board[col][row][i] = HitCheck::HIT;
			// checkl to see if piece is at that location
			// if so // mark that peice as hit once
			// update the board at that location to show hitcheck::HIT
			// else it's a miss but still update board
int Game::processTurn(Player* &WhatPlayer)
{
	bool isOccupied, isFinishedTurn = false;
	int col;
	int row;


	WhatPlayer->playerinput = NULL;
	if (WhatPlayer->bisAI == false)
	{
		if (WhatPlayer->bcompletedSetup == false)
		{
			WhatPlayer->bcompletedSetup = setupBoard(LocalPlayerOne);
		}
		else
		{
			cout << WhatPlayer->getNames() << " it is your turn! Time to make a move\nType [1] Attack\nType [2] End Turn " << endl;
			cin.ignore();
			cin >> WhatPlayer->playerinput;
			if (cin) {
				switch ((WhatPlayer->playerinput))
				{
				default:
					cout << "NOT A VALID OPTION!\nEnding game\n";
					break;
				case ATTACK:
					if (WhatPlayer->bHasAttacked == false)
					{
						col = enterColPosition();
						row = enterRowPosition();
						WhatPlayer->bHasAttacked = true;

						if (WhatPlayer == LocalPlayerOne)
						{
							//check if input is occupied with the piece grid
							isOccupied = GetGrid(col, row, LocalPlayerOne);
							if (isOccupied == true)
							{
								if (board2[col][row] == HitCheck::HIT)
								{
									WhatPlayer->bHasAttacked = false;
									processTurn(WhatPlayer);
									cout << "You have already shot there! Try again" << endl;
								}
								else
								{
									board2[col][row] = HitCheck::HIT; //print hit
									LocalPlayerTwo->iPiece--;
								}
							}
							else
							{
								board2[col][row] = HitCheck::MISS; //print midd
							}
						}
						if (WhatPlayer == LocalPlayerTwo)
						{
							isOccupied = GetGrid(col, row, LocalPlayerTwo);
							if (isOccupied == true)
							{
								if (board[col][row] == HitCheck::HIT)
								{
									WhatPlayer->bHasAttacked = false;
									processTurn(WhatPlayer);
									cout << "You have already shot there! Try again" << endl;
								}
								else
								{
									board[col][row] = HitCheck::HIT;
									LocalPlayerOne->iPiece--;
								}
							}
							else
							{
								board[col][row] = HitCheck::MISS;
							}
						}
						LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? displayBoard(LocalPlayerOne) : displayBoard(LocalPlayerTwo);
					}
					else
					{
						cout << "You have already attacked, please choose one of the following options\n" << endl;
						processTurn(WhatPlayer);
					}
					break;

				case ENDTURN:

					system("cls");

					WhatPlayer->iAmountOfTurns += 1;
					WhatPlayer->bHasAttacked = false;
					WhatPlayer->playerinput = NUL;
					LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? displayBoard(LocalPlayerOne) : displayBoard(LocalPlayerTwo);
					break;
				}
			}
			if (!cin)
			{

				cin.ignore();
				cin.clear(1000, '\n');
				processTurn(WhatPlayer);
			}
		}
	}
	if(WhatPlayer->bisAI == true)
	{
		cout << "CPU is making their move....\n";
		col = rand() % 4 + 0; row = rand() % 5 + 1;
		WhatPlayer->bHasAttacked = true;

		isOccupied = GetGrid(col, row, LocalPlayerTwo);
		if (isOccupied == true)
		{
			if (board[col][row] == HitCheck::HIT)
			{
				WhatPlayer->bHasAttacked = false;
				processTurn(WhatPlayer);
			}
			else
			{
				board[col][row] = HitCheck::HIT;
				LocalPlayerOne->iPiece--;
			}
		}
		else
		{
			board[col][row] = HitCheck::MISS;
		}
		system("PAUSE");
		WhatPlayer->iAmountOfTurns += 1;
		WhatPlayer->bHasAttacked = false;
		WhatPlayer->playerinput = NUL;
		LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? displayBoard(LocalPlayerOne) : displayBoard(LocalPlayerTwo);
	}
	return 0;
}



void Game::displayBoard(Player* &WhatPlayer)
{
	system("cls");

		cout << "It is " << WhatPlayer->getNames() << "'s turn \n" << endl;
		cout << "    A    B    C    D    E\n\n";

		for (int row = 0; row < 5; row++)
		{
			cout << row + 1;
			for (int col = 0; col < 5; col++)
			{
				//we have two boards to keep track of shots / misses for each player - used to compare with piece coords
				cout << " ";
				if (WhatPlayer == LocalPlayerOne)
				{
					cout << "  " << board2[col][row] << " ";
				}
				if (WhatPlayer == LocalPlayerTwo)
				{
					cout << "  " << board[col][row] << " ";
				}

			}
			cout << endl;
		}
		cout << "\n\n" << LocalPlayerOne->getNames() << "\t\t\t" << LocalPlayerTwo->getNames() << endl;
		cout << "Ships remaining: " << LocalPlayerOne->iPiece << "\tShips remaining: " << LocalPlayerTwo->iPiece << endl;
		cout << "Turns elapsed: " << LocalPlayerOne->iAmountOfTurns << "\tTurns Elapsed: " << LocalPlayerTwo->iAmountOfTurns - 1 << endl;
		cout << "-------------------------------------------------" << endl;
		checkForWinner();
		LocalPlayerOne->iAmountOfTurns < LocalPlayerTwo->iAmountOfTurns ? processTurn(LocalPlayerOne) : processTurn(LocalPlayerTwo);



}

Game::Game()
{


}


Game::~Game()
{

}

