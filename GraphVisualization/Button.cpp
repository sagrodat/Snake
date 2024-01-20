#include "Button.hpp"

Button::Button(sf::Vector2f position, std::string textureFilePath) 
{
	texture.loadFromFile(textureFilePath);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}




template bool Button::contains<int>(sf::Vector2<int>);
template bool Button::contains<float>(sf::Vector2<float>);
template bool Button::contains<unsigned int>(sf::Vector2<unsigned int>);
template <typename T>
bool Button::contains(sf::Vector2<T> vec)
{
	sf::Vector2f buttonPos = getPosition();
	sf::Vector2f buttonSize = getSize();
	if (vec.x > buttonPos.x &&
		vec.x < buttonPos.x + buttonSize.x &&
		vec.y > buttonPos.y &&
		vec.y < buttonPos.y + buttonSize.y)
		return true;
	return false;
}


sf::Vector2f Button::getPosition() { return sprite.getPosition(); }
void Button::setPosition(sf::Vector2f vec) { sprite.setPosition(vec); }

sf::Vector2f Button::getSize() 
{ 
	sf::Vector2u buttonSize = texture.getSize();
	return sf::Vector2f(buttonSize.x, buttonSize.y);
}

sf::Sprite Button::getSprite() { return sprite; }