#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFMLObjects.hpp"
#include "Board.hpp"
class Snake
{
public :
	Snake();
public :
	enum Direction {
		LEFT = 0,
		UP = 1,
		RIGHT = 2,
		DOWN = 3
	};
	
private :
	int SNAKE_HEAD_ID = 0;

	const int startingTotalLength = 3;
	const int minDistanceFromEdge = startingTotalLength;
	int length;
	int startDirection = -1;
	int currentDirection = -1;

	long long moveNumber = 0;

	// used when generating the starting position ( don't want to start on the edge of screen)
	int headDistanceFromEdge = 10; 
	
	sf::Color headColor = sf::Color(75,75, 255);
	sf::Color bodyColor = sf::Color(0, 0, 255);

	// element at index 0 is the head, rest is the body
	std::vector<sf::RectangleShape>  *snakeElements; 

	void generateAndSetHeadStartingPosition();

public :
	void moveSnake();
	sf::Vector2f getHeadPosition();
	void setHeadPosition(sf::Vector2f);
	std::vector<sf::RectangleShape>* getSnakeElements();
	void setDirection(int direction);
	int getDirection();
	bool isPositionIllegal();
	int getSnakeHeadID();
	void increaseLength();

	void countMove();
	long long getMoveNumber();
	int getReversedDirection(int dir);

	sf::RectangleShape createNextBodyElement(int snakeDirection, int snakeCurrentBodyElementID);
};