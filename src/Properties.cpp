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
			default:
				return north;
		}
	}

    /// Returns a valid track piece based on the orientation of its two ends
    Track trackOrientation(Heading a, Heading b)
    {
        switch (a)
        {
            case north:
                switch (b)
                {
                    case north:
                        return none; // Invalid case, return foth::none
                    case east:
                        return northEast;
                    case south:
                        return northSouth;
                    case west:
                        return northWest;
                }
                break;

            case east:
                switch (b)
                {
                    case north:
                        return northEast;
                    case east:
                        return none; // Invalid case, return foth::none
                    case south:
                        return southEast;
                    case west:
                        return eastWest;
                }
                break;

            case south:
                switch (b)
                {
                    case north:
                        return northSouth;
                    case east:
                        return southEast;
                    case south:
                        return none; // Invalid case, return foth::none
                    case west:
                        return southWest;
                }
                break;

            case west:
                switch (b)
                {
                    case north:
                        return northWest;
                    case east:
                        return eastWest;
                    case south:
                        return southWest;
                    case west:
                        return none; // Invalid case, return foth::none
                }
                break;

            // This should never, ever happen
            default:
                return none;
        }

		return none;

    }
}
