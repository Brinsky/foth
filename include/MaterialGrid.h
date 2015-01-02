#ifndef MATERIALGRID_H
#define MATERIALGRID_H

#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "Properties.h"
#include "ResourceManager.h"
#include "ManagedSprite.h"
#include "VirtualScreen.h"

class MaterialGrid : public Grid <foth::Material, foth::grass>
{
    public:
        MaterialGrid(int width, int height, ResourceManager& manager);
        void draw(VirtualScreen& screen);
    private:
        ManagedSprite grassSprite;
        ManagedSprite stoneSprite;
};

#endif
