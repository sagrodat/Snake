#include "Game.hpp"

Game::Game()
{
	
}

bool Game::hasStarted() { return started; }
void Game::startGame() { started = true; }

bool Game::isOneOfTheseKeysPressed(std::vector<sf::Keyboard::Key>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (sf::Keyboard::isKeyPressed(vec.at(i)))
			return true;
	}
	return false;
}

sf::Time Game::getFrameInterval() { return frameInterval; }
void Game::setFrameInterval(sf::Time interval) { frameInterval = interval; }