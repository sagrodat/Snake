#include "Game.hpp"

Game::Game()
{
	assets.updateCurrentScoreTexts(0);
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
	drawEndGameScreen();
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

int Game::getDirectionOfKey(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up) {
		return Snake::UP;
	}
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left) {
		return Snake::LEFT;
	}
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down) {
		return Snake::DOWN;
	}
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right) {
		return Snake::RIGHT;
	}
	return -1;
}

sf::Keyboard::Key* Game::getWhichKeyIsPressed(std::vector <sf::Keyboard::Key>& vec)
{
	sf::Keyboard::Key * ret = NULL;

	for (int i = 0; i < vec.size(); i++)
	{
		if (sf::Keyboard::isKeyPressed(vec.at(i)))
		{
			ret = &vec.at(i);
			break;
		}
	}
	return ret;
}