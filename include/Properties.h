#ifndef FOTH_PROPERTIES_H
#define FOTH_PROPERTIES_H

namespace foth
{
	enum Heading
	{
		north,
		east,
		south,
		west
	};

	enum Material
	{
		grass,
        stone
	};

    enum Track
    {
        none,
        northSouth,
        eastWest,
        northEast,
        southEast,
        northWest,
        southWest
    };

	Heading flipHeading(Heading incoming);
}

#endif
