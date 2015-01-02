#include "Properties.h"

namespace foth
{
	heading flipHeading(heading incoming)
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
