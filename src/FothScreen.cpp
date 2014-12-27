#include "FothScreen.h"

FothScreen::FothScreen(unsigned int width, unsigned int height,
                                     unsigned int pixelsPerNode) :
        PIXELS_PER_NODE(pixelsPerNode)
{
    create(width, height);
}

/// Properly renders a sprite at the given world coordinates (i.e. 
/// NodeGrid-based)
void FothScreen::draw(sf::Sprite& sprite,
                             const sf::Vector2f& worldPosition)
{
    // We don't care about the sprite's old position, but we should leave it
    // as we found it once we finish
    const sf::Vector2f& oldPosition = sprite.getPosition();
    
    // Convert the world coordinates to pixel coordinates
    sprite.setPosition(getPixelPosition(worldPosition));

    // Draw the sprite on our RenderTexture
    RenderTexture::draw(sprite);

    sprite.setPosition(oldPosition);
}

/// Converts a given game-world position and converts it into a pixel-based
/// position
sf::Vector2f FothScreen::getPixelPosition(
        const sf::Vector2f& worldPosition)
{
    return sf::Vector2f(worldPosition.x * PIXELS_PER_NODE,
                        -(worldPosition.y * PIXELS_PER_NODE) + height);
}
