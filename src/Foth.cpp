#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "GameState.h"

const int DEFAULT_SCREEN_WIDTH = 448;
const int DEFAULT_SCREEN_HEIGHT = 640;

int main()
{
    sf::RenderWindow window(sf::VideoMode(DEFAULT_SCREEN_WIDTH, 
         DEFAULT_SCREEN_HEIGHT), "foth");

    Game game(window);

    game.loop();

    return 0;
}
