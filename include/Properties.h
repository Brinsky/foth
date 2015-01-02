#ifndef FOTH_PROPERTIES_H
#define FOTH_PROPERTIES_H

namespace foth
{
	enum heading
	{
		north,
		east,
		south,
		west
	};

	enum material
	{
		grass,
        stone
	};

	heading flipHeading(heading incoming);
}

#endif
