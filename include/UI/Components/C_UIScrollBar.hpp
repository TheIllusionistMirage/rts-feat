/*
 * ------------------------
 *  Module    : Components
 *  Submodule : ScrollBar
 * ------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 04-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module defines the ScrollBar (vertical) component for the UI
 *  widgets. UI widgets containing the scrollbar component can have a
 *  vertical scroll bar functionality attached to them.
 * 
 */

#ifndef C_UI_SCROLLBAR_HPP
#define C_UI_SCROLLBAR_HPP

#include <memory>

#include <SFML/Graphics/Sprite.hpp>

#include "UI/Components/C_ComponentBase.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            struct C_UIScrollBar : public C_ComponentBase
            {
                typedef std::shared_ptr<C_UIScrollBar> Ptr;
                
                C_UIScrollBar( const int height );
                
                void draw(sf::RenderTarget& target, sf::RenderStates states) const;
                
                int m_width, m_height;
                
                // Denotes the sprites
                enum Rects
                {
                    SCROLL_AREA,
                    SCROLL_BAR,
                    SCROLL_ARROW_UP,
                    SCROLL_ARROW_DOWN
                };
                
                enum State
                {
                    INVALID = -1 ,
                    NORMAL ,
                    HOVER  ,
                    DOWN   ,
                    SELECTED,
                    MAX_STATE
                } m_state[4];
                
                sf::Sprite m_sprite[4];
                
                int m_scrollHeight;
                
                int m_scrollAmount;
                
                float deltaY;
            };
        }
    }
}

#endif // C_UI_SCROLLBAR_HPP
