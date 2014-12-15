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

	heading flipHeading(heading incoming);
}

#endif
