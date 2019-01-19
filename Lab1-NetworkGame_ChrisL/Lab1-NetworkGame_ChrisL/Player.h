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
	int iGamesPlayed;
	int playerinput;
	bool bHasMoved;
	bool bHasAttacked;
	bool bIsActivePiece;

};

