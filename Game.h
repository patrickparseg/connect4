/*Patrick Parsegian
CSIS 137
Final Project: Connect Four

UML Design:

		Game
		---------------
		-player1: Player
		-player2: Player
		-board: Board
		---------------
		+Game(string)
		+startGame(): void
		+startExplode(): void
*/

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Board.h"

class Game
{
private:
	Player player1;
	Player player2;
	Board board;
public:
	Game(string);
	void startGame();
	void startExplode();
};



#endif