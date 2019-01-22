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
	int iPiece = 1;
	int iWins;
	int iAmountOfTurns = 0;
	int iGamesPlayed;
	int playerinput = 0;
	bool bHasMoved;
	bool bHasAttacked = false;
	bool bIsActivePiece = true;

};

