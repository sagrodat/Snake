#include "Assets.hpp"

#include <iostream>

Assets::Assets()
{
	loadAssets();
}

void Assets::loadAssets()
{
	arcadeFont.font.loadFromFile(arcadeFont.path);

	currentScoreEndGame.text.setFont(arcadeFont.font);
	currentScoreEndGame.text.setCharacterSize(2 * sfmlObjects.getWindowHeight() / Board::getNumberOfRows());
	currentScoreEndGame.text.setFillColor(currentScoreEndGame.color);
	currentScoreEndGame.text.setPosition(currentScoreEndGame.position);

	currentScore.text.setFont(arcadeFont.font);
	currentScore.text.setCharacterSize(sfmlObjects.getWindowHeight() / Board::getNumberOfRows());
	currentScore.text.setFillColor(currentScore.color);
	currentScore.text.setPosition(currentScore.position);


	bestScore.text.setFont(arcadeFont.font);
	bestScore.text.setCharacterSize(2 * sfmlObjects.getWindowHeight() / Board::getNumberOfRows());
	bestScore.text.setFillColor(bestScore.color);
	bestScore.text.setPosition(bestScore.position);

	trophyIcon.texture.loadFromFile(trophyIcon.path);
	trophyIcon.sprite.setTexture(trophyIcon.texture);
	trophyIcon.sprite.setScale(trophyIcon.scale);
	trophyIcon.sprite.setPosition(trophyIcon.position);

	appleIconEndGame.texture.loadFromFile(appleIconEndGame.path);
	appleIconEndGame.sprite.setTexture(appleIconEndGame.texture);
	appleIconEndGame.sprite.setScale(appleIconEndGame.scale);
	appleIconEndGame.sprite.setPosition(appleIconEndGame.position);

	appleIconScore.texture.loadFromFile(appleIconScore.path);
	appleIconScore.sprite.setTexture(appleIconScore.texture);
	appleIconScore.sprite.setScale(appleIconScore.scale);
	appleIconScore.sprite.setPosition(appleIconScore.position);

	endGameBackground.rectangle.setFillColor(assets.endGameBackground.color);
	endGameBackground.rectangle.setSize(assets.endGameBackground.size);
	endGameBackground.rectangle.setPosition(assets.endGameBackground.position);

	updateHighScoreText(0);
}



void Assets::updateCurrentScoreTexts(int score)
{
	currentScore.text.setString(std::to_string(score));
	currentScoreEndGame.text.setString(std::to_string(score));
}

void Assets::updateHighScoreText(int score)
{
	bestScore.text.setString(std::to_string(score));
}
sf::Sprite Assets::getTrophyIcon() { return trophyIcon.sprite; }
sf::Sprite Assets::getAppleIconEndGame() { return appleIconEndGame.sprite; }

sf::Text Assets::getCurrentScore() {return currentScore.text; }
sf::Text Assets::getCurrentScoreEndGame() { return currentScoreEndGame.text; }
sf::Text Assets::getBestScore() { return bestScore.text; }

sf::Sprite Assets::getAppleIconScore() { return appleIconScore.sprite; }

sf::RectangleShape Assets::getEndGameBackground() { return endGameBackground.rectangle; }