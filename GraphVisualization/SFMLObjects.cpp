#include "SFMLObjects.hpp"
SFMLObjects::SFMLObjects()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake game", sf::Style::Titlebar | sf::Style::Close);
	clock = new sf::Clock;
}

sf::RenderWindow * SFMLObjects::getWindow() { return window;}
sf::Clock* SFMLObjects::getClock() { return clock; }
const int SFMLObjects::getWindowHeight() { return WINDOW_HEIGHT; }
const int SFMLObjects::getWindowWidth() { return WINDOW_WIDTH; }