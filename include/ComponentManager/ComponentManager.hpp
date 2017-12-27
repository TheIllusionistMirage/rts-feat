/*
 * Manages all the in game components of the
 * UI system, entity system and the world engine
 */

#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <string>
#include <map>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

//#include "UI/Components/C_UIGroup.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "UI/Components/C_UICaption.hpp"
#include "UI/Components/C_UIBackground.hpp"
#include "UI/Components/C_UIGroup.hpp"

namespace rts
{
    namespace CManager
    {
        ///////////////////
        // UI Components //
        ///////////////////
        namespace UIComponent
        {
            //////////////////////////////////////
            // UI component interface functions //
            //////////////////////////////////////
            
//             /* Enable the component */
//             void enable( const std::string& ID );
//             
//             /* Disable the component */
//             void disable( const std::string& ID );
//             
//             /* Set the visibility of a component */
//             void setVisibility( const std::string& ID, const bool visibility );
//             
//             /* Function only relevant for components that are selectable */
//             void select( const std::string& ID );
//             
//             /* Returns true if the component is enabled */
//             bool enabled( const std::string& ID );
//             
//             /* Returns true if the component is visible */
//             bool visible( const std::string& ID );
//             
//             /* Returns true if the component is selectable */
//             bool selectable( const std::string& ID );
//             
//             /* Returns true only if the component is selectable &
//                currently the one selected in its component group */
//             bool selected( const std::string& ID );
            
            ///////////////////////
            // Caption component //
            ///////////////////////
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
                    
                    /* Get the size of the Caption */
                    static const sf::Vector2f getSize( const std::string& ID );
                    
                    /* Set the character size for teh Caption */
                    static void setCharSize( const std::string& ID, const int size );
                    
                    /* Set the font of the Caption */
                    static void setFont( const std::string& ID, FontID font );
                    
                    /* Hide/Show the Caption */
                    static void setVisibility( const std::string& ID, const bool visibility );
                    
                    /* Set the origin about which transforms are applied */
                    static void setOrigin( const std::string& ID, const sf::Vector2f& origin );
                    
                public:
                    
                    /* update and render methods need access to the static maps */                    
                    friend void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                
                private:
                    
                    static std::map<std::string, C_UICaption::Ptr> captions;
            };
            
            
            //////////////////////////
            // Background component //
            //////////////////////////
            class Background
            {
                public:
                    
                    /* Create a new caption component with the given ID */
                    static bool create( const std::string& ID, const TextureID texID, const int sWidth, const int sHeight );
                    
                    /* Destroy a caption component with the given ID (if it exists) */
                    static void destroy( const std::string& ID );
                    
                    /* Set the texture of the Background component */
                    static void setTexture( const std::string& ID, TextureID texID, const int sWidth, const int sHeight );
                    
                    /* Set the state of the Background component */
                    static void setState( const std::string& ID, C_UIBackground::State state );
                    
                    /* Get the current state of the Background component */
                    static C_UIBackground::State getState( const std::string& ID );
                    
                    /* Set the position of the Background */
                    static void setPosition( const std::string& ID, const sf::Vector2f& position );
                    
                    /* Get the position of the Background */
                    static const sf::Vector2f getPosition( const std::string& ID );
                    
                    /* Set the size of the Background */
                    static void setSize( const std::string& ID, const sf::Vector2f& size );
                    
                    /* Get the size of the Background */
                    static const sf::Vector2f getSize( const std::string& ID );
                    
                    /* Hide/Show the Background */
                    static void setVisibility( const std::string& ID, const bool visibility );
                    
                    /* Set the origin about which transforms are applied */
                    static void setOrigin( const std::string& ID, const sf::Vector2f& origin );
                
                public:
                    
                    /* update and render methods need access to the static maps */                    
                    friend void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                    
                private:
                    static std::map<std::string, C_UIBackground::Ptr> backgrounds;
            };
            
            
            /////////////////////
            // Group component //
            /////////////////////
            class Group
            {
                public:
                    
                    /* Create a new Group component */
                    static bool create( const std::string& ID );
                    
                    /* Add a UI widget with ID `wID` to the Group identified by `ID` */
                    static void add( const std::string& ID, const std::string& mID );
                    
                public:
                    
                    /* update and render methods need access to the static maps */                    
                    friend void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                    
                private:
                    
                    static std::map<std::string, C_UIGroup::Ptr> groups;
            };
            
            
            ///////////////////////////////////////////////
            // Update & Render operations for components //
            ///////////////////////////////////////////////
            
            void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt );
            
            void renderUIComponents( sf::RenderWindow& window );
        }
    }
}

#endif // COMPONENT_MANAGER_HPP
