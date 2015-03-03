#include "TrackGrid.h"

TrackGrid::TrackGrid(int width, int height, ResourceManager& manager) :
    Grid(width, height),
    track(manager, "track", true),
    straight(0, 0, 64, 64),
    turn(64, 0, 64, 64)
{
}

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
                    track.setTextureRect(straight);
                    track.setRotation(0);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::northEast:
                    track.setTextureRect(turn);
                    track.setRotation(180);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::northWest:
                    track.setTextureRect(turn);
                    track.setRotation(90);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::southEast:
                    track.setTextureRect(turn);
                    track.setRotation(270);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::southWest:
                    track.setTextureRect(turn);
                    track.setRotation(0);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
                case foth::eastWest:
                    track.setTextureRect(straight);
                    track.setRotation(90);
                    screen.worldDraw(track, sf::Vector2f(x, y));
                    break;
            }
        }
    }
}
