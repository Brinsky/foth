#include "PlayLevelState.h"

PlayLevelState::PlayLevelState(Game& game, int pixelsPerNode,
                               ResourceManager& manager) :
    GameState(game),
    grid(pixelsPerNode, manager, 20)
{

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
