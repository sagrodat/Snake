#include "Assets.hpp"

#include <iostream>

Assets::Assets()
{
	loadAssets();
}

void Assets::loadAssets()
{
	//TEXT
	arcadeFont.font.loadFromFile(arcadeFont.path);

	currentScore.text.setFont(arcadeFont.font);
	currentScore.text.setCharacterSize(2 * sfmlObjects.getWindowHeight() / Board::getNumberOfRows());
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

	appleIcon.texture.loadFromFile(appleIcon.path);
	appleIcon.sprite.setTexture(appleIcon.texture);
	appleIcon.sprite.setScale(appleIcon.scale);
	appleIcon.sprite.setPosition(appleIcon.position);

	endGameBackground.rectangle.setFillColor(assets.endGameBackground.color);
	endGameBackground.rectangle.setSize(assets.endGameBackground.size);
	endGameBackground.rectangle.setPosition(assets.endGameBackground.position);
}


void Assets::updateScoreValues(int actualScore, int highScore)
{
	currentScore.text.setString(std::to_string(actualScore));

	bestScore.text.setString(std::to_string(highScore));

}
sf::Sprite Assets::getTrophyIcon() { return trophyIcon.sprite; }
sf::Sprite Assets::getAppleIcon() { return appleIcon.sprite; }

sf::Text Assets::getCurrentScore() { return bestScore.text; }
sf::Text Assets::getBestScore() { return currentScore.text; }

sf::RectangleShape Assets::getEndGameBackground() { return endGameBackground.rectangle; }