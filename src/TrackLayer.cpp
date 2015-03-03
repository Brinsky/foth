#include "TrackLayer.h"

TrackLayer::TrackLayer(int x, int y, TrackGrid& a_trackGrid,
                       foth::Heading reverse) :
    trackGrid(a_trackGrid) // Copying reference
{
    this->x = x;
    this->y = y;
    this->reverse = reverse;
}

bool TrackLayer::move(foth::Heading heading)
{
    // The target for movement, based on the heading
    int newX = x;
    int newY = y;

    // The orientation of the new track piece to be placed
    foth::Track newPiece;

    switch (heading)
    {
        case foth::east:
            newX++;
            newPiece = foth::eastWest;
            break;
        case foth::north:
            newY++;
            newPiece = foth::northSouth;
            break;
        case foth::west:
            newX--;
            newPiece = foth::eastWest;
            break;
        case foth::south:
            newY--;
            newPiece = foth::northSouth;
            break;
    }

    // If the target position is in bounds and is empty, move to it and
    // place track
    if (trackGrid.inBounds(newX, newY))
    {
        if (trackGrid.getNode(newX, newY) == foth::none)
        {
            // Update the previous track piece's orientation to point towards
            // the new piece. Uses the OLD reverse heading.
            trackGrid.setNode(x, y, trackOrientation(heading, reverse));
        
            // Update the position and the reverse heading
            x = newX;
            y = newY;
            reverse = flipHeading(heading);
        
            // Place the new track piece
            trackGrid.setNode(x, y, newPiece);

            return true;
        }
        /* NOT QUITE RIGHT, IMPLEMENT LATER
        // If the player is back-tracking over an old piece, erase the last one
        else if (heading == reverse)
        {
            trackGrid.setNode(x, y, foth::none);

            x = newX;
            y = newY;

            // Leave the reverseHeading alone! We have effectively just gone in
            // reverse, not reoriented

            return true;
        }
        */
        else
        {
            return false;
        }
    }

    return false;
}
