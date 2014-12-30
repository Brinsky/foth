#ifndef FOTHSCREEN_H
#define FOTHSCREEN_H

#include "VirtualScreen.h"

class FothScreen : public VirtualScreen
{
    public:
        FothScreen(unsigned int width, unsigned int height,
                   unsigned int pixelsPerNode);

    private:
        sf::Vector2f getPixelPosition(const sf::Vector2f& worldPos);

        const unsigned int PIXELS_PER_NODE;
        unsigned int height;
        unsigned int width;
};

#endif
