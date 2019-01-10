#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string NewName;
public:
	Player();
	~Player();

	Player(string Name) : NewName(Name){}

	int iPiece[2];
	int iWins;
	int iGamesPlayed;

	bool bHasMoved;
	bool bHasAttacked;
	bool bIsActivePiece;

};

