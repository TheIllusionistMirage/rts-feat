/*
 * ---------------------------
 *  Module    : Components
 *  Submodule : ComponentBase
 * ---------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module defines the API for the classes that implement UI
 *  components.
 * 
 */

#ifndef C_COMPONENT_BASE_HPP
#define C_COMPONENT_BASE_HPP

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            struct C_ComponentBase : public sf::Drawable,
                                     public sf::Transformable
            {                
                typedef std::shared_ptr<C_ComponentBase> Ptr;
                
                /* Indicates whether or not the component reacts to user input & is updated */
                bool m_enabled;
                
                /* Indicates whether the component is visible or not */
                bool m_visible;
                
                /* Indicates whether the component is currently reacting to mouse/keyboard input */
                bool m_selected;
                
            protected:
                
                /* Indicates whether the component can be selected or not */
                bool m_selectable;
            };
        }
    }
}

#endif // C_COMPONENT_BASE_HPP
