#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <memory>

#include "Game.hpp"

namespace rts
{
    class Game;
    
    /*
     * This is an abstract class. Actual states must derive from this class.
     */
    
    class GameState
    {
        public:
            typedef std::shared_ptr<GameState> Ptr;
        
        public:
            
            Game* game;
            
            virtual void draw(const sf::Time dt) = 0;

            virtual void update(const sf::Time dt) = 0;

            virtual void handleInput() = 0;
            
        private:
    };
}

#endif // GAME_STATE_HPP
