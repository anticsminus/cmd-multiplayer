#include "Game.h"

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


	return 0;

}

void Game::displayBoard()
{

	//cout << "::::::::::::::::::::::::::::::::::::::::::\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||::::::||::::::||::::::||::::::||::::::||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||::::::||::::::||::::::||::::::||::::::||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||::::::||::::::||::::::||::::::||::::::||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||::::::||::::::||::::::||::::::::::::::||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "||      ||      ||      ||      ||      ||\n" << endl;
	//cout << "::::::::::::::::::::::::::::::::::::::::::\n" << endl;
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


