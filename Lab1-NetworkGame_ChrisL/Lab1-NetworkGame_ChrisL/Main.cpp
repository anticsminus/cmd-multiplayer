/**********************(
	*Welcome to CMD battleships
	*Game networking lab
	*Name: Christopher Landry
	*This game is a local battleships variant, allows players to input coords and place ships on the board
	*Ships are not revealed until the player attacks the area
	*Local multiplayer only

*/

#include <iostream>
#include "Game.h"
#include <time.h>
string name;
Player* p1;
Player* p2;


using namespace std;

void initNames() //function for initializing the names
{

	srand(time(NULL));
	int aichoice;
	cout << "Welcome to Battleships! A local multiplayer game between two players\nProgrammed in C++ using visual studio\nMade by Christopher Landry\n\nPlease choose game mode\n[0] Player vs Player\n[1] Player vs Computer" << endl;
	cin >> aichoice;
	try {


		if (cin)
		{
			if (aichoice == 0)
			{
				cout << "\n\nPlease enter your name for player one: ";
				cin >> name; //take input from console for name 
				p1 = new Player(name); //set to specific player 
				bool gameRunning = true;

				//rinse & repeat for player 2
				cout << "\nPlease enter your name for player two: ";
				cin >> name;
				p2 = new Player(name);
				p2->iAmountOfTurns = 1; //set the turn for player two higher so that player one will start first 
				system("cls");
				Game game(p1, p2); //attach players
				//complete board setup
				p1->bcompletedSetup = game.setupBoard(p1);
				if (p1->bcompletedSetup == true)
				{

					p2->bcompletedSetup = game.setupBoard(p2);
				}
				//while (gameRunning)
				//{
				game.displayBoard(p1);
				//}
			}
			if (aichoice == 1)
			{
				cout << "\n\nPlease enter your name for player one: ";
				cin >> name; //take input from console for name 
				p1 = new Player(name); //set to specific player 
				bool gameRunning = true;
				//rinse & repeat for player 2
				cout << "\nPlease enter your name for player two: ";
				int randnamechoice = rand() % 5 + 1;
				switch (randnamechoice)
				{
				case 1:
					name = "Nicole";
					break;
				case 2:
					name = "Gavin";
					break;
				case 3:
					name = "Christopher";
					break;
				case 4:
					name = "Jeff";
					break;
				case 5:
					name = "Joel";
					break;
				}

				p2 = new Player(name);
				p2->iAmountOfTurns = 1; //set the turn for player two higher so that player one will start first 
				system("cls");
				Game game(p1, p2); //attach players
				//complete board setup
				p1->bcompletedSetup = game.setupBoard(p1);
				if (p1->bcompletedSetup == true)
				{
					p2->bisAI = true;
					p2->bcompletedSetup = game.setupAIBoard(p2);
				}
				//while (gameRunning)
				//{
				game.displayBoard(p1);
				//}

			}
		}
		if (!cin)
		{
			cin.ignore();
			cin.clear(1000, '\n');
			initNames();
		}
	}
	catch (exception e)
	{
		
	}
}

int main()
{
	initNames();
	

	system("PAUSE");
	return 0;
}