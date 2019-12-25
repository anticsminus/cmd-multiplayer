#pragma once
#include <string>

using namespace std;



class Player
{
private:
	string PlayerName;
public:
	Player();
	~Player();
	Player(string NewName) : PlayerName(NewName) {}

	void setNames(string Name)
	{
		Name = PlayerName;
	}
	string getNames() { return PlayerName; }
	int iPiece = 4;
	int iPlacedPieces = 0;
	int iWins = 0;
	int iAmountOfTurns = 0;
	int iGamesPlayed = 0;
	int playerinput = 0;
	bool bcompletedSetup = false;
	bool bHasAttacked = false;
	bool bIsActivePiece = true;
	bool bisAI = false;

};

