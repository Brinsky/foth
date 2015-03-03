#include "PlayLevelState.h"

#include "Properties.h"

PlayLevelState::PlayLevelState(Game& game, int pixelsPerNode,
                               ResourceManager& manager) :
    GameState(game),
    materialGrid(7, 20, manager),
    trackGrid(7, 20, manager),
    trackLayer(3, 2, trackGrid, foth::south)
{
    materialGrid.setNode(0, 0, foth::stone);
    materialGrid.setNode(2, 4, foth::stone);
    materialGrid.setNode(4, 5, foth::stone);
    trackGrid.setNode(1, 1, foth::northEast);
    trackGrid.setNode(1, 2, foth::southEast);
    trackGrid.setNode(2, 1, foth::northWest);
    trackGrid.setNode(2, 2, foth::southWest);
    trackGrid.setNode(3, 1, foth::eastWest);
    trackGrid.setNode(3, 2, foth::northSouth);
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

void PlayLevelState::event(sf::Time elapsed, sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
            /// Deal with TrackLayer movement
            case sf::Keyboard::Left:
                trackLayer.move(foth::west);
                break;
            case sf::Keyboard::Right:
                trackLayer.move(foth::east);
                break;
            case sf::Keyboard::Up:
                trackLayer.move(foth::north);
                break;
            case sf::Keyboard::Down:
                trackLayer.move(foth::south);
                break;

            default:
                break;
        }
    }
}

void PlayLevelState::update(sf::Time elapsed)
{

}

void PlayLevelState::draw(VirtualScreen& screen)
{
    materialGrid.draw(screen);
    trackGrid.draw(screen);
}
