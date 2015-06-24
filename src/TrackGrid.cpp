#include "TrackGrid.h"

TrackGrid::TrackGrid(int width, int height, ResourceManager& manager) :
    Grid(width, height),
    track(manager, "track", "straight", true)
{}

void TrackGrid::draw(VirtualScreen& screen)
{
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            switch (getNode(x, y))
            {
                case foth::none:
                    break;
                case foth::northSouth:
                    track.changeFrame("straight");
                    track.setRotation(0);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::northEast:
                    track.changeFrame("turn");
                    track.setRotation(180);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::northWest:
                    track.changeFrame("turn");
                    track.setRotation(90);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::southEast:
                    track.changeFrame("turn");
                    track.setRotation(270);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::southWest:
                    track.changeFrame("turn");
                    track.setRotation(0);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::eastWest:
                    track.changeFrame("straight");
                    track.setRotation(90);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
            }
        }
    }
}
