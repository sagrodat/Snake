#pragma once
#include "SFMLObjects.hpp"
class Board
{
public :
	Board();
	
	enum fieldStatus {
		EMPTY = -1,
		SNAKE = 0,
		FOOD = 1
	};

private :
	static const int rows = 20;
	static const int cols = 20;
	const int numberOfFields = rows * cols;

	static int fieldWidth;
	static int fieldHeight;

	sf::Color boardColorEven = sf::Color(0, 255,0);
	sf::Color boardColorOdd = sf::Color(0, 200, 0);

	sf::RectangleShape** backgroundFields;

	int** playingFields;

public :
	static void initializeStaticMemberVariables();
	sf::RectangleShape** getBackgroundFields();
	static int getNumberOfRows();
	static int getNumberOfColumns();
	static int getFieldWidth();
	static int getFieldHeight();
};