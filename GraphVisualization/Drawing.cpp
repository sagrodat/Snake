#include "Game.hpp"

void draw()
{

	//CLEAR OLD FRAME
	sfmlObjects.getWindow()->clear();

	
	//draw background
	for (int r = 0; r < game.board.getNumberOfRows(); r++)
	{
		for (int c = 0; c < game.board.getNumberOfColumns(); c++)
		{
			sfmlObjects.getWindow()->draw(game.board.getBackgroundFields()[r][c]);
		}
	}

	//draw snake
	for (int i = 0; i < game.snake.getSnakeElements()->size(); i++)
	{
		sfmlObjects.getWindow()->draw(game.snake.getSnakeElements()->at(i));
	}

	//DISPLAY NEW FRAME
	sfmlObjects.getWindow()->display();
}