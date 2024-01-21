#pragma once
#include "SFML/Graphics.hpp"
#include "SFMLObjects.hpp"
#include "Board.hpp"
#include "ResourcesPath.hpp"

class Assets
{
public:
	Assets();
private :

	///////////////// IMAGES TO DRAW ////////////////////////
	struct {
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = resourcesPath.concatenate("textures\\trophy.png");
		sf::Vector2f scale = sf::Vector2f(0.2, 0.2);
		sf::Vector2f position = sf::Vector2f(450, 310);
	}trophyIcon;

	struct {
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = resourcesPath.concatenate("textures\\apple.png");
		sf::Vector2f scale = sf::Vector2f(0.03, 0.03);
		sf::Vector2f position = sf::Vector2f(300, 300);
	}appleIconEndGame;

	struct {
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = resourcesPath.concatenate("textures\\apple.png");
		sf::Vector2f scale = sf::Vector2f(0.015, 0.015);
		sf::Vector2f position = sf::Vector2f(0, 0);
	}appleIconScore;

	struct {
		sf::Color color = sf::Color(0, 0, 255);
		sf::Vector2f position = sf::Vector2f(200, 200);
		sf::Vector2f size = sf::Vector2f(400, 400);
		sf::RectangleShape rectangle;
	}endGameBackground;


	////////////////////// BUTTONS ////////////////////////

	struct startNewGameButtonInfo {
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = resourcesPath.concatenate("textures\\playButton.png");
		sf::Vector2f position = sf::Vector2f(300, 500);
	}startNewGameButtonInfo;

	////////////////////// TEXT //////////////////////////

	struct {
		sf::Font font;
		std::string path = resourcesPath.concatenate("fonts\\ARCADECLASSIC.TTF");
	}arcadeFont;
	
	struct {
		sf::Text text;
		sf::Color color = sf::Color(sf::Color::White);
		sf::Vector2f position = sf::Vector2f(300, 350);
	}currentScoreEndGame;

	struct {
		sf::Text text;
		sf::Color color = sf::Color(sf::Color::Black);
		sf::Vector2f position = sf::Vector2f(25, -11);
	}currentScore;

	struct {
		sf::Text text;
		sf::Color color = sf::Color(sf::Color::White);
		sf::Vector2f position = sf::Vector2f(450, 350);
	}bestScore;

	

	////////////////////////////////////////////////////////////
	
public :
	sf::Sprite getTrophyIcon();
	sf::Sprite getAppleIconEndGame();
	sf::Sprite getAppleIconScore();

	sf::Text getCurrentScore();
	sf::Text getCurrentScoreEndGame();
	sf::Text getBestScore();

	void updateHighScoreText(int score);
	void updateCurrentScoreTexts(int score);

	struct startNewGameButtonInfo getStartNewGameButton() { return startNewGameButtonInfo; }
	
	sf::RectangleShape getEndGameBackground();

private :
	void loadAssets();
};
inline Assets assets;
