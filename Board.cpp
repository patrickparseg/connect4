/*Patrick Parsegian
CSIS 137
Final Project: Connect Four*/

#include "Board.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>

using namespace std;

Board::Board()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Board::display()
{
	cout << "|" << setw(2) << board[0][0] << "  |" << setw(2) << board[0][1] << "  |" << setw(2) << board[0][2] 
		<< "  |" << setw(2) << board[0][3] << "  |" << setw(2) << board[0][4]
		<< "  |" << setw(2) << board[0][5] << "  |" << setw(2) << board[0][6] << "  |" << endl;
	cout << "|----+----+----+----+----+----+----|\n";
	cout << "|" << setw(2) << board[1][0] << "  |" << setw(2) << board[1][1] << "  |" << setw(2) << board[1][2] 
		<< "  |" << setw(2) << board[1][3] << "  |" << setw(2) << board[1][4]
		<< "  |" << setw(2) << board[1][5] << "  |" << setw(2) << board[1][6] << "  |" << endl;
	cout << "|----+----+----+----+----+----+----|\n";
	cout << "|" << setw(2) << board[2][0] << "  |" << setw(2) << board[2][1] << "  |" << setw(2) << board[2][2]
		<< "  |" << setw(2) << board[2][3] << "  |" << setw(2) << board[2][4]
		<< "  |" << setw(2) << board[2][5] << "  |" << setw(2) << board[2][6] << "  |" << endl;
	cout << "|----+----+----+----+----+----+----|\n";
	cout << "|" << setw(2) << board[3][0] << "  |" << setw(2) << board[3][1] << "  |" << setw(2) << board[3][2]
		<< "  |" << setw(2) << board[3][3] << "  |" << setw(2) << board[3][4]
		<< "  |" << setw(2) << board[3][5] << "  |" << setw(2) << board[3][6] << "  |" << endl;
	cout << "|----+----+----+----+----+----+----|\n";
	cout << "|" << setw(2) << board[4][0] << "  |" << setw(2) << board[4][1] << "  |" << setw(2) << board[4][2]
		<< "  |" << setw(2) << board[4][3] << "  |" << setw(2) << board[4][4]
		<< "  |" << setw(2) << board[4][5] << "  |" << setw(2) << board[4][6] << "  |" << endl;
	cout << "|----+----+----+----+----+----+----|\n";
	cout << "|" << setw(2) << board[5][0] << "  |" << setw(2) << board[5][1] << "  |" << setw(2) << board[5][2]
		<< "  |" << setw(2) << board[5][3] << "  |" << setw(2) << board[5][4]
		<< "  |" << setw(2) << board[5][5] << "  |" << setw(2) << board[5][6] << "  |" << endl;
	cout << "|==================================|\n";
	cout << setw(4) << "0" << setw(5) << "1" << setw(5) << "2" << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6";
}

bool Board::placePiece(Piece p, int row)
{
	if (board[row][p.getCol()] == " ")
	{
		board[row][p.getCol()] = p.getSign();
		slots -= 1;
		return true;
	}
	else {
		placePiece(p, row - 1);
	}
}

bool Board::checkVert(string s)
{
	int count = 0;
	for (int j = 0; j < 7; j++)
	{
		count = 0;
		for (int i = 0; i < 6; i++)
		{
			if (board[i][j] == s)
			{
				count += 1;
				if (count == 4)
					return true;
			}
			else if (count > 0)
			{
				count = 0;
			}
		}
	}
	return false;
}

bool Board::checkHoriz(string s)
{
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		count = 0;
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == s)
			{
				count += 1;
				if (count == 4)
					return true;
			}
			else if (count > 0)
			{
				count = 0;
			}
		}
	}
	return false;
}

bool Board::checkDiag1(string s)
{
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		count = 0;
		for (int j = 0; j < 7; j++)
		{
			if (j + i < 6)
			{
				if (board[j + i][j] == s)
				{
					count += 1;
					if (count == 4)
						return true;
				}
				else if (count > 0)
				{
					count = 0;
				}
			}
		}

	}

	for (int i = 0; i < 6; i++)
	{
		count = 0;
		for (int j = 6; j >= 0; j--)
		{
			if (j - i >= 0)
			{
				if (board[j - i][j] == s)
				{
					count += 1;
					if (count == 4)
						return true;
				}
				else if (count > 0)
				{
					count = 0;
				}
			}
		}

	}
	return false;
}

bool Board::checkDiag2(string s)
{
	int count = 0;
	for (int i = 5; i >= 0; i--)
	{
		count = 0;
		for (int j = 0; j < 7; j++)
		{
			if (i - j >= 0)
			{
				if (board[i - j][j] == s)
				{
					count += 1;
					if (count == 4)
						return true;
				}
				else if (count > 0)
				{
					count = 0;
				}
			}
		}

	}

	for (int i = 0; i < 6; i++)
	{
		count = 0;
		for (int j = 6; j >= 0; j--)
		{
			if (5 - j + i <= 5)
			{
				if (board[5 - j + i][j] == s)
				{
					count += 1;
					if (count == 4)
						return true;
				}
				else if (count > 0)
				{
					count = 0;
				}
			}
		}

	}
	return false;
}

bool Board::drawCondition()
{
	if (slots == 0)
		return true;
	else
		return false;
}

string Board::getPiece(int a, int b)
{
	return board[a][b];
}

void Board::explode()
{
	int randCol = 0;

	srand(time(NULL));
	randCol = rand() % 7;

	for (int i = 0; i < 6; i++)
	{
		board[i][randCol] = " ";
	}
	slots += getNumPieceCol(randCol);
}

int Board::getNumPieceCol(int col)
{
	int numPieces = 0;
	for (int i = 0; i < 6; i++)
	{
		if (board[i][col] != " ")
		{
			numPieces += 1;
		}
	}
	return numPieces;
}
