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
	int currentScoreEndGame = game->getScore();
	if (currentScoreEndGame > highScore)
	{
		highScore = currentScoreEndGame;
		assets.updateHighScoreText(currentScoreEndGame);
	}
}