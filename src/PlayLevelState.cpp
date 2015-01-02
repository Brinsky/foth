#include "PlayLevelState.h"

#include "Properties.h"

PlayLevelState::PlayLevelState(Game& game, int pixelsPerNode,
                               ResourceManager& manager) :
    GameState(game),
    grid(7, 20, manager)
{
    grid.setNode(0, 0, foth::stone);
    grid.setNode(2, 4, foth::stone);
    grid.setNode(4, 5, foth::stone);
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
}
