#ifndef NODEGRID_H
#define NODEGRID_H

#include <vector>
#include <memory>

#include "Properties.h"

/// A collection of node data which represents the contents of a FOTH level
class NodeGrid
{
	public:
		NodeGrid(int height, int width);
		~NodeGrid();
		foth::heading routeHeading(int x, int y,
			foth::heading incoming);
		foth::material getMaterial(int x, int y);

	private:
		/// Used to easily store the properties of defined nodes
		typedef struct Node
		{
			foth::heading northTo;
			foth::heading eastTo;
			foth::heading southTo;
			foth::heading westTo;

			foth::material material;
		} Node;
		
		bool nodeExists(int nodeX, int nodeY);

		int width;
		int height;

		/// A 2D vector of (pointers to) Nodes
		std::vector<std::vector<std::unique_ptr<Node>>> grid;
};

#endif
