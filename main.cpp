/*Patrick Parsegian
CSIS 137
Final Project: Connect Four*/

#include "Game.h"
#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace std;
void menu();

int main()
{
	string userInput = " ";
	cout << userInput;
	do
	{
		menu();
		cin >> userInput;

		if (userInput == "1")
		{
			cout << endl;
			Game X(userInput);
		}
		else if (userInput == "2")
		{
			cout << endl;
			Game X(userInput);
		}
		else if (userInput == "3")
		{
			cout << "\n============" << endl;
			cout << "Instructions" << endl;
			cout << "============" << endl;
			cout << "Player 1 starts by selecting a single character (either number or letter) to use as their piece." << endl << "Player 2 then follows by selecting their piece." << endl;
			cout << "The players then take turns selecting what columns to place their pieces into in order to form a 4 in-a-row." << endl;
			cout << "A 4 in-a-row or Connect 4, can be assembled by having four of one player's pieces in a row either vertically, " << endl;
			cout <<"horizontally, or diagonally." << endl;
			cout << "\n=================" << endl;
			cout << "Story of the Game" << endl;
			cout << "=================" << endl;
			cout << "Four in a Row's origin has been ambiguous as the earliest story regarding the game is revolved around " << endl;
			cout << "an explorer name Captain Cook, who has spend excessive amount of time playing this game against " << endl;
			cout << "travelers earned the game name Captain's Mistress. " << endl;
			cout << "Milton Bradley trademarked a version of the game called Connect 4 and distributed in the states " << endl;
			cout << "in 1974, however there are versions of Four in a Row described in Robbie Bell's book that dates to " << endl;
			cout << "Edwardian time near the beginning of 20th century." << endl;
			cout << "Classic version of Four in a Row consist of a 6 by 7 board design, with 2 sets of color tokens. " << endl;
			cout << "The objective of the game is to connect four tokens of the chosen color before your opponent does. " << endl;
			cout << "Rules vary depending on the variation of the board used, and game can be started in mid positions as well. " << endl;
			cout << "Today the game is a popular hit with family and kids alike, it is a game with easy engagementand quick pace fun." << endl;
		}
		else if (userInput == "4")
		{
			cout << "\nThanks for playing! Have a nice day." << endl;
		}
		else
		{
			cout << "\nInvalid Selection. Please try again with a number from 1-3: " << endl;
		}
	} while (userInput != "4");
	
	system("PAUSE");
	return 0;
}

void menu()
{
	cout << "\n=================" << endl;
	cout << "CONNECT FOUR MENU" << endl;
	cout << "=================" << endl;
	cout << "1) Play Connect Four" << endl;
	cout << "2) Play Connect Four EXPLODE!" << endl;
	cout << "3) Learn About the Game" << endl;
	cout << "4) Quit" << endl;
}
