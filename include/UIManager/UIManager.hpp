#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include <string>
#include <map>

#include "ResourceManager/ResourceManager.hpp"

namespace rts
{
    namespace UIManager
    {
        namespace UILabel
        {
            /* Create a new caption component with the given ID */
            bool create( const std::string& ID, const std::string& text );
            
            /* Destroy a caption component with the given ID (if it exists) */
            void destroy( const std::string& ID );
            
            /* Set the caption text */
            void setCaption( const std::string& ID, const std::string& text );
            
            /* Get the string of the caption */
            const std::string getCaption( const std::string& ID );
            
            /* Set the position of the Caption */
            void setPosition( const std::string& ID, const sf::Vector2f& position );
            
            /* Get the position of the Caption */
            const sf::Vector2f getPosition( const std::string& ID );
            
            /* Set the character size for teh Caption */
            void setCharSize( const std::string& ID, const int size );
            
            /* Set the font of the Caption */
            void setFont( const std::string& ID, FontID font );
            
            /* Hide/Show the Caption */
            void setVisibility( const std::string& ID, const bool visibility );
        }
    }
}

#endif // UI_MANAGER_HPP
