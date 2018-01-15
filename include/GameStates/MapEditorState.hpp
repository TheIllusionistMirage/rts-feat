/*
 * ----------------------------
 *  Module    : GameStates
 *  Submodule : MapEditorState
 * ----------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 02-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module contains a class that defines the map editor state
 *  of the game.
 * 
 */

#ifndef MAP_EDITOR_STATE_HPP
#define MAP_EDITOR_STATE_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "GameStates/GameState.hpp"
#include "TileMap/TileMap.hpp"

namespace rts
{
    class MapEditorState : public GameState
    {
        public:
            
            typedef std::shared_ptr<MapEditorState> Ptr;
            
        public:
            
            MapEditorState( Game* game );
            
            ~MapEditorState();
            
            /* Handle user input */
            void handleInput() override;
            
            /* Update the objects constituting the main menu */
            void update( const sf::Time dt ) override;
            
            /* Render the objects constituting the main menu */
            void draw( const sf::Time dt ) override;
            
            void freeze(bool f) override;
            
        private:
            
            // Boundaries for the widgets
            enum Rect
            {
                MAIN_TITLE,
                MENU_BAR
            };
            
            sf::RectangleShape m_rects[2];
            
            WorldEntities::TileMap m_map;
            
            TextureID m_selectedTex;
    };
}

#endif // MAP_EDITOR_STATE_HPP
