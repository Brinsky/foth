#include "Properties.h"

namespace foth
{
	heading flipHeading(heading incoming)
	{
		switch (incoming)
		{
			case North:
				return South;
			case East:
				return West;
			case South:
				return North;
			case West:
				return East;
		}
	}
}
