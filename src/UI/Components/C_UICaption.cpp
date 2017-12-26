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
            C_UICaption::C_UICaption( const std::string& text )
            {
                // A caption cannot be selected
                m_selectable = false;
                m_visible = true;
                m_enabled = true;
                m_selected = false;
                
//                 m_text.setFont( *ResourceManager::getFont( FontID::MONACO ) );
                m_text.setFont( *ResourceManager::getFont( FontID::DEFAULT ) );
                m_text.setString( text );
                m_text.setFillColor( sf::Color::White );
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
