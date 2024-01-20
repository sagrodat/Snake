#include "Game.hpp"
#include "Drawing.hpp"
//TO DO 
//buttons 
// difficulty levels ? 
//color change
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

            // wait one full frame
            // this is done so the snake starts moving in the way its drawn,
            // no matter what direction user chooses to start with
            if (sfmlObjects.getClock()->getElapsedTime() > game.getFrameInterval())
            {
                sfmlObjects.getClock()->restart();
            }
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

            // if time to crate next frame 
            if (sfmlObjects.getClock()->getElapsedTime() > game.getFrameInterval())
            {
                game.snake.moveSnake();

                // check for end of game
                if (game.snake.isPositionIllegal())
                    game.endGame();

                // check if snake ate the fruit
                if (game.snakeCapturedFruit())
                {
                    game.snake.increaseLength();
                    game.increaseScore();
                    game.increaseSpeed();

                    //generate fruit until it's in a legal position
                    //cant be generated inside snake ( low chance )
                    do {
                        game.fruits.generateFruit();
                    } while (game.fruitGeneratedInsideSnake());
                }
                   
                //reset clock
                sfmlObjects.getClock()->restart();
            }
            

         
        }

        draw();
    }

    return 0;
}