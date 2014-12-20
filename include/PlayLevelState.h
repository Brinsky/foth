#ifndef PLAYLEVELSTATE_H
#define PLAYLEVELSTATE_H

#include "GameState.h"
#include "NodeGrid.h"

/// The state in which levels are loaded and played
class PlayLevelState : public GameState
{
    public:
        PlayLevelState(Game& a_game);
        virtual ~PlayLevelState();

        void pause();
        void resume();

        void event(sf::Event event);
        void tick();
        void draw(sf::RenderTarget& target,
                  sf::RenderStates states);

    private:
        NodeGrid grid;
};

#endif
