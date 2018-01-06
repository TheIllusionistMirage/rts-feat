/*
 * ---------------------------
 *  Module : ComponentManager
 * ---------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module contains the components manager for the UI components,
 *  entities and other objects of the game that follow the component
 *  based model.
 * 
 *  The component manager for the UI components are stored in th
 *  `UIComponent` namespace.
 * 
 *  The structure of the ComponentManager module is pretty
 *  self-explanatory if you're familiar with component based object
 *  composition.
 * 
 */

#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <string>
#include <map>
#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "ResourceManager/ResourceManager.hpp"
#include "UI/Components/C_UICaption.hpp"
#include "UI/Components/C_UIBackground.hpp"
#include "UI/Components/C_UIScrollBar.hpp"
#include "UI/Components/C_UIGroup.hpp"

namespace rts
{
    namespace CallbackManager
    {
        template <typename R, typename ...A>
        struct Callback
        {
            typedef std::function<R(A...)> Callable;
        };
    }
    
    namespace CManager
    {
        ///////////////////
        // UI Components //
        ///////////////////
        namespace UIComponent
        {
            ////////////////////////
            // Callback structure //
            ////////////////////////
            
            typedef std::function<void()> Callback;
            
            enum class UIEvent
            {
                INVALID,
                MOUSE_PRESSED,
                MOUSE_RELEASED,
                SCROLL_DRAGGED_UP,
                SCROLL_DRAGGED_DOWN,
                MAX_EVENTS
            };
            
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

                    /* Create a new Caption component with the given ID,
                     * text, font, character size and font color
                     */
                    static bool create( const std::string& ID,
                                        const std::string& text,
                                        const FontID fontID,
                                        const int charSize,
                                        const sf::Color fontColor );
                    
                    /* Destroy a Caption component with the given ID (if it exists) */
                    static void destroy( const std::string& ID );
                    
                    /* Set the Caption text */
                    static void setCaption( const std::string& ID,
                                            const std::string& text );
                    
                    /* Get the string of a Caption */
                    static const std::string getCaption( const std::string& ID );
                    
                    /* Set the position of a Caption */
                    static void setPosition( const std::string& ID,
                                             const sf::Vector2f& position );
                    
                    /* Get the position of a Caption */
                    static const sf::Vector2f getPosition( const std::string& ID );
                    
                    /* Get the size of a Caption */
                    static const sf::Vector2f getSize( const std::string& ID );
                    
                    /* Set the character size for a Caption */
                    static void setCharSize( const std::string& ID,
                                             const int size );
                    
                    /* Set the font of a Caption */
                    static void setFont( const std::string& ID,
                                         FontID font );
                    
                    /* Hide/Show a Caption */
                    static void setVisibility( const std::string& ID,
                                               bool visibility );
                    
                    /* Set the origin about which transforms are applied on the Caption */
                    static void setOrigin( const std::string& ID,
                                           const sf::Vector2f& origin );
                    
                    static void setCallback( const std::string& ID,
                                             Callback cb,
                                             UIEvent event );
                    
                public:
                    
                    /* update and render methods need access to the static maps */
                    
                    friend void updateUIComponents( const sf::Event& event,
                                                    const sf::Vector2i mousePos,
                                                    const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                
                private:
                    
                    // The Caption component map. All Caption components
                    // created in the game are stored here.
                    static std::map<std::string, C_UICaption::Ptr> captions;
                    
                    static std::map<std::pair<std::string, UIEvent>, Callback> caption_callbacks;
            };
            
            
            //////////////////////////
            // Background component //
            //////////////////////////
            class Background
            {
                public:
                    
                    /* Create a new caption component with the given ID */
                    static bool create( const std::string& ID,
                                        const TextureID texID,
                                        const int sWidth, 
                                        const int sHeight, 
                                        bool mode );
                    
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
                    
                    static void setCallback( const std::string& ID,
                                             Callback cb,
                                             UIEvent event );
                
                public:
                    
                    /* update and render methods need access to the static maps */                    
                    friend void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                    
                private:
                    
                    static std::map<std::string, C_UIBackground::Ptr> backgrounds;
                    
                    static std::map<std::pair<std::string, UIEvent>, Callback> background_callbacks;
            };
            
            class ScrollBar
            {
                public:
                    
                    static bool create( const std::string& ID, const int scrollHeight );
                    
                    static void destroy( const std::string& ID );
                    
                    static void setPosition( const std::string& ID, const sf::Vector2f& position );
                    
                    static const sf::Vector2f getPosition( const std::string& ID );
                    
                    static const sf::Vector2f getSize( const std::string& ID );
                    
                    static void setState( const std::string& ID, C_UIScrollBar::Rects rect, C_UIScrollBar::State state );
                    
                    static void setScrollAmount( const std::string& ID, const int scrollAmount );
                    
                    static void setRowCount( const std::string& ID, const int rows );
                    
                    static void setVisibility( const std::string& ID, const bool visibility );
                    
                    //static void setOrigin( const std::string& ID, const sf::Vector2f& origin );
                    
                    static void setCallback( const std::string& ID,
                                             Callback cb,
                                             UIEvent event );
                
                public:
                    
                    /* update and render methods need access to the static maps */                    
                    friend void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                    
                private:
                    
                    static std::map<std::string, C_UIScrollBar::Ptr> scrollbars;
                    
                    static std::map<std::pair<std::string, UIEvent>, Callback> scrollbar_callbacks;
            };
            
            
            /////////////////////
            // Group component //
            /////////////////////
            class Group
            {
                public:
                    
                    /* Create a new Group component */
                    static bool create( const std::string& ID );
                    
                    static bool create( const std::string& ID, const std::vector<std::string>& members );
                    
                    static void destroy( const std::string& ID );
                    
                    /* Add a UI widget with ID `wID` to the Group identified by `ID` */
                    static void add( const std::string& ID, const std::string& mID );
                    
                    /* Returns the member count for the given Group */
                    static int count( const std::string& ID );
                    
                    /* Returns the ID of the first added member in the Group */
                    static std::string first( const std::string& ID );
                    
                    /* Returns the ID of the last added member in the Group */
                    static std::string last( const std::string& ID );
                    
                    /* Returns the list of IDs of all members of the Group */
                    static std::vector<std::string> get( const std::string& ID );
                    
                public:
                    
                    /* update and render methods need access to the static maps */                    
                    friend void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt );
                    
                    friend void renderUIComponents( sf::RenderWindow& window );
                    
                private:
                    
                    static std::map<std::string, C_UIGroup::Ptr> groups;
            };
            
//             
//             class TitleBar
//             {
//                 public:
//                 public:
//                 private:
//                     
//             };
            
            //static std::map<std::pair<std::string, UIEvent>, Callback> menu_button_callbacks;
            
            ///////////////////////////////////////////////
            // Update & Render operations for components //
            ///////////////////////////////////////////////
            
            void updateUIComponents( const sf::Event& event,
                                     const sf::Vector2i mousePos,
                                     const sf::Time dt );
            
            void renderUIComponents( sf::RenderWindow& window );
        }
    }
}

#endif // COMPONENT_MANAGER_HPP
