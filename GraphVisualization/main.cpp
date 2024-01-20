#include "GameManager.hpp"
#include "Drawing.hpp"
//TO DO 
//buttons 
// difficulty levels ? 
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


        if (game->hasStarted() == false)
        {
            sf::Keyboard::Key * pressedKey = game->getWhichKeyIsPressed(game->startingKeys);
            if (pressedKey != NULL)
            {
                //only start game if player is trying to move in the 3/4 possible directions 
                //(not into the snake itself)
                if (game->getDirectionOfKey(*pressedKey) != game->snake.reversedDirection(game->snake.getDirection()))
                {
                    game->startGame();
                    game->snake.setDirection(game->getDirectionOfKey(*pressedKey));
                }
                
            }
        }

        if(game->hasStarted())
        {
            // MAIN GAME LOGIC
            
            //keep getting user input ( direction of snake )
            if (game->isOneOfTheseKeysPressed(game->upKeys) && !game->snake.willTurnBackwards(Snake::UP))
                game->snake.setDirection(Snake::UP);
            else if (game->isOneOfTheseKeysPressed(game->leftKeys) && !game->snake.willTurnBackwards(Snake::LEFT))
                game->snake.setDirection(Snake::LEFT);
            else if (game->isOneOfTheseKeysPressed(game->rightKeys) && !game->snake.willTurnBackwards(Snake::RIGHT))
                game->snake.setDirection(Snake::RIGHT);
            else if (game->isOneOfTheseKeysPressed(game->downKeys) && !game->snake.willTurnBackwards(Snake::DOWN))
                game->snake.setDirection(Snake::DOWN);

            // if time to crate next frame 
            if (sfmlObjects.getClock()->getElapsedTime() > game->getFrameInterval())
            {
                game->snake.moveSnake();

                // check for end of game
                if (game->snake.isPositionIllegal())
                {
                    gameManager.updateHighScore();
                    game->endGame();
                }
               
                // check if snake ate the fruit
                if (game->snakeCapturedFruit())
                {
                    game->snake.increaseLength();
                    game->increaseScore();
                    game->increaseSpeed();

                    //generate fruit until it's in a legal position
                    //cant be generated inside snake ( low chance )
                    do {
                        game->fruits.generateFruit();
                    } while (game->fruitGeneratedInsideSnake());
                }
                   
                //reset clock
                sfmlObjects.getClock()->restart();
            }
        }
        draw();
    }
    return 0;
}