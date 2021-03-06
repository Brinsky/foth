#ifndef TRACKGRID_H
#define TRACKGRID_H

#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "Properties.h"
#include "ResourceManager.h"
#include "SpriteSheet.h"
#include "VirtualScreen.h" 

class TrackGrid : public Grid <foth::Track, foth::none>
{
    public:
        TrackGrid(int width, int height, ResourceManager& manager);
        void draw(VirtualScreen& screen);
        foth::Heading routeHeading(int x, int y, foth::Heading incoming);

    private:
        SpriteSheet track;
};

#endif
