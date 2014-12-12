#include "NodeGrid.h"
#include <iostream>
#include <typeinfo>

using namespace foth;

int main()
{
	NodeGrid grid(7, 20);
}

NodeGrid::NodeGrid(int width, int height)
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

/// Determines the routing of a given heading for the Node at a given location./// Returns the opposite heading if a Node is not defined at that location.
heading NodeGrid::routeHeading(int nodeX, int nodeY, heading incoming)
{
	// If the node is in the grid, and if the node is not null
	if (nodeX >= 0 && nodeX < width
		&& nodeY >= 0 && nodeY < height
		&& grid[nodeY][nodeX])
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

/// Determines whether or not a Node exists at a given location
bool NodeGrid::nodeExists(int nodeX, int nodeY)
{
	// Checks if coordinates could be valid
	// If so, checks if a defined Node exists at those coordinates
	return nodeX >= 0 && nodeX < width
		&& nodeY >= 0 && nodeY < height
		&& grid[nodeY][nodeX];
}
