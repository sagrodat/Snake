#include "Fruits.hpp"

Fruits::Fruits()
{
	//create first fruit that will show up before the game's started
	generateFruit();
}

void Fruits::generateFruit()
{
	fruitOnBoard = true;
	fruit.setPosition(generateFruitPosition());
	fruit.setFillColor(fruitColor);
	fruit.setSize(sf::Vector2f(Board::getFieldWidth(), Board::getFieldHeight()));
}

sf::Vector2f Fruits::generateFruitPosition()
{
	int fruitX = rand() % (Board::getNumberOfRows());
	int fruitY = rand() % (Board::getNumberOfColumns());
	fruitX *= Board::getFieldWidth();
	fruitY *= Board::getFieldHeight();
	return sf::Vector2f(fruitX, fruitY);
}

sf::Vector2f Fruits::getFruitPos() { return fruit.getPosition(); }

sf::RectangleShape Fruits::getFruit() { return fruit; }