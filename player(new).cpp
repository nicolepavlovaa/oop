#include <iostream>
#include "Header.h"
#include <cstring>
using namespace std;

Player::Player(char const * n, double s) : name(nullptr), score(s)
{
	setName(n);
}
Player::Player(const Player& other) :name(nullptr), score(other.score)
{
	setName(other.name);
}
void Player::setName(char const * n)
{
	delete[] name;
	name = new char[MAX + 1];
	strcpy(name, n);
}
void Player::setScore(double s)
{
	score = s;
}
char * Player::getName() const
{
	return name;
}
double Player::getScore() const
{
	return score;
}
void Player::print() const
{
	cout << "Player " << name << " has " << score << " points. " << endl;
}
Player::~Player()
{
	delete[] name;
}
