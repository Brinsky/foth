#include "FothScreen.h"

FothScreen::FothScreen(unsigned int width, unsigned int height,
                       unsigned int pixelsPerNode) :
        VirtualScreen(width, height),
        PIXELS_PER_NODE(pixelsPerNode)
{
    this->width = width;
    this->height = height;
}

/// Converts a given game-world position and converts it into a pixel-based
/// position
sf::Vector2f FothScreen::getPixelPosition(const sf::Vector2f& worldPosition)
{
    return sf::Vector2f((worldPosition.x + 0.5) * PIXELS_PER_NODE,
                        -((worldPosition.y + 0.5) * PIXELS_PER_NODE) + height);
}
