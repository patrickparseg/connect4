/*Patrick Parsegian
CSIS 137
Final Project: Connect Four*/

#include "Player.h"
#include <iostream>
#include <string>
#include <iomanip>

Player::Player(string s)
{
	setSign(s);
}

Player::Player()
{
	setSign("0");
}

string Player::getSign()
{
	return sign;
}

void Player::setSign(string s)
{
	sign = s;
}