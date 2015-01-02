#ifndef NODEGRID_H
#define NODEGRID_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Properties.h"
#include "ResourceManager.h"
#include "ManagedSprite.h"
#include "VirtualScreen.h"

/// A collection of node data which represents the contents of a FOTH level
class NodeGrid
{
	public:
		NodeGrid(int pixelsPerNode, ResourceManager& manager, int height,
                 int width = 7);
		~NodeGrid();

		foth::Heading routeHeading(int x, int y,
			foth::Heading incoming);
		foth::Material getMaterial(int x, int y);

        bool setNode(int x, int y, foth::Material material);
        bool setNode(int x, int y, foth::Heading northTo,
                     foth::Heading eastTo, foth::Heading southTo,
                     foth::Heading westTo, foth::Material material);

        void draw(VirtualScreen& screen);

	private:
        ManagedSprite grassSprite;
        ManagedSprite stoneSprite;

		/// Used to easily store the properties of defined nodes
		typedef struct Node
		{
			foth::Heading northTo;
			foth::Heading eastTo;
			foth::Heading southTo;
			foth::Heading westTo;

			foth::Material material;
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
