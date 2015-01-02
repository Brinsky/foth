#include "MaterialGrid.h"

MaterialGrid::MaterialGrid(int width, int height, ResourceManager& manager) : 
    Grid(width, height), 
    grassSprite(manager, "grassTile", true),
    stoneSprite(manager, "stoneTile", true)
{
}

void MaterialGrid::draw(VirtualScreen& screen)
{
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            switch (getNode(x, y))
            {
                case foth::grass:
                    screen.worldDraw(grassSprite, sf::Vector2f(x, y));
                    break;
                case foth::stone:
                    screen.worldDraw(stoneSprite, sf::Vector2f(x, y));
                    break;
            }
        }
    }
} 

