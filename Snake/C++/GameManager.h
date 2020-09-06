#pragma once

#include <iostream>
#include <ctime>
#include <vector>

//The borders
const int Row = 20; 
const int Column = 50;

enum direction
{
	STOP = 0, UP, DOWN, LEFT, RIGHT
};

bool gameOver = false;
std::vector<int>playerLocationX;
std::vector<int>playerLocationY;

class Entity
{
	public:
	int posX;
	int posY;
};


class Snake : Entity
{
	private:
	int score;
	int bodyCount;
	int move;

	public: 
	Snake()
	{
		score = 0;
		bodyCount = 0;
		posX = Column / 2;
		posY = Row / 2;
		move = STOP;
	}

	int getPosX() { return posX; }

	int getPosY() { return posY; }

	void setPosX(int x) { posX = x; }

	void setPosY(int y) { posY = y; }

	int getMove() { return move; }
	
	void setMove(int direction) { move = direction; }

	void setScore(int score) { this->score = score; }

	int getScore() { return score; }

	void setBodyCount(int n) { bodyCount = n; }

	int getBodyCount() { return bodyCount; }

};

class Fruit : Entity
{
	public:
	void setRandomLocationX()
	{
		posX = rand() % (Column - 1);
		if (posX == 0) { setRandomLocationX(); }
	}

	void setRandomLocationY()
	{
		posY = rand() % (Row - 1);
		if (posY == 0) { setRandomLocationY(); }
	}

	int getPosX() { return posX; }

	int getPosY() { return posY; }

	Fruit()
	{
		setRandomLocationX();
		setRandomLocationY();
	}
};

Snake player;
Snake playerBody;
Fruit fruit;


