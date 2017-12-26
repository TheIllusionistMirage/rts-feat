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
