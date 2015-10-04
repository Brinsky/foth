#ifndef MATERIALGRID_H
#define MATERIALGRID_H

#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "Properties.h"
#include "ResourceManager.h"
#include "VirtualScreen.h"

class MaterialGrid : public Grid <foth::Material, foth::grass>
{
    public:
        MaterialGrid(int width, int height, ResourceManager& manager);
        void draw(VirtualScreen& screen);
    private:
    sf::Sprite grassSprite;
    sf::Sprite stoneSprite;
};

#endif
