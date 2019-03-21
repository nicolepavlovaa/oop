#ifndef __PLAYER_H
#define __PLAYER_H 
#pragma warning(disable : 4996)
const int MAX = 100;
class Player
{
	char * name;
	double score;

public:
	Player(char const * name= "Anonymous", double score=0);
	Player(Player const& p);

	char * getName() const;
	double getScore() const;
	void setName(char const * name);
	void setScore(double score);

	void print() const;
};
#endif
