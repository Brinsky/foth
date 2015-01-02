#include "PlayLevelState.h"

#include "Properties.h"

PlayLevelState::PlayLevelState(Game& game, int pixelsPerNode,
                               ResourceManager& manager) :
    GameState(game),
    grid(7, 20, manager),
    track(7, 20, manager) 
{
    grid.setNode(0, 0, foth::stone);
    grid.setNode(2, 4, foth::stone);
    grid.setNode(4, 5, foth::stone);
    track.setNode(1, 1, foth::northEast);
    track.setNode(1, 2, foth::southWest);
    track.setNode(2, 1, foth::northWest);
    track.setNode(2, 2, foth::southEast);
    track.setNode(3, 1, foth::eastWest);
    track.setNode(3, 2, foth::northSouth);
}

PlayLevelState::~PlayLevelState()
{

}

void PlayLevelState::pause()
{

}

void PlayLevelState::resume()
{

}

void PlayLevelState::event(sf::Event event)
{

}

void PlayLevelState::tick()
{

}

void PlayLevelState::draw(VirtualScreen& screen)
{
    grid.draw(screen);
    track.draw(screen);
}
