#ifndef FOTH_H
#define FOTH_H

#include "Game.h"
#include "FothScreen.h"
#include "ResourceManager.h"

class Foth : public Game
{
    public:
        Foth(sf::RenderWindow& window, FothScreen& virtualScreen,
             ResourceManager& manager);

    private:
        void event(sf::Event event);
        void draw();

        sf::Sprite testSprite;
};

#endif
