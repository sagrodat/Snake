#include "GameManager.hpp"

GameManager::GameManager()
{
	createNextGameInstance();
}

void GameManager::createNextGameInstance()
{
	delete game;
	game = new Game();
}

int GameManager::getHighScore() { return highScore; }
void GameManager::updateHighScore()
{
	int currentScore = game->getScore();
	if (currentScore > highScore)
	{
		highScore = currentScore;
	}
}