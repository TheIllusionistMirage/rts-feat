/*
 * ---------------
 *  Module : Game
 * ---------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module abstracts away the overall game attributes and
 *  functions and manages the flow.
 * 
 *  The Game class is responsible for initializing the game assets
 *  by invoking appropriate methods of the resource manager, managing
 *  the game states by handling input, updating and rendering them.
 * 
 *  Other management functions like entity management & component
 *  management are delegated to their respective managers. This
 *  software follows the component based object model for realizing
 *  in game entities (game entities like units or UI widgets like
 *  buttons).
 * 
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "GameStates/GameState.hpp"

namespace rts
{
    // Forward declration of the GameState API
    class GameState;
    
    // The Game class with the high level attributes
    // and methods for managing the overall flow of
    // the game.
    class Game
    {
        public:
            typedef Game* Ptr;
            
            /////////////////
            // Game States //
            /////////////////
            enum class State
            {
                INVALID = -1, // Invalid state
                MAIN_MENU,    // Main menu state
                START_GAME,   // The state just prior to playing, allows users to set game options like civilizaiton, map style etc.
                PLAYING,      // The heart state of this software; This is where all the magic happens
                MAP_EDITOR,   // The state for editing maps
                PAUSED        // The paused state
            };
            
        public:
            
            /* Default constructor
             * 
             * Initializes the game window, the resource
             * manager and sets some basic properties.
             */
            Game();
            
            /* The main program loop.
             * 
             * For the current state, it's updation &
             * rendering take place here.
             */
            void run();
            
            /* Stop the main progam loop.
             * 
             * Break the main program loop, release all
             * resources and stop the program.
             */
            void close();
            
            /* Add a new state on the game state stack.
             * 
             * This method causes the specified state to
             * be pushed to the top of stack.
             */            
            void pushState( const State state );
            
            /* Remove the current state from the game state stack.
             * 
             * This method causes the state on the top of the
             * stack to be removed.
             */
            void popState();
            
            /* Replace the current state from the game state stack.
             * 
             * This method replaces the state currently on the top
             * of the game state stack with the specified state.
             */
            void changeState( const State state );
            
            /* Get a pointer to the current game state.
             */
            std::shared_ptr<GameState> peekState();
            
        public:
            
            // Main game window
            sf::RenderWindow m_window;
            
            // The game state stack
            std::stack<std::shared_ptr<GameState>> m_states;
            
            // The background for the current state
            sf::Sprite m_backgroundSprite;
            
            // Boolean to indicate game status, i.e., running or not
            bool m_running;
            
        private:
            
            sf::Sprite m_mousePointer   ;
            
            /* Debug info */
            
            // Frame rate info
            sf::Text m_fps;
    };
}

#endif // GAME_HPP
