#include "Foth.h"

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "ResourceManager.h"
#include "PlayLevelState.h"

const int SCREEN_WIDTH = 448;
const int SCREEN_HEIGHT = 640;

const int PIXELS_PER_NODE = 64;

int main()
{
    ResourceManager manager("res/resources.txt");

    if (!manager)
    {
        std::cout << "Resource Manager: Error opening files." << std::endl;
        return -1;
    }

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), 
                            "foth");

    // In order to deal with aspect ratio consistency and the conversion from
    // game coordinates to pixel coordinates, we create a virtual screen and
    // render to that, then apply it to the main window as a sprite
    FothScreen virtualScreen(SCREEN_WIDTH, SCREEN_HEIGHT, PIXELS_PER_NODE);

    Foth foth(window, virtualScreen);

    // Begin playing the level
    foth.pushState(std::unique_ptr<GameState>(new PlayLevelState(foth, 64, 
                                                                 manager)));

    foth.loop();

    return 0;
}

Foth::Foth(sf::RenderWindow& window, FothScreen& virtualScreen) :
    Game(window, virtualScreen)
{

}
