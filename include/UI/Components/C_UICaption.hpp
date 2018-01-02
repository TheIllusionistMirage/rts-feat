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
 *  This module defines the Caption component for the UI widgets. UI
 *  widgets containing the Caption component can have text label
 *  attached to them.
 * 
 */

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
            struct C_UICaption : public C_ComponentBase
            {
                typedef std::shared_ptr<C_UICaption> Ptr;
                
                C_UICaption( const std::string& text,
                             const FontID fontID,
                             const int charSize,
                             const sf::Color fontColor );
                
                void draw(sf::RenderTarget& target, sf::RenderStates states) const;
                
                /* The text element of the caption */
                sf::Text m_text;
            };
        }
    }
}

#endif // C_UI_CAPTION_HPP
