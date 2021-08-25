/*Patrick Parsegian
CSIS 137
Final Project: Connect Four

UML Design:

		Piece
		---------------
		-sign: string
		-col: int
		---------------
		+Piece(string)
		+makeMove(int): void
		+getCol(): int
		+getSign(): string
*/

#ifndef PIECE_H
#define PIECE_H
#include <string>

using namespace std;

class Piece
{
private:
	string sign;
	int col;
public:
	Piece(string);
	void makeMove(int);
	int getCol();
	string getSign();
};





#endif
