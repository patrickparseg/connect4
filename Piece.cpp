/*Patrick Parsegian
CSIS 137
Final Project: Connect Four*/

#include "Piece.h"
#include <iostream>
#include <iomanip>

using namespace std;

Piece::Piece(string symbol)
{
	col = 0;
	sign = symbol;
}

void Piece::makeMove(int column)
{
	col = column;
}

int Piece::getCol()
{
	return col;
}

string Piece::getSign()
{
	return sign;
}
