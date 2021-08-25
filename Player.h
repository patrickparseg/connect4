/*Patrick Parsegian
CSIS 137
Final Project: Connect Four

UML Design:

		Player
		---------------
		-sign: string
		---------------
		+Player(string)
		+Player()
		+getSign(): string
		setSign(string): void*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
private:
	string sign;
public:
	Player(string);
	Player();
	string getSign();
	void setSign(string);
};



#endif
