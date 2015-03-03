#ifndef PLAYLEVELSTATE_H
#define PLAYLEVELSTATE_H

#include "ResourceManager.h"
#include "GameState.h"
#include "MaterialGrid.h"
#include "TrackGrid.h"
#include "TrackLayer.h"

/// The state in which levels are loaded and played
class PlayLevelState : public GameState
{
    public:
        PlayLevelState(Game& a_game, int pixelsPerNode,
                       ResourceManager& manager);
        virtual ~PlayLevelState();

        void pause();
        void resume();

        void event(sf::Event event);
        void tick();
        void draw(VirtualScreen& screen);

    private:
        MaterialGrid materialGrid;
        TrackGrid trackGrid;
        TrackLayer trackLayer;
};

#endif
