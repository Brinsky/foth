#ifndef NODEGRID_H
#define NODEGRID_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Properties.h"
#include "ResourceManager.h"
#include "CenteredSprite.h"

/// A collection of node data which represents the contents of a FOTH level
class NodeGrid
{
	public:
		NodeGrid(int pixelsPerNode, ResourceManager& manager, int height,
                 int width = 7);
		~NodeGrid();

		foth::heading routeHeading(int x, int y,
			foth::heading incoming);
		foth::material getMaterial(int x, int y);

        bool setNode(int x, int y, foth::heading northTo,
                     foth::heading eastTo, foth::heading southTo,
                     foth::heading westTo, foth::material material);

        void draw(sf::RenderTarget& target);

	private:
        CenteredSprite grassSprite;

		/// Used to easily store the properties of defined nodes
		typedef struct Node
		{
			foth::heading northTo;
			foth::heading eastTo;
			foth::heading southTo;
			foth::heading westTo;

			foth::material material;
		} Node;
		
		bool nodeExists(int x, int y);
        bool inBounds(int x, int y);
        
		int width;
		int height;

		/// A 2D vector of (pointers to) Nodes
		std::vector<std::vector<std::unique_ptr<Node>>> grid;

        const int PIXELS_PER_NODE;
};

#endif
