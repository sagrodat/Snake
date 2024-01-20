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

void Game::endGame()
{
	std::cout << "Game lost!" << std::endl;
	drawEndGameScreen();
	/* 
	* TO DO 
	* Draw on the screen :
	* - a reset button
	* - score number (eaten fruits)
	* 
	*/
}

int Game::getScore() { return score; }

bool Game::snakeCapturedFruit()
{
	if (snake.getSnakeElements()->at(snake.getSnakeHeadID()).getPosition() == fruits.getFruitPos())
		return true;
	return false;
}

void Game::increaseSpeed()
{
	frameInterval = sf::seconds(calculateNewFrameDuration());
}
float Game::calculateNewFrameDuration()
{
	float a = startFrameDuration;
	float b = 0.05; // the higher the value the faster the difficulty (speed) increases
	float c = minFrameDuration;

	// exponential function : 0.25 for x = 0 and 0.01 as x->inf
	return (a-c) * exp(-b * score) + c; 
}

void Game::increaseScore() { score += 1; }

bool Game::fruitGeneratedInsideSnake()
{
	for (int i = 0; i < snake.getSnakeElements()->size(); i++)
	{
		if (snake.getSnakeElements()->at(i).getPosition() == fruits.getFruitPos())
			return true;
	}
	return false;
}
