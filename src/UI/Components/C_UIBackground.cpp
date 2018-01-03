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
 *  Contains implementation of the methods & classes declared
 *  in Background submodule.
 * 
 */

#include "Utility/Log.hpp"
#include "Utility/Constants.hpp"
#include "UI/Components/C_UIBackground.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            C_UIBackground::C_UIBackground( const TextureID texID, const int sWidth, const int sHeight )
            {
                m_selectable = false;
                m_visible = true;
                m_enabled = true;
                m_selected = false;
                
                m_state = State::NORMAL;
                
                m_sWidth = sWidth;
                m_sHeight = sHeight;
                
                m_background.setTexture( *ResourceManager::getTexture( texID ) );
                
                // NOTE: This line has to be present in the code which handles updating the Background
                m_background.setTextureRect( sf::IntRect{ static_cast<int>( m_state ) * m_sWidth, 0, m_sWidth, m_sHeight } );
            }
            
            void C_UIBackground::draw(sf::RenderTarget& target, sf::RenderStates states) const
            {
                states.transform *= getTransform();
                target.draw( m_background, states );
            }
        }
    }
}
