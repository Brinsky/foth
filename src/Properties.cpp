#include "Properties.h"

namespace foth
{
	Heading flipHeading(Heading incoming)
	{
		switch (incoming)
		{
			case north:
				return south;
			case east:
				return west;
			case south:
				return north;
			case west:
				return east;
		}
	}
}
