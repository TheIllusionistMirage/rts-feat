/*
 * ---------------------------
 *  Module    : GameStates
 *  Submodule : MainMenuState
 * ---------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module contains a class that defines the main menu state
 *  of the game.
 * 
 */

#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "GameStates/GameState.hpp"

namespace rts
{
    class MainMenuState : public GameState
    {
        public:
            
            typedef std::shared_ptr<MainMenuState> Ptr;
            
        public:
            
            /* The pointer to the Game object which created
               this MainMenuState instance must be passed
               while creation.
            */
            MainMenuState(Game::Ptr game);
            
            /* Destructor */
            ~MainMenuState();
            
            /* Handle user input */
            void handleInput() override;
            
            /* Update the objects constituting the main menu */
            void update(const sf::Time dt) override;
            
            /* Render the objects constituting the main menu */
            void draw(const sf::Time dt) override;
            
            void freeze(bool f) override;
        
        private:
            
            void stateTransition( Game::State state );
            
            sf::Sprite m_testSprite;
    };
}

#endif // MAIN_MENU_STATE_HPP
