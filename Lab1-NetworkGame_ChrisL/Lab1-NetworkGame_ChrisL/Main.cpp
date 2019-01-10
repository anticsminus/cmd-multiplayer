/*========================*\
* Lab 1
* Name: Chris Landry & Mason Lee
* Date: January 8th, 2019.
*
*=========================*/

#include <iostream>
#include "Game.h"
string name;
Player* p1;
Player* p2;

Game game(p1, p2);

using namespace std;

void initNames() //function for initializing the names
{
	cout << "Welcome to Battleships! A local multiplayer game between two players\n\n" << endl;
	cout << "\n\nPlease enter your name for player one \n";
	cin >> name; //take input from console for name 
	p1 = new Player(name); //set to specific player 

	//rinse & repeat for player 2
	cout << "\n\nPlease enter your name for player two \n";
	cin >> name; 
	p2 = new Player(name);
}

int main()
{
	initNames();
	//game.displayBoard();

	system("PAUSE");
	return 0;
}