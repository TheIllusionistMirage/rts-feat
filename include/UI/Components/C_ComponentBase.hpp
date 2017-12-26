/*
 * This is the common interface to which each UI component must adhere to
 */

#ifndef C_COMPONENT_BASE_HPP
#define C_COMPONENT_BASE_HPP

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
//                 /* The rectangular bounds of the component */
//                 sf::FloatRect m_bounds;
                
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
