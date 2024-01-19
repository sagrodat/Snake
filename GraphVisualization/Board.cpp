#include "Board.hpp"

Board::Board()
{
	initializeStaticMemberVariables();

	//initiate background array consisting of rectangles
	backgroundFields = new sf::RectangleShape * [rows];
	for (int i = 0; i < rows; i++)
		backgroundFields[i] = new sf::RectangleShape[cols];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			backgroundFields[row][col].setSize(sf::Vector2f(fieldWidth, fieldHeight));
			backgroundFields[row][col].setPosition(sf::Vector2f(col * fieldWidth, row * fieldHeight));
			sf::Color fieldColor = (row + col) % 2 == 0 ? boardColorEven : boardColorOdd;
			backgroundFields[row][col].setFillColor(fieldColor);
		}
	}

	//initiate array which holds information on field status ( empty, snake, food )
	playingFields = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		playingFields[i] = new int[cols];
	}

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			playingFields[row][col] = EMPTY;
		}
	}
}

sf::RectangleShape** Board::getBackgroundFields() { return backgroundFields; }

//STATIC METHODS
int Board::fieldWidth;
int Board::fieldHeight;
void Board::initializeStaticMemberVariables()
{
	fieldWidth = sfmlObjects.getWindowWidth() / getNumberOfColumns();
	fieldHeight = sfmlObjects.getWindowHeight() / getNumberOfRows();
}

int Board::getNumberOfColumns() { return cols; }
int Board::getNumberOfRows() { return rows; }

int Board::getFieldWidth() { return fieldWidth; }
int Board::getFieldHeight() { return fieldHeight; }