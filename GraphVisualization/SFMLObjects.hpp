#pragma once

#include "SFML/Graphics.hpp"
class SFMLObjects {
public :
	SFMLObjects();
private :
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 800;
	sf::RenderWindow * window;
	sf::Clock* clock;
	
public :
	sf::RenderWindow * getWindow();
	const int getWindowHeight();
	const int getWindowWidth();
	sf::Clock* getClock();
};
inline SFMLObjects sfmlObjects;