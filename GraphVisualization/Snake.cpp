#include "Snake.hpp"

Snake::Snake()
{
	//random seed
	srand(time(NULL));

	//allocate memory for snake rectangles vector
	snakeElements = new std::vector<sf::RectangleShape>;

	//create and add head object
	sf::RectangleShape head;
	head.setFillColor(headColor);
	head.setSize(sf::Vector2f(Board::getFieldWidth(), Board::getFieldHeight()));
	snakeElements->push_back(head);

	//get and set starting position of head
	generateAndSetHeadStartingPosition();

	//create and add body objects
	startDirection = rand() % 4;
	for (int i = 0; i < startingTotalLength - 1; i++)
	{
		sf::RectangleShape bodyElement = createNextBodyElement(getReversedDirection(startDirection), i);
		snakeElements->push_back(bodyElement);
	}
	currentDirection = startDirection;
}

int Snake::getReversedDirection(int dir)
{
	int ret;
	switch (dir)
	{
	case UP :
		ret = DOWN;
		break;
	case LEFT :
		ret = RIGHT;
		break;
	case RIGHT :
		ret = LEFT;
		break;
	case DOWN :
		ret = UP;
		break;
	default :
		ret = -1;
		break;
	}
	return ret;
}

sf::RectangleShape Snake::createNextBodyElement(int snakeDirection, int snakeCurrentBodyElementID)
{
	sf::RectangleShape bodyElement;

	bodyElement.setFillColor(bodyColor);
	bodyElement.setSize(sf::Vector2f(Board::getFieldWidth(), Board::getFieldHeight()));

	//set position of the body based on generated direction
	sf::Vector2f position = snakeElements->at(snakeCurrentBodyElementID).getPosition();
	switch (snakeDirection)
	{
	case LEFT:
		position.x -= Board::getFieldWidth();
		break;
	case UP:
		position.y -= Board::getFieldHeight();
		break;
	case RIGHT:
		position.x += Board::getFieldWidth();
		break;
	case DOWN:
		position.y += Board::getFieldHeight();
		break;
	default:
		break;
	}
	bodyElement.setPosition(position);

	return bodyElement;
}


void Snake::generateAndSetHeadStartingPosition()
{
	// due to this generating method this has to be true : rows > 2 * minDistanceFromEdge
	// ( minDistanceFromEdge = startingTotalLength )
	// same condition for columns
	int headPosX = minDistanceFromEdge + rand()%( Board::getNumberOfColumns() - 2* minDistanceFromEdge);
	int headPosY = minDistanceFromEdge + rand()%( Board::getNumberOfRows() - 2* minDistanceFromEdge);
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

void Snake::setDirection(int direction) { this->currentDirection = direction;}
int Snake::getDirection() { return currentDirection; }

void Snake::moveSnake()
{
	// make body follow head
	for (int i = snakeElements->size() - 1; i > 0; --i) // 1 cause SNAKE_HEAD_ID == 0
	{
		snakeElements->at(i).setPosition( snakeElements->at(i- 1).getPosition() );
	}

	// update head position
	sf::Vector2f toBeNewHeadPosition = snakeElements->at(SNAKE_HEAD_ID).getPosition();
	
	//firstly move head in the direction the snake was drawn in
	if (getMoveNumber() == 0)
		currentDirection = startDirection;

	switch (currentDirection)
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
	
	//just a regular counter
	countMove();
}

void Snake::countMove() { moveNumber++; }
long long Snake::getMoveNumber() { return moveNumber; }

bool Snake::isPositionIllegal()
{
	//out of map bounds
	if (getHeadPosition().x >= Board::getNumberOfColumns() * Board::getFieldWidth()
		|| getHeadPosition().x < 0
		|| getHeadPosition().y >= Board::getNumberOfRows() * Board::getFieldHeight() 
		|| getHeadPosition().y < 0)
		return true;

	//head ran into body
	for (int i = 1; i < snakeElements->size(); i++)
	{
		if (snakeElements->at(SNAKE_HEAD_ID).getPosition() == snakeElements->at(i).getPosition())
			return true;
	}

	return false;
}

int Snake::getSnakeHeadID() { return SNAKE_HEAD_ID;}

void Snake::increaseLength()
{
	//calculate position differences between two last body elements
	//work out the direction in which they are positioned
	//extend the snake in that direction
	int dx = snakeElements->at(snakeElements->size() - 2).getPosition().x - snakeElements->at(snakeElements->size() - 1).getPosition().x;
	int dy = snakeElements->at(snakeElements->size() - 2).getPosition().y - snakeElements->at(snakeElements->size() - 1).getPosition().y;
	int bodyBackDirection;
	if (dx == -Board::getFieldWidth())
		bodyBackDirection = RIGHT;
	else if (dx == Board::getFieldWidth())
		bodyBackDirection = LEFT;
	else if (dy == Board::getFieldHeight())
		bodyBackDirection == DOWN;
	else if (dy == -Board::getFieldHeight())
		bodyBackDirection == UP;

	snakeElements->push_back(createNextBodyElement(bodyBackDirection, snakeElements->size() - 1));
}

