#ifndef GAME_H
#define GAME_H

#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>

// Forward declaration required to prevent circular dependency.
class GameState;

/// A Game manages an SFML window, SFML events, and GameStates.
/// The structure of Game was partly inspired by this post:
/// http://gamedevgeek.com/tutorials/managing-game-states-in-c/
class Game
{
    public:
        Game(sf::RenderWindow& a_window);
        virtual ~Game();

        // Main loop functions
        void loop();

        // State management functions
        void changeState(std::unique_ptr<GameState> state);
        void pushState(std::unique_ptr<GameState> state);
        void popState();

        void quit();

    private:
        // Game loop functions, called in this order
        virtual void event(sf::Event a_event);
        virtual void tick();
        virtual void draw();

        // Proxy functions to ensure that both game loop and state loop
        // functions are called
        void masterEvent(sf::Event a_event);
        void masterTick();
        void masterDraw();

        sf::RenderWindow& window;
        std::stack<std::unique_ptr<GameState>> states;
        bool running;
};

#endif