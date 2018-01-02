/*
 * ------------------------
 *  Module    : Components
 *  Submodule : Caption
 * ------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods & classes declared
 *  in Caption submodule.
 * 
 */

#include "Utility/Log.hpp"
#include "Utility/Constants.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "UI/Components/C_UICaption.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            C_UICaption::C_UICaption( const std::string& text,
                                      const FontID fontID,
                                      const int charSize,
                                      const sf::Color fontColor )
            {
                // A caption cannot be selected
                m_selectable = false;
                m_visible = true;
                m_enabled = true;
                m_selected = false;
                
                m_text.setFont( *ResourceManager::getFont( fontID ) );
                m_text.setString( text );
                m_text.setFillColor( fontColor );
                
                if ( charSize >= 10 && charSize <= 70 )
                    m_text.setCharacterSize( charSize );
                else
                    m_text.setCharacterSize( UI_DEFAULT_CAPTION_CHAR_SIZE );
            }
                            
            void C_UICaption::draw(sf::RenderTarget& target, sf::RenderStates states) const
            {
                states.transform *= getTransform();
                target.draw( m_text, states );
            }
        }
    }
}
