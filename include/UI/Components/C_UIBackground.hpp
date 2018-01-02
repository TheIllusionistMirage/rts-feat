/*
 * ------------------------
 *  Module    : Components
 *  Submodule : Background
 * ------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module defines the Background component for the UI widgets.
 *  UI widgets containing the Background component can have a
 *  background texture attached to them.
 * 
 */

#ifndef C_UI_BACKGROUND_HPP
#define C_UI_BACKGROUND_HPP

#include <memory>

#include <SFML/Graphics/Sprite.hpp>

#include "ResourceManager/ResourceManager.hpp"
#include "UI/Components/C_ComponentBase.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            struct C_UIBackground : public C_ComponentBase
            {
                typedef std::shared_ptr<C_UIBackground> Ptr;
                
                C_UIBackground( const TextureID texID, const int sWidth, const int sHeight );
                
                void draw(sf::RenderTarget& target, sf::RenderStates states) const;
                
                /* The background sprite */
                sf::Sprite m_background;
                
                /* State of the button */
                enum State
                {
                    INVALID = -1 ,
                    NORMAL ,
                    HOVER  ,
                    DOWN
                } m_state;
                
                /* Width & Height of the sprite for any state */
                int m_sWidth, m_sHeight;
            };
        }
    }
}

#endif // C_UI_BACKGROUND_HPP
