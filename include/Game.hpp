#ifndef GAME_HPP
#define GAME_HPP

#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "GameState.hpp"

namespace rts
{
    class GameState;
    
    class Game
    {
        public:
            
            /////////////////////
            // Possible States //
            /////////////////////
            enum class State
            {
                MAIN_MENU,
                MAP_EDITOR,
                GAME_START,
                PLAYING,
                PAUSED
            };
            
        public:
            
            Game();
            
            ~Game();
            
            void run();
            
            void close();
            
            void pushState( const State state );
            
            void popState();
            
            void changeState( const State state );
            
            std::shared_ptr<GameState> peekState();
            
        public:
            
            sf::RenderWindow m_window;
            
            std::stack<std::shared_ptr<GameState>> m_states;
            
            sf::Sprite m_backgroundSprite;
            
            sf::Text m_fps;
            
            bool m_running;
    };
}

#endif // GAME_HPP
