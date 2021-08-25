/*Patrick Parsegian
CSIS 137
Final Project: Connect Four*/

#include <iostream>
#include <iomanip>
#include "Game.h"

using namespace std;

Game::Game(string s) 
{
	if (s == "1")
	{
		startGame();
	}
	else if (s == "2")
	{
		startExplode();
	}
}

void Game::startGame()
{
	string p1;
	string p2;
	bool win = false;

	p1 = "89";
	p2 = "89";
	cout << "Hello Welcome to Connect Four!" << endl;
	while (p1.length() > 1)
	{
		cout << "\nPlayer 1 please select 1 character either a number or letter to represent your piece: " << endl;
		cin >> p1;
		if (p1.length() > 1)
		{
				cout << "Please input a single character to represent your piece. Examples: 'X' '7'" << endl;
		}
	}
	while (p2.length() > 1)
	{
		cout << "Player 2 please select a different character either a number or letter to represent your piece: " << endl;
		cin >> p2;
		if (p2.length() > 1)
		{
			cout << "Please input a single character to represent your piece. Examples: 'X' '7'" << endl;
		}
	}
	player1.setSign(p1);
	player2.setSign(p2);
	Piece piece1(player1.getSign()), piece2(player2.getSign());

	cout << "To place your piece, please enter a column number from 0-6." << endl;
	Board x;
	x.display();

	int move1;
	int move2;
	while (win == false)
	{
		move1 = 7;
		move2 = 7;
		while (move1 > 6 || move1 < 0)
		{
			cout << "\nPlayer 1 please select a column: " << endl;
			cin >> move1;
			if (move1 > 6 || move1 < 0)
			{
				cout << "Invalid Column! Please input a valid column from 0-6." << endl;
			}
		}
		piece1.makeMove(move1);
		x.placePiece(piece1, 5);
		x.display();
		if (x.checkHoriz(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		else if (x.checkVert(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		else if (x.checkDiag1(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		else if (x.checkDiag2(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		if (!win)
		{
			while (move2 > 6 || move2 < 0)
			{
				cout << "\nPlayer 2 please select a column: " << endl;
				cin >> move2;
				if (move2 > 6 || move2 < 0)
				{
					cout << "Invalid Column! Please input a valid column from 0-6." << endl;
				}
			}
			piece2.makeMove(move2);
			x.placePiece(piece2, 5);
			x.display();
			if (x.checkHoriz(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.checkVert(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.checkDiag1(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.checkDiag2(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.drawCondition())
			{
				cout << "There is a draw. Good Game!" << endl;
				win = true;
			}
		}
	}
}

void Game::startExplode()
{
	string p1;
	string p2;
	bool win = false;
	int p1Limit = -1;
	int p2Limit = -1;

	p1 = "89";
	p2 = "89";
	cout << "Hello Welcome to Connect Four EXPLODE!" << endl;
	cout << "In this game mode, all the same rules for Connect Four apply." << endl << "The only difference is you can DEMOLISH one of the columns at random when inputting '-1'." << endl;
	cout << "This explosion feature can only be used once per game by each opponent." << endl;
	while (p1.length() > 1)
	{
		cout << "\nPlayer 1 please select 1 character either a number or letter to represent your piece: " << endl;
		cin >> p1;
		if (p1.length() > 1)
		{
			cout << "Please input a single character to represent your piece. Examples: 'X' '7'" << endl;
		}
	}
	while (p2.length() > 1)
	{
		cout << "Player 2 please select a different character either a number or letter to represent your piece: " << endl;
		cin >> p2;
		if (p2.length() > 1)
		{
			cout << "Please input a single character to represent your piece. Examples: 'X' '7'" << endl;
		}
	}
	player1.setSign(p1);
	player2.setSign(p2);
	Piece piece1(player1.getSign()), piece2(player2.getSign());

	cout << "To place your piece, please enter a column number from 0-6 or utilize your EXPLOSION feature by entering '-1'" << endl << "(EXPLOSION can only be done once)" << endl;
	Board x;
	x.display();

	int move1;
	int move2;
	while (win == false)
	{
		move1 = 7;
		move2 = 7;
		while (move1 > 6 || move1 < p1Limit)
		{
			cout << "\nPlayer 1 please select a column: " << endl;
			cin >> move1;
			if (move1 > 6 || move1 < p1Limit)
			{
				cout << "Invalid Column! Please input a valid column from 0-6." << endl;
			}
		}
		if (move1 == -1)
		{
			x.explode();
			p1Limit += 1;
		}
		else
		{
			piece1.makeMove(move1);
			x.placePiece(piece1, 5);
		}
		x.display();
		if (x.checkHoriz(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		else if (x.checkVert(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		else if (x.checkDiag1(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		else if (x.checkDiag2(p1))
		{
			cout << "\nPlayer 1 WON!" << endl;
			win = true;
		}
		if (!win)
		{
			while (move2 > 6 || move2 < p2Limit)
			{
				cout << "\nPlayer 2 please select a column: " << endl;
				cin >> move2;
				if (move2 > 6 || move2 < p2Limit)
				{
					cout << "Invalid Column! Please input a valid column from 0-6." << endl;
				}
			}
			if (move2 == -1)
			{
				x.explode();
				p2Limit += 1;
			}
			else
			{
				piece2.makeMove(move2);
				x.placePiece(piece2, 5);
			}
			x.display();
			if (x.checkHoriz(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.checkVert(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.checkDiag1(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.checkDiag2(p2))
			{
				cout << "\nPlayer 2 WON!" << endl;
				win = true;
			}
			else if (x.drawCondition())
			{
				cout << "There is a draw. Good Game!" << endl;
				win = true;
			}
		}
	}
}
