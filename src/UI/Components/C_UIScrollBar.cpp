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
 *  Contains implementation of the methods & classes declared
 *  in ScrollBar submodule.
 * 
 */

#include <iostream>

#include "Utility/Constants.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "UI/Components/C_UIScrollBar.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            C_UIScrollBar::C_UIScrollBar( const int height )
            {
                m_selectable = false;
                m_visible = true;
                m_enabled = true;
                m_selected = false;
                
                m_width = UI_SCROLL_TEXTURE_WIDTH;
                m_height = UI_SCROLL_TEXTURE_HEIGHT;
                m_scrollHeight = height;
                
                m_state[Rects::SCROLL_AREA] = State::NORMAL;
                m_state[Rects::SCROLL_BAR] = State::NORMAL;
                m_state[Rects::SCROLL_ARROW_UP] = State::NORMAL;
                m_state[Rects::SCROLL_ARROW_DOWN] = State::NORMAL;
                
                m_scrollAmount = 0;
                
                // Set the textures
                m_sprite[Rects::SCROLL_AREA].setTexture( *ResourceManager::getTexture( TextureID::UI_SCROLL_AREA ) );
                m_sprite[Rects::SCROLL_AREA].setTextureRect( sf::IntRect{ m_state[Rects::SCROLL_AREA] * m_width, 0, m_width, m_height } );
                
                m_sprite[Rects::SCROLL_BAR].setTexture( *ResourceManager::getTexture( TextureID::UI_SCROLL_BAR ) );
                m_sprite[Rects::SCROLL_BAR].setTextureRect( sf::IntRect{ m_state[Rects::SCROLL_BAR] * m_width, 0, m_width, m_height } );
                
                m_sprite[Rects::SCROLL_ARROW_UP].setTexture( *ResourceManager::getTexture( TextureID::UI_SCROLL_ARROW_UP ) );
                m_sprite[Rects::SCROLL_ARROW_UP].setTextureRect( sf::IntRect{ m_state[Rects::SCROLL_ARROW_UP] * m_width, 0, m_width, m_height } );
                
                m_sprite[Rects::SCROLL_ARROW_DOWN].setTexture( *ResourceManager::getTexture( TextureID::UI_SCROLL_ARROW_DOWN ) );
                m_sprite[Rects::SCROLL_ARROW_DOWN].setTextureRect( sf::IntRect{ m_state[Rects::SCROLL_ARROW_DOWN] * m_width, 0, m_width, m_height } );
                
                m_sprite[Rects::SCROLL_AREA].scale( 15.f / m_width, ( m_scrollHeight * 1.f ) / ( m_height * 1.f ) );
                m_sprite[Rects::SCROLL_ARROW_UP].scale( 15.f / m_width, 15.f / m_height );
                m_sprite[Rects::SCROLL_ARROW_DOWN].scale( 15.f / m_width, 15.f / m_height );
                m_sprite[Rects::SCROLL_BAR].scale( 15.f / m_width, ( ( m_scrollHeight - m_sprite[Rects::SCROLL_ARROW_DOWN].getGlobalBounds().height * 2.f ) * 1.f ) / ( m_height * 1.f ) );
            }
            
            void C_UIScrollBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
            {
                states.transform *= getTransform();
                target.draw( m_sprite[Rects::SCROLL_AREA] , states );
                target.draw( m_sprite[Rects::SCROLL_BAR] , states );
                target.draw( m_sprite[Rects::SCROLL_ARROW_UP] , states );
                target.draw( m_sprite[Rects::SCROLL_ARROW_DOWN] , states );
            }
        }
    }
}
