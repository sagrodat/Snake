#include "Snake.hpp"

Snake::Snake()
{
	//random seed
	srand(time(NULL));

	//allocate memory for vector
	snakeElements = new std::vector<sf::RectangleShape>;

	//create and add head object
	sf::RectangleShape head;
	head.setFillColor(headColor);
	head.setSize(sf::Vector2f(Board::getFieldWidth(), Board::getFieldHeight()));
	snakeElements->push_back(head);


	//get and set starting position of head
	generateAndSetHeadStartingPosition();

	//create and add body objects
	int direction = rand() % 4;
	for (int i = 0; i < startingTotalLength - 1; i++)
	{
		sf::RectangleShape bodyElement;
		bodyElement.setFillColor(bodyColor);
		bodyElement.setSize(sf::Vector2f(Board::getFieldWidth(), Board::getFieldHeight()));

		//set position of the body based on generated direction
		sf::Vector2f position = snakeElements->at(i).getPosition();
		switch (direction)
		{
		case LEFT :
			position.x -= Board::getFieldWidth();
			break;
		case UP :
			position.y -= Board::getFieldHeight();
			break;
		case RIGHT :
			position.x += Board::getFieldWidth();
			break;
		case DOWN :
			position.y += Board::getFieldHeight();
			break;
		default :
			break;
		}
		bodyElement.setPosition(position);

		snakeElements->push_back(bodyElement);
	}


}

void Snake::generateAndSetHeadStartingPosition()
{
	int headPosX = startingTotalLength + rand()%( Board::getNumberOfColumns() - 2* startingTotalLength);
	int headPosY = startingTotalLength + rand()%( Board::getNumberOfRows() - 2*startingTotalLength);
	headPosX*= Board::getFieldWidth();
	headPosY *= Board::getFieldHeight();
	setHeadPosition(sf::Vector2f(headPosX, headPosY));
}

sf::Vector2f Snake::getHeadPosition()
{
	return snakeElements->at(SNAKE_HEAD_ID).getPosition();
}

void Snake::setHeadPosition(sf::Vector2f vec)
{
	snakeElements->at(SNAKE_HEAD_ID).setPosition(vec);
}

std::vector<sf::RectangleShape>* Snake::getSnakeElements() { return snakeElements; }

void Snake::setDirection(int direction) { this->direction = direction;}
int Snake::getDirection() { return direction; }

void Snake::moveSnake()
{
	// make body follow head
	for (int i = snakeElements->size() - 1; i > 0; --i) // 1 cause SNAKE_HEAD_ID == 0
	{
		snakeElements->at(i).setPosition( snakeElements->at(i- 1).getPosition() );
	}


	// update head position
	sf::Vector2f toBeNewHeadPosition = snakeElements->at(SNAKE_HEAD_ID).getPosition();

	switch (direction)
	{
	case UP:
		toBeNewHeadPosition.y -= Board::getFieldHeight();
		break;
	case LEFT:
		toBeNewHeadPosition.x -= Board::getFieldWidth();
		break;
	case RIGHT:
		toBeNewHeadPosition.x += Board::getFieldWidth();
		break;
	case DOWN:
		toBeNewHeadPosition.y += Board::getFieldHeight();
		break;
	default:
		break;
	}
	snakeElements->at(SNAKE_HEAD_ID).setPosition(toBeNewHeadPosition);

}