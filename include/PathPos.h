#ifndef PATHPOS_H
#define PATHPOS_H

#include "Properties.h"

// This class is implemented in a painful way and should probably be redone
/// A valid "on path" position between two nodes
class PathPos
{
    public:
        PathPos(int nearestX, int nearestY);
        PathPos(int nearestX, int nearestY, foth::heading direction,
                double distance);
        virtual ~PathPos();

        bool moveIfAble(foth::heading towards, double distance);
        void moveToNextNode(foth::heading direction);
        //void moveToNearestBorder(); Might be unnecessary?
        void moveAlongAxis(double distance);

        double distToNextNode(foth::heading direction);
        double distToNextBorder(foth::heading direction);

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

        axis getAxis(foth::heading direction);
        bool isPositiveOnAxis(foth::heading direction);
        bool inAxis(foth::heading directionA, axis givenAxis);

        int nearestX;
        int nearestY;
        double distFromNearest;
        axis mainAxis;
};

#endif // PATHPOS_H
