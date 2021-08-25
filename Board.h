/*Patrick Parsegian
CSIS 137
Final Project: Connect Four

UML Design:

		Board
		---------------
		-board: string
		-slots: int
		-player: int
		---------------
		+Board()
		+display(): void
		+placePiece(Piece,int): bool
		+checkVert(string): bool
		+checkHoriz(string): bool
		+checkDiag1(string): bool
		+checkDiag2(string): bool
		+drawCondition(): bool
		+getPiece(int, int): string
		+explode(): void
		+getNumPieceCol(int): int
*/

#include "Piece.h"
#ifndef BOARD_H
#define BOARD_H


class Board
{
private:
	string board[6][7];
	int slots = 42;
	int player = 1;
public:
	Board();
	void display();
	bool placePiece(Piece,int);
	bool checkVert(string);
	bool checkHoriz(string);
	bool checkDiag1(string);
	bool checkDiag2(string);
	bool drawCondition();
	string getPiece(int, int);
	void explode();
	int getNumPieceCol(int);

};


#endif