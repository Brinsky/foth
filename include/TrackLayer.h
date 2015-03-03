#include "Properties.h"
#include "TrackGrid.h"

class TrackLayer
{
    public:
        TrackLayer(int x, int y, TrackGrid& a_trackGrid,
                   foth::Heading reverse);
        bool move(foth::Heading heading);

    private:
        int x;
        int y;
    
        // The heading opposite that of the last movement. Used for back-
        // tracking and updating the orientations of previous pieces
        foth::Heading reverse;

        TrackGrid& trackGrid;

};
