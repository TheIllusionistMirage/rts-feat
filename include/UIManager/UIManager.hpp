/*
 * --------------------
 *  Module : UIManager
 * --------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module contains methods for composing UI widgets like labels,
 *  buttons, etc. using the UI components available. The methods here
 *  invoke the appropriate UI component manager methods for creating
 *  and customizing the UI components to get a resulting UI widget.
 *  Hence, UI widgets aren't concrete instances of some classes but
 *  are defined in terms of their components.
 * 
 */

#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include <functional>
#include <string>
#include <map>
//#include <utility>

#include "ComponentManager/ComponentManager.hpp"
#include "ResourceManager/ResourceManager.hpp"

namespace rts
{
    namespace UIManager
    {
        ////////////////////////
        
        /* Helpers common to all UI widgets */
        bool selectable( const std::string& ID );
        
        /* Select a widget with ID `wID` in the Group identified by `ID` */
        void select( const std::string& ID, const std::string& wID );
        
        
        // The default UI Label widget        
        namespace UILabel
        {            
            /* Create a new Label component with the given ID */
            bool create( const std::string& ID,
                         const std::string& text );
            
            /* Destroy a Label component with the given ID (if it exists) */
            void destroy( const std::string& ID );
            
            /* Set the Label text */
            void setCaption( const std::string& ID,
                             const std::string& text );
            
            /* Get the string of the Label */
            const std::string getCaption( const std::string& ID );
            
            /* Set the position of the Label */
            void setPosition( const std::string& ID,
                              const sf::Vector2f& position );
            
            /* Get the position of the Label */
            const sf::Vector2f getPosition( const std::string& ID );
            
            /* Get the size of the Label */
            const sf::Vector2f getSize( const std::string& ID );
            
            /* Set the character size for teh Caption */
            void setCharSize( const std::string& ID,
                              const int size );
            
            /* Set the font of the Caption */
            void setFont( const std::string& ID,
                          FontID font );
            
            /* Hide/Show the Label */
            void setVisibility( const std::string& ID,
                                const bool visibility );
            
            void setOrigin( const std::string& ID,
                                   const sf::Vector2f& origin );
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
            
            /* Set a callback to the button for handling the button press event */
            template <typename Callable>
            void setCallback( const std::string& ID, Callable callable, CManager::UIComponent::UIEvent event )
            {
                if ( event <= CManager::UIComponent::UIEvent::INVALID || event >= CManager::UIComponent::UIEvent::MAX_EVENTS )
                {
                    LOG(Logger::Level::ERROR) << "Invalid UIEvent specified." << std::endl;
                    return;
                }
                
                CManager::UIComponent::Background::setCallback( ID, callable, event );
            }
        }

        namespace UIMenuButton
        {
            bool create( const std::string& ID, const std::string& text );
            
            void destroy( const std::string& ID );
            
            void setCaption( const std::string& ID, const std::string& text );
            
            const std::string getCaption( const std::string& ID );
            
            void setPosition( const std::string& ID, const sf::Vector2f& position );
            
            const sf::Vector2f getPosition( const std::string& ID );
            
            /* Get the size of the UIButton */
            const sf::Vector2f getSize( const std::string& ID );
            
            //void setCharSize( const std::string& ID, const int size );
            
            /* Set the font of the Caption */
            //void setFont( const std::string& ID, FontID font );
            
            /* Hide/Show the button */
            void setVisibility( const std::string& ID, const bool visibility );
            
            /* Set a callback to the button for handling the button press event */
            
            template <typename Callable>
            void setCallback( const std::string& ID, Callable callable, CManager::UIComponent::UIEvent event )
            {
                if ( event <= CManager::UIComponent::UIEvent::INVALID || event >= CManager::UIComponent::UIEvent::MAX_EVENTS )
                {
                    LOG(Logger::Level::ERROR) << "Invalid UIEvent specified." << std::endl;
                    return;
                }
                
                CManager::UIComponent::Background::setCallback( ID, callable, event );
            }
        }


//         
//         namespace UIContainer
//         {
//             
//         }
//         
//         
        namespace UIPictureFrame
        {
            /* Create a Picture widget with given ID and specified image and caption */
            bool create( const std::string& ID, const TextureID tID, const int sWidth, const int sHeight, const std::string& text );
            
            void destroy( const std::string& ID );
            
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
            
            void setVisibility( const std::string& ID, const bool visibility );
        }
        
        /* NOTE: This widget is only relevant to the map editor */
        namespace UITileBox
        {
            bool create( const std::string& ID );
            
            void destroy( const std::string& ID );
            
            void setPosition( const std::string& ID, const sf::Vector2f position );
            
            const sf::Vector2f getPosition( const std::string& ID );
            
            const sf::Vector2f getSize( const std::string& ID );
            
            void shiftByRows( const std::string& ID, const int rows, const int direction );
            
            void shiftUpByRows( const std::string& ID, const int rows );
            
            void shiftDownByRows( const std::string& ID, const int rows );
        }
//         
//         namespace UIRadioButton
//         {
//             /* Create a radio button with specified ID and caption */
//             bool create( const std::string& ID, const std::string& text );
//             
//             /* Set the position of a radio button */
//             void setPosition( const std::string& ID, const sf::Vector2f& position );
//         }
//         
//         namespace UIListItem
//         {
//             bool create( const std::string& ID, const std::string& text );
//             
//             void setPosition( const std::string& ID, const sf::Vector2f& position );
//             
//             const sf::Vector2f getPosition( const std::string& ID );
//             
//             const sf::Vector2f getSize( const std::string& ID );
//         }
//         
//         namespace UIListBox
//         {
//             bool create( const std::string& ID );//, const std::string& text );
//             
//             /* Add UIListItem identified by `mID` to the UIListBox identified by `ID` */
//             void add( const std::string& ID, const std::string& wID );
//             
//             void setPosition( const std::string& ID, const sf::Vector2f& position );
//         }
//         
//         namespace UIComboBox
//         {
//             bool create( const std::string& ID, std::vector<std::string>& wID );
//             
//             void add( const std::string& ID, const std::string& wID );
//             
//             void setPosition( const std::string& ID, const sf::Vector2f& position );
//         }

//         class EventHandler
//         {
//             public:
//                 
//                 enum class UIEvent
//                 {
//                     NONE,
//                     BUTTON_PRESSED,
//                     MAX_EVENTS
//                 };
//         
//             public:
//                 
//                 /* Bind the callable `cb` to a widget identified by `ID` for the specified UI `event` */
//                 static void addEventCallback( const std::string& ID, Callback cb, UIEvent event );
//                 
//                 static void handleEvents();
//                 
//             private:
//                 
//                 /* Store the callbacks for all the buttons */
//                 static std::map<std::pair<std::string, UIEvent>, Callback> menu_button_callbacks;
//         };
    }
}

#endif // UI_MANAGER_HPP
