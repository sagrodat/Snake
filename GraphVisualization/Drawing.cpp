#include "GameManager.hpp"

void draw()
{
    // CLEAR OLD FRAME
    sfmlObjects.getWindow()->clear();

    // draw background
    for (int r = 0; r < game->board.getNumberOfRows(); r++)
    {
        for (int c = 0; c < game->board.getNumberOfColumns(); c++)
        {
            sfmlObjects.getWindow()->draw(game->board.getBackgroundFields()[r][c]);
        }
    }

    // draw snake
    for (int i = 0; i < game->snake.getSnakeElements()->size(); i++)
    {
        sfmlObjects.getWindow()->draw(game->snake.getSnakeElements()->at(i));
    }

    // draw fruit
    sfmlObjects.getWindow()->draw(game->fruits.getFruit());

    // DISPLAY NEW FRAME
    sfmlObjects.getWindow()->display();
}

void drawEndGameScreen()
{
    // don't clear, just add what is needed to be drawn on top

    // background plane
    sfmlObjects.getWindow()->draw(assets.getEndGameBackground());

    // display icons (trophy - best score, apple - current score)
    sfmlObjects.getWindow()->draw(assets.getTrophyIcon());
    sfmlObjects.getWindow()->draw(assets.getAppleIcon());

    // display score as text
    assets.updateScoreValues(game->getScore(), gameManager.getHighScore());
    sfmlObjects.getWindow()->draw(assets.getCurrentScore());
    sfmlObjects.getWindow()->draw(assets.getBestScore());

    sfmlObjects.getWindow()->draw(game->Buttons.startNewGameButton.getSprite());

    sfmlObjects.getWindow()->display();

    while (true)
    {
        if (game->Buttons.startNewGameButton.contains(
            sfmlObjects.getMouse()->getPosition(*sfmlObjects.getWindow())))
        {
            if (sfmlObjects.getMouse()->isButtonPressed(sf::Mouse::Left))
            {
                gameManager.createNextGameInstance();
                break;
            }
        }
    }
}
