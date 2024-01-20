#pragma once
#include "SFML/Graphics.hpp"
class Button
{
public :
	Button(sf::Vector2f position, std::string textureFilePath);
private :
	sf::Texture texture;
	sf::Sprite sprite;
	
public :
	template <typename T>
	bool contains(sf::Vector2<T> vec);

	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	sf::Vector2f getSize();
};