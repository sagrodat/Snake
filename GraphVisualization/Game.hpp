#pragma once

#include "SFMLObjects.hpp"
#include "Board.hpp"
#include "Snake.hpp"

class Game
{
public :
	Game();
private : // game variables
	sf::Time frameInterval = sf::seconds(0.25f);
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

public :
	void startGame();
	void endGame();

	bool hasStarted();

	bool isOneOfTheseKeysPressed(std::vector<sf::Keyboard::Key> & vec);

	sf::Time getFrameInterval();
	void setFrameInterval(sf::Time interval);


};
inline Game game;