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

	int iPiece[2];
	int iWins;
	int iGamesPlayed;

	bool bHasMoved;
	bool bHasAttacked;
	bool bIsActivePiece;

};

