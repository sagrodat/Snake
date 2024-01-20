#pragma once

#include "SFMLObjects.hpp"
#include "Board.hpp"
#include "Snake.hpp"
#include "Fruits.hpp"

class Game
{
public :
	Game();
private : // game variables
	float startFrameDuration = 0.25f;
	float minFrameDuration = 0.01f;
	sf::Time frameInterval = sf::seconds(startFrameDuration);

	int score = 0;
	int bestScore = -1;

	bool started = false;

public : // initiated in header


	std::vector<sf::Keyboard::Key> startingKeys = {
		sf::Keyboard::W,
		sf::Keyboard::A,
		sf::Keyboard::S,
		sf::Keyboard::D,

		sf::Keyboard::Left,
		sf::Keyboard::Up,
		sf::Keyboard::Right,
		sf::Keyboard::Down
	};

	std::vector<sf::Keyboard::Key> upKeys = {
		sf::Keyboard::W,
		sf::Keyboard::Up
	};

	std::vector<sf::Keyboard::Key> rightKeys = {
		sf::Keyboard::D,
		sf::Keyboard::Right
	};

	std::vector<sf::Keyboard::Key> leftKeys = {
		sf::Keyboard::A,
		sf::Keyboard::Left
	};

	std::vector<sf::Keyboard::Key> downKeys = {
		sf::Keyboard::S,
		sf::Keyboard::Down
	};

public : // game classes
	Board board;
	Snake snake;
	Fruits fruits;

public :
	void startGame();
	void endGame();
	bool hasStarted();
	bool isOneOfTheseKeysPressed(std::vector<sf::Keyboard::Key> & vec);
	sf::Time getFrameInterval();
	void setFrameInterval(sf::Time interval);
	bool snakeCapturedFruit();
	void increaseSpeed();
	void increaseScore();
	float calculateNewFrameDuration();
	bool fruitGeneratedInsideSnake();


};
inline Game game;