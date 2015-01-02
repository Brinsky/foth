#ifndef PATHPOS_H
#define PATHPOS_H

#include "Properties.h"

// This class is implemented in a painful way and should probably be redone
/// A valid "on path" position between two nodes
class PathPos
{
    public:
        PathPos(int nearestX, int nearestY);
        PathPos(int nearestX, int nearestY, foth::Heading direction,
                double distance);
        virtual ~PathPos();

        bool moveIfAble(foth::Heading towards, double distance);
        void moveToNextNode(foth::Heading direction);
        //void moveToNearestBorder(); Might be unnecessary?
        void moveAlongAxis(double distance);

        double distToNextNode(foth::Heading direction);
        double distToNextBorder(foth::Heading direction);

        double getAbsoluteX();
        double getAbsoluteY();

    private:
        enum axis
        {
            Vertical,
            Horizontal
        };

        double getRoundRemainder(double value);
        int properRound(double value);
        double reconcile(double distance);

        axis getAxis(foth::Heading direction);
        bool isPositiveOnAxis(foth::Heading direction);
        bool inAxis(foth::Heading directionA, axis givenAxis);

        int nearestX;
        int nearestY;
        double distFromNearest;
        axis mainAxis;
};

#endif // PATHPOS_H
