#include "Game.hpp"
#include "Drawing.hpp"
int main()
{

    while (sfmlObjects.getWindow()->isOpen())
    {
        sf::Event event;
        while (sfmlObjects.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sfmlObjects.getWindow()->close();
        }

        if (!game.hasStarted() && game.isOneOfTheseKeysPressed(game.startingKeys))
        {
            game.startGame();
        }

        if(game.hasStarted())
        {
            // MAIN GAME LOGIC
            
            //get user input ( direction of snake )
            if (game.isOneOfTheseKeysPressed(game.upKeys))
                game.snake.setDirection(Snake::UP);
            else if (game.isOneOfTheseKeysPressed(game.leftKeys))
                game.snake.setDirection(Snake::LEFT);
            else if (game.isOneOfTheseKeysPressed(game.rightKeys))
                game.snake.setDirection(Snake::RIGHT);
            else if (game.isOneOfTheseKeysPressed(game.downKeys))
                game.snake.setDirection(Snake::DOWN);

            // move snake 

            if (sfmlObjects.getClock()->getElapsedTime() > game.getFrameInterval())
            {
                game.snake.moveSnake();

                //reset clock
                sfmlObjects.getClock()->restart();
            }
         
        }

        draw();
    }

    return 0;
}