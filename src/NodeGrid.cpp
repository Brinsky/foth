#include "NodeGrid.h"

#include <iostream>

using namespace foth;

NodeGrid::NodeGrid(int pixelsPerNode, ResourceManager& manager, int height, 
                   int width) :
    PIXELS_PER_NODE(pixelsPerNode),
    grassSprite(manager, "grassTile", true)
{
	this->width = width;
	this->height = height;

	// Apply the level's width to the first dimension
	grid.resize(width);

	// Apply the level's height to the second dimension
	for (auto x = grid.begin(); x != grid.end(); ++x)
	{
		x->resize(height);
	}
	// Nodes can now be accessed through "grid[x][y]"
}

NodeGrid::~NodeGrid()
{

}

/// Determines the routing of a given heading for the Node at a given location.
/// Returns the opposite heading if a Node is not defined at that location.
heading NodeGrid::routeHeading(int nodeX, int nodeY, heading incoming)
{
	// If the node is in the grid, and if the node is not null
	if(nodeExists(nodeX, nodeY)) 
	{
		// Determine the proper routing through the node
		switch (incoming)
		{
			case North:
				return grid[nodeX][nodeY]->northTo;
			case East:
				return grid[nodeX][nodeY]->eastTo;
			case South:
				return grid[nodeX][nodeY]->westTo;
			case West:
				return grid[nodeX][nodeY]->southTo;
		}
	}
	else // Default node behavior, assumed for nonexistant nodes
	{
		// Simply get the opposite heading
		return flipHeading(incoming);
	}
}

/// Determines the material of the Node at a given location. Returns Grass
/// if a Node is not defined at that location.
material NodeGrid::getMaterial(int nodeX, int nodeY)
{
	if (nodeExists(nodeX, nodeY))
		return grid[nodeX][nodeY]->material;
	else
		return Grass;
}

/// If the given coordinates are in bounds, a Node is established there with the
/// specified properties. Returns false if the Node is not within bounds.
bool NodeGrid::setNode(int x, int y, foth::heading northTo,
                       foth::heading eastTo, foth::heading southTo,
                       foth::heading westTo, foth::material material)
{
    if (inBounds(x, y))
    {
        // Create a new Node and move it into the grid
        std::unique_ptr<Node> node(new Node);
        node->northTo = northTo;
        node->eastTo = eastTo;
        node->southTo = southTo;
        node->westTo = westTo;
        node->material = material;

        grid[x][y] = std::move(node);

        return true;
    }
    else
        return false;    
}

void NodeGrid::draw(VirtualScreen& screen)
{
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            if (getMaterial(x, y) == foth::Grass)
            {
                screen.worldDraw(grassSprite, sf::Vector2f(x, y));
            }
        }
    }
}

/// Determines whether or not a Node is in bounds and truly exists (is
/// non-default) at a given location
bool NodeGrid::nodeExists(int x, int y)
{
	// Checks if coordinates could be valid
	// If so, checks if a defined Node exists at those coordinates
	return inBounds(x, y) && grid[x][y];
}

/// Determines whether or not a Node is within bounds
bool NodeGrid::inBounds(int x, int y)
{
	return x >= 0 && x < width && y >= 0 && y < height;
}
