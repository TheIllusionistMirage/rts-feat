/*
 * ---------------------
 *  Module : GameStates
 * ---------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module defines the API for the game state classes.
 * 
 */

#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <memory>

#include "Game.hpp"

namespace rts
{
    // Forward declaration of the Game class
    class Game;
    
    // This is an abstract class. Actual states must derive from this class.
    class GameState
    {
        public:
            
            typedef std::shared_ptr<GameState> Ptr;
        
        public:
            
            /* Default constructor */
            GameState(){}
            
            /* Virtual destructor */
            virtual ~GameState(){}
            
            /* All derived classes must define methods with
               the following signatures to handle input,
               update and render them. */
            
            virtual void handleInput() = 0;
            
            virtual void update(const sf::Time dt) = 0;
            
            virtual void draw(const sf::Time dt) = 0;
            
        public:
            
            // Pointer to the Game object of which this state is a part of
            Game* m_game;
    };
}

#endif // GAME_STATE_HPP
