#ifndef FOTH_H
#define FOTH_H

#include "Game.h"

class Foth : public Game
{
    public:
        Foth(sf::RenderWindow& window);

    private:
        void event(sf::Event event);
};

#endif
