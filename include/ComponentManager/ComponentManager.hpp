/*
 * Manages all the in game components of the
 * UI system, entity system and the world engine
 */

#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <string>
#include <map>

#include <SFML/Graphics/RenderWindow.hpp>

//#include "UI/Components/C_UIGroup.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "UI/Components/C_UICaption.hpp"

namespace rts
{
    namespace CManager
    {
        //static std::map<std::string, Group::C_UIGroup::Ptr> m_groupComponents;
        namespace UIComponent
        {
//             static std::map<std::string, Caption::C_UICaption::Ptr> captions;
            
//             namespace Caption
//             {
            class Caption
            {
                public:

                    /* Create a new caption component with the given ID */
                    static bool create( const std::string& ID, const std::string& text );
                    
                    /* Destroy a caption component with the given ID (if it exists) */
                    static void destroy( const std::string& ID );
                    
                    /* Set the caption text */
                    static void setCaption( const std::string& ID, const std::string& text );
                    
                    /* Get the string of the caption */
                    static const std::string getCaption( const std::string& ID );
                    
                    /* Set the position of the Caption */
                    static void setPosition( const std::string& ID, const sf::Vector2f& position );
                    
                    /* Get the position of the Caption */
                    static const sf::Vector2f getPosition( const std::string& ID );
                    
                    /* Set the character size for teh Caption */
                    static void setCharSize( const std::string& ID, const int size );
                    
                    /* Set the font of the Caption */
                    static void setFont( const std::string& ID, FontID font );
                    
                    /* Hide/Show the Caption */
                    static void setVisibility( const std::string& ID, const bool visibility );
                    
                    /* update and render methods need access to the static maps */                    
                    friend void updateUIComponents( const sf::Event& event, const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                
                private:
                    
                    static std::map<std::string, C_UICaption::Ptr> captions;
            };
//             }
            
            void updateUIComponents( const sf::Event& event, const sf::Time dt );
            
            void renderUIComponents( sf::RenderWindow& window );
        }
    }
}

#endif // COMPONENT_MANAGER_HPP
