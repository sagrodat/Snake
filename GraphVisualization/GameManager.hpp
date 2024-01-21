#pragma once
#include "Game.hpp"
#include "Assets.hpp"
class GameManager {
public :
	GameManager();
private :
	int highScore = 0;
public :
	void createNextGameInstance();
	void updateHighScore();
	int getHighScore();
};
inline GameManager gameManager;