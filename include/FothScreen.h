#ifndef FOTHSCREEN_H
#define FOTHSCREEN_H

#include <SFML/Graphics.hpp>

class FothScreen : public sf::RenderTexture
{
    public:
        FothScreen(unsigned int width, unsigned int height,
                         unsigned int pixelsPerNode);
        void draw(sf::Sprite& sprite, const sf::Vector2f& worldPosition);

    private:
        sf::Vector2f getPixelPosition(
                const sf::Vector2f& worldPosition);

        const unsigned int PIXELS_PER_NODE;
        unsigned int width;
        unsigned int height;
};

#endif
