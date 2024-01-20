#pragma once
#include "SFML/Graphics.hpp"
#include "Board.hpp"
class Fruits
{
public :
	Fruits();

private :
	bool fruitOnBoard = false;
	bool snakeJustAteFruit = false;
	sf::RectangleShape fruit;
	sf::Color fruitColor = sf::Color(255, 0, 0);
	sf::Vector2f generateFruitPosition();
public :
	void generateFruit();
	sf::Vector2f getFruitPos();
	sf::RectangleShape getFruit();
};