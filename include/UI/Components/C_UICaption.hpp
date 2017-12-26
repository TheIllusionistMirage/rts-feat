#ifndef C_UI_CAPTION_HPP
#define C_UI_CAPTION_HPP

#include <string>
#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "UI/Components/C_ComponentBase.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
//             namespace Caption
//             {
                struct C_UICaption : public C_ComponentBase
                {
                    typedef std::shared_ptr<C_UICaption> Ptr;
                    
                    C_UICaption( const std::string& text );
                    
                    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
                    
                    /* The text element of the caption */
                    sf::Text m_text;
                };
//             }
        }
    }
}

#endif // C_UI_CAPTION_HPP
