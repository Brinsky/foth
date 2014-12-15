#include "PathPos.h"

PathPos::PathPos(int nodeX, int nodeY)
{
    this->nearestX = nodeX;
    this->nearestY = nodeY;

    mainAxis = Vertical;
    distFromNearest = 0;
}

PathPos::PathPos(int nearestX, int nearestY, foth::heading direction,
                 double distance)
{
    this->nearestX = nearestX;
    this->nearestY = nearestY;

    mainAxis = getAxis(direction);

    // We need to make sure our heading-distance is positive in order to
    // properly store it in our axis-distance format
    if (distance < 0)
    {
        direction = foth::flipHeading(direction);
        distance = -distance;
    }

    // Depending on whether the direction is positive (i.e. North for Vertical,
    // East for Horizontal) or negative, our axial distance will be negated.
    if (isPositiveOnAxis(direction))
        // Ensure distance is within [-0.5, 0.5)
        distFromNearest = reconcile(distance);
    else
        // Ensure distance is within [-0.5, 0.5)
        distFromNearest = reconcile(-distance);
}

PathPos::~PathPos()
{
    //dtor
}

/// Moves in a given direction if the position is aligned with the proper axis.
/// Returns false otherwise.
bool PathPos::moveIfAble(foth::heading towards, double distance)
{
    // Fail if we are not aligned with the axis in question
    if (distance > 0 && !inAxis(towards, mainAxis))
        return false;

    // We need to make sure the heading-distance is positive for movement
    // calculations to work properly
    if (distance < 0)
    {
        towards = foth::flipHeading(towards);
        distance = -distance;
    }

    if (isPositiveOnAxis(towards))
        moveAlongAxis(distance);
    else
        moveAlongAxis(-distance);

    return true;
}

/// Shifts the position to the nearest node in a given direction
void PathPos::moveToNextNode(foth::heading direction)
{
    distFromNearest = 0;
}

/// Moves the coordinates along the current axis by the given distance
void PathPos::moveAlongAxis(double distance)
{
    // Gets the change in distance relative to the nearest node
    distFromNearest += distance;

    // If we're moving vertically, adjust the nearest Y node
    if (mainAxis == Vertical)
        nearestY = properRound(distFromNearest);
    // If we're moving horizontally, adjust the X node
    else
        nearestX = properRound(distFromNearest);

    // Determine the new distFromNearest
    distFromNearest = getRoundRemainder(distFromNearest);
}

/// Returns the distance to the nearest node in a given direction
double PathPos::distToNextNode(foth::heading direction)
{
    if (getAxis(direction) != mainAxis)
        return 1;

    if (isPositiveOnAxis(direction))
    {
        if (distFromNearest == 0)
            return 0;
        if (distFromNearest < 0)
            return -distFromNearest;
        else
            return 1.0 - distFromNearest;
    }
    else // We are going in a negative direction
    {
        if (distFromNearest < 0)
            return 1.0 + distFromNearest;
        else
            return distFromNearest;
    }
}

double PathPos::distToNextBorder(foth::heading direction)
{
    if (getAxis(direction) != mainAxis)
        return 0.5;

    if (isPositiveOnAxis(direction))
    {
        if (distFromNearest == 0.5)
            return 0;
        if (distFromNearest < 0)
            return 0.5 + -distFromNearest;
        else
            return 0.5 - distFromNearest;
    }
    else // We are going in a negative direction
    {
        if (distFromNearest < 0)
            return -distFromNearest;
        else
            return 0.5 + distFromNearest;
    }
}

double PathPos::getAbsoluteX()
{
    if (mainAxis == Horizontal)
        return nearestX + distFromNearest;
    else
        return nearestX;
}

double PathPos::getAbsoluteY()
{
    if (mainAxis == Vertical)
        return nearestY + distFromNearest;
    else
        return nearestY;
}

/// Get the excess value of a double which would be lost during rounding.
/// Effectively retrieves the number "after the decimal"
double PathPos::getRoundRemainder(double value)
{
    // Get the part after the decimal. Probably a loss of precision here...
    return value - ((int) value);
}

/// Turns a double into the nearest int. Rounds away from a number if its
/// value after the decimal is not within [-0.5, 0.5).
int PathPos::properRound(double value)
{
    int truncated = (int) value;

    // If the left-over value (after the decimal) is 0.5 or larger, round up
    if (value - truncated >= 0.5)
        return truncated + 1;
    // If the left-over value is less than -0.5, round down
    else if (value - truncated < -0.5)
        return truncated - 1;
    // If the left-over value is in between, simply truncate
    else
        return truncated;
}

/// Ensures that a distance is [-0.5, 0.5) by setting it to 0 if necessary
double PathPos::reconcile(double distance)
{
    if (distance >= 0.5 || distance < -0.5)
        return 0;
    else
        return distance;
}

PathPos::axis PathPos::getAxis(foth::heading direction)
{
    switch (direction)
    {
        case foth::North:
            return Vertical;

        case foth::East:
            return Horizontal;

        case foth::South:
            return Vertical;

        case foth::West:
            return Horizontal;
    }
}

bool PathPos::isPositiveOnAxis(foth::heading direction)
{
    switch (direction)
    {
        case foth::North:
            return true;

        case foth::East:
            return true;

        case foth::South:
            return false;

        case foth::West:
            return false;
    }
}

bool PathPos::inAxis(foth::heading direction, axis givenAxis)
{
    switch (direction)
    {
        case foth::North:
            return givenAxis == Vertical;

        case foth::East:
            return givenAxis == Horizontal;

        case foth::South:
            return givenAxis == Vertical;

        case foth::West:
            return givenAxis == Horizontal;
    }
}
