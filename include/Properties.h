#ifndef FOTH_PROPERTIES_H
#define FOTH_PROPERTIES_H

namespace foth
{
	enum heading
	{
		North,
		East,
		South,
		West
	};

	enum material
	{
		Grass,
		Track
	};	

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

#endif
