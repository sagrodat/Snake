#pragma once
#include "SFML/Graphics.hpp"
#include "SFMLObjects.hpp"
#include "Board.hpp"

class Assets
{
public:
	Assets();

private :

	///////////////// IMAGES TO DRAW ////////////////////////
	struct {
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = "resources\\textures\\trophy.png";
		sf::Vector2f scale = sf::Vector2f(0.2, 0.2);
		sf::Vector2f position = sf::Vector2f(450, 300);
	}trophyIcon;

	struct {
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = "resources\\textures\\apple.png";
		sf::Vector2f scale = sf::Vector2f(0.03, 0.03);
		sf::Vector2f position = sf::Vector2f(300, 300);
	}appleIcon;


	////////////////////// BUTTONS ////////////////////////

	struct startNewGameButtonInfo {
		sf::Sprite sprite;
		sf::Texture texture;
		std::string path = "resources\\textures\\playButton.png";
		sf::Vector2f position = sf::Vector2f(300, 500);
	}startNewGameButtonInfo;

	////////////////////// TEXT //////////////////////////

	struct {
		sf::Font font;
		std::string path = "resources\\fonts\\ARCADECLASSIC.TTF";
	}arcadeFont;
	
	struct {
		sf::Text text;
		sf::Color color = sf::Color(sf::Color::White);
		sf::Vector2f position = sf::Vector2f(300, 350);
	}currentScore;

	struct {
		sf::Text text;
		sf::Color color = sf::Color(sf::Color::White);
		sf::Vector2f position = sf::Vector2f(450, 350);
	}bestScore;
	
public :
	sf::Sprite getTrophyIcon();
	sf::Sprite getAppleIcon();

	sf::Text getCurrentScore();
	sf::Text getBestScore();

	void updateScoreValues(int actualScore, int highScore);

	struct startNewGameButtonInfo getStartNewGameButton() { return startNewGameButtonInfo; }
	
private :
	void loadAssets();
	void adjustAssets();

	
};
inline Assets assets;
