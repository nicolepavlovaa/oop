#include <iostream>
#include "Header.h"
#include <cstring>
using namespace std;

Player::Player(char const * n, double s): name(nullptr), score(s)
{
	setName(n);
}
Player::Player(Player const& p) : name(nullptr), score(p.score)
{
	setName(p.name);
}

char * Player::getName() const
{
	return this->name;
}
double Player::getScore() const
{
	return this->score;
}
void Player::setName(char const* n)
{
	delete[] name;
	const int nameLength = strlen(n);
	name = new char[nameLength + 1];
	strcpy(name, n);
}
void Player::setScore(double score)
{
	this->score = score;
}
void Player::print() const
{
	cout << "Player " << name << " has " << score << " points." << endl;
}
