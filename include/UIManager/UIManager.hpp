#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include <string>
#include <map>

#include "ResourceManager/ResourceManager.hpp"

namespace rts
{
    namespace UIManager
    {
        /* Helpers common to all UI widgets */
        bool selectable( const std::string& ID );
        
        /* Select a widget with ID `wID` in the Group identified by `ID` */
        void select( const std::string& ID, const std::string& wID );
        
        namespace UILabel
        {
            /* Create a new Label component with the given ID */
            bool create( const std::string& ID, const std::string& text );
            
            /* Destroy a Label component with the given ID (if it exists) */
            void destroy( const std::string& ID );
            
            /* Set the Label text */
            void setCaption( const std::string& ID, const std::string& text );
            
            /* Get the string of the Label */
            const std::string getCaption( const std::string& ID );
            
            /* Set the position of the Label */
            void setPosition( const std::string& ID, const sf::Vector2f& position );
            
            /* Get the position of the Label */
            const sf::Vector2f getPosition( const std::string& ID );
            
            /* Get the size of the Label */
            const sf::Vector2f getSize( const std::string& ID );
            
            /* Set the character size for teh Caption */
            void setCharSize( const std::string& ID, const int size );
            
            /* Set the font of the Caption */
            void setFont( const std::string& ID, FontID font );
            
            /* Hide/Show the Caption */
            void setVisibility( const std::string& ID, const bool visibility );
        }
        
        namespace UIButton
        {
            bool create( const std::string& ID, const std::string& text );
            
            void destroy( const std::string& ID );
            
            void setCaption( const std::string& ID, const std::string& text );
            
            const std::string getCaption( const std::string& ID );
            
            void setPosition( const std::string& ID, const sf::Vector2f& position );
            
            const sf::Vector2f getPosition( const std::string& ID );
            
            /* Get the size of the UIButton */
            const sf::Vector2f getSize( const std::string& ID );
            
            void setCharSize( const std::string& ID, const int size );
            
            /* Set the font of the Caption */
            void setFont( const std::string& ID, FontID font );
            
            /* Hide/Show the Caption */
            void setVisibility( const std::string& ID, const bool visibility );
        }
        
        namespace UIContainer
        {
            
        }
        
        
        namespace UIPicture
        {
            /* Create a Picture widget with given ID and specified image and caption */
            bool create( const std::string& ID, const TextureID tID, const int sWidth, const int sHeight, const std::string& text );
            
            /* Set the image of the Picture widget */
            void setPicture( const std::string& ID, const TextureID tID, const int sWidth, const int sHeight );
            
            /* Set the caption of the Picture widget */
            void setCaption( const std::string& ID, const std::string& text );
            
            /* Set the position of a Picture widget */
            void setPosition( const std::string& ID, const sf::Vector2f& position );
            
            /* Get the position of a Picture widget */
            const sf::Vector2f getPosition( const std::string& ID );
            
            // NOTE: The character size of the caption for a picture cannot be excplicitly set
            
            /* Set the size of a Picture widget */
            void setSize( const std::string& ID, const sf::Vector2f& size );
            
            /* Get the size of a Picture widget */
            const sf::Vector2f getSize( const std::string& ID );
        }
        
        namespace UIRadioButton
        {
            /* Create a radio button with specified ID and caption */
            bool create( const std::string& ID, const std::string& text );
            
            /* Set the position of a radio button */
            void setPosition( const std::string& ID, const sf::Vector2f& position );
        }
    }
}

#endif // UI_MANAGER_HPP
