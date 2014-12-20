#include "Foth.h"

#include <memory>
#include <SFML/Graphics.hpp>

#include "PlayLevelState.h"

const int DEFAULT_SCREEN_WIDTH = 448;
const int DEFAULT_SCREEN_HEIGHT = 640;

int main()
{
    sf::RenderWindow window(sf::VideoMode(DEFAULT_SCREEN_WIDTH, 
         DEFAULT_SCREEN_HEIGHT), "foth");

    Foth foth(window);

    // Begin playing the level
    foth.pushState(std::unique_ptr<GameState>(new PlayLevelState(foth)));

    foth.loop();

    return 0;
}

Foth::Foth(sf::RenderWindow& window) : Game(window) { }

void Foth::event(sf::Event event)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    else if (event.type == sf::Event::Resized)
    {
        // Maintains correct aspect ratio
        // Might not always work!
        //sf::Vector2u newSize = window.getSize();
        //newSize.x = int (newSize.y / 10) * 7;
        //window.setSize(newSize);
    }
}
