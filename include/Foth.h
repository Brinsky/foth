#ifndef FOTH_H
#define FOTH_H

#include "Game.h"
#include "FothScreen.h"

class Foth : public Game
{
    public:
        Foth(sf::RenderWindow& window, FothScreen& virtualScreen);
};

#endif
