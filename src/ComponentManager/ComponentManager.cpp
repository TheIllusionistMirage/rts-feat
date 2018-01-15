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
 *  Contains implementation of the methods & classes declared
 *  in ComponentManager module.
 */

#include <memory>
#include <algorithm>
#include <functional>
#include <cmath>

#include <SFML/Window/Event.hpp>

#include "Utility/Log.hpp"
#include "Utility/Constants.hpp"
#include "Utility/System.hpp"
#include "ComponentManager/ComponentManager.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {   
            // Initialize the static maps
            std::map<std::string, C_UICaption::Ptr> Caption::captions = {};
            std::map<std::string, C_UIBackground::Ptr> Background::backgrounds = {};
            std::map<std::string, C_UIScrollBar::Ptr> ScrollBar::scrollbars = {};
            std::map<std::string, C_UIGroup::Ptr> Group::groups = {};
            
            std::map<std::pair<std::string, UIEvent>, Callback> Caption::caption_callbacks = {};
            std::map<std::pair<std::string, UIEvent>, Callback> Background::background_callbacks = {};
            std::map<std::pair<std::string, UIEvent>, Callback> ScrollBar::scrollbar_callbacks = {};
            
            ////////////////////////
            // Caption operations //
            ////////////////////////
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            bool Caption::create( const std::string& ID,
                                  const std::string& text,
                                  const FontID fontID,
                                  const int charSize,
                                  const sf::Color fontColor )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a Caption component" << std::endl;
                    return false;
                }
                
                if ( isStrWS( text ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid caption text used for creating a Caption component" << std::endl;
                    return false;
                }
                
                if ( captions.find( ID ) != captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") already exists" << std::endl;
                    return false;
                }
                
                captions[ID] = std::make_shared<C_UICaption>( text, fontID, charSize, fontColor );
                
                LOG(Logger::Level::DEBUG) << "New Caption component with ID: " + ID + " created." << std::endl;
                return true;
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::destroy( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                captions.erase( it );
                LOG(Logger::Level::DEBUG) << "Destroyed Caption component with ID: " + ID << std::endl;
                
                //auto cit = caption_callbacks.find( ID )
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setCaption( const std::string& ID, const std::string& text )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_text.setString( text );
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            const std::string Caption::getCaption( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return UI_INVALID_STRING;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return UI_INVALID_STRING;
                }
                
                return it->second->m_text.getString().toAnsiString();
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_text.setPosition( position );
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            const sf::Vector2f Caption::getPosition( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return {};
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return { it->second->m_text.getGlobalBounds().left,
                          it->second->m_text.getGlobalBounds().top };
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            const sf::Vector2f Caption::getSize( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return {};
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return sf::Vector2f{ it->second->m_text.getGlobalBounds().width,
                                      it->second->m_text.getGlobalBounds().height };
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setCharSize( const std::string& ID, const int size )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                if ( size < 10 || size > 72 )
                {
                    LOG(Logger::Level::ERROR) << "Invalid character size for Caption component: " << size << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_text.setCharacterSize(size);
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setFont( const std::string& ID, FontID font )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_text.setFont( *ResourceManager::getFont( font ) );
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setFontColor( const std::string& ID, const sf::Color fontColor )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_text.setFillColor( fontColor );
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setVisibility( const std::string& ID, const bool visibility )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second ->m_visible = visibility;
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setOrigin( const std::string& ID, const sf::Vector2f& origin )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_text.setOrigin( origin );
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void Caption::setCallback( const std::string& ID,
                                       Callback cb,
                                       UIEvent event )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                caption_callbacks[ std::make_pair(ID, event) ] = cb;
            }
            
            
            
            ///////////////////////////
            // Background operations //
            ///////////////////////////
            
            bool Background::create( const std::string& ID, const TextureID texID, const int sWidth, const int sHeight, bool mode  )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a Background component" << std::endl;
                    return false;
                }
                
                if ( backgrounds.find( ID ) != backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") already exists" << std::endl;
                    return false;
                }
                
                backgrounds[ID] = std::make_shared<C_UIBackground>( texID, sWidth, sHeight );
                backgrounds[ID]->m_multiTexMode = mode;
                
                LOG(Logger::Level::DEBUG) << "New Background component with ID: " + ID + " created." << std::endl;
                return true;
            }
                    
            void Background::destroy( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                backgrounds.erase( it );
                LOG(Logger::Level::DEBUG) << "Destroyed Background component with ID: " + ID << std::endl;
            }
            
            void Background::setTexture( const std::string& ID, TextureID texID, const int sWidth, const int sHeight )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_sWidth = sWidth;
                it->second->m_sHeight = sHeight;
                it->second->m_state = C_UIBackground::State::NORMAL;
                
                it->second->m_background.setTexture( *ResourceManager::getTexture( texID ) );
                it->second->m_background.setTextureRect( sf::IntRect{ static_cast<int>( it->second->m_state ) * sWidth, 0, sWidth, sHeight } );
                
                LOG(Logger::Level::DEBUG) << "Updated the texture of Background component with ID(" + ID + ") to (" + textureIDToStr( texID ) + ")" << std::endl;
            }
            
            void Background::setState( const std::string& ID, C_UIBackground::State state )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                if ( state <= C_UIBackground::State::INVALID || state >= C_UIBackground::State::MAX_STATE )
                {
                    LOG(Logger::Level::ERROR) << "Cannot change state of Background component to an invalid state" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                if ( !it->second->m_multiTexMode )
                    return;
                
                it->second->m_state = state;                
                it->second->m_background.setTextureRect( sf::IntRect{ static_cast<int>( it->second->m_state ) * it->second->m_sWidth, 0, it->second->m_sWidth, it->second->m_sHeight } );
                
                //LOG(Logger::Level::DEBUG) << "Updated the state of Background component with ID(" + ID + ")" << std::endl;
            }
            
            C_UIBackground::State Background::getState( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return C_UIBackground::State::INVALID;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return C_UIBackground::State::INVALID;
                }
                
                return it->second->m_state;
            }
            
            void Background::setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_background.setPosition( position );
            }
            
            const sf::Vector2f Background::getPosition( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return {};
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                //return it->second->m_background.getPosition();
                
                return { it->second->m_background.getGlobalBounds().left,
                          it->second->m_background.getGlobalBounds().top };
                
//                 return { it->second->m_background.getPosition().x - it->second->m_background.getGlobalBounds().width / 2,
//                           it->second->m_background.getPosition().y - it->second->m_background. getGlobalBounds().height / 2 };
            }
            
            void Background::setSize( const std::string& ID, const sf::Vector2f& size )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                sf::Vector2f bgSize{ it->second->m_background.getGlobalBounds().width,
                                      it->second->m_background.getGlobalBounds().height };
                //it->second->m_background.setScale( size.x / bgSize.x, size.y / bgSize.y );
                it->second->m_background.scale( size.x / bgSize.x, size.y / bgSize.y );
            }
            
            const sf::Vector2f Background::getSize( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return {};
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return { it->second->m_background.getGlobalBounds().width,
                          it->second->m_background.getGlobalBounds().height };
            }
            
            void Background::setVisibility( const std::string& ID, const bool visibility )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_visible = visibility;
            }
            
            void Background::setCallback( const std::string& ID,
                                          Callback cb,
                                          UIEvent event )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                background_callbacks[ std::make_pair(ID, event) ] = cb;
            }
            
            void Background::setCallback2( const std::string& ID,
                                           Callback2 cb,
                                           UIEvent event )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                background_callbacks_2[ std::make_pair(ID, event) ] = cb;
            }
            
            
            ///////////////////
            // UI Scroll bar //
            ///////////////////
            
            bool ScrollBar::create( const std::string& ID, const int scrollHeight )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a ScrollBar component" << std::endl;
                    return false;
                }
                
                if ( scrollbars.find( ID ) != scrollbars.end() )
                {
                    LOG(Logger::Level::ERROR) << "A ScrollBar component with the given key(" + ID + ") already exists" << std::endl;
                    return false;
                }
                
                scrollbars[ID] = std::make_shared<C_UIScrollBar>( scrollHeight );
                setPosition( ID, { 0, 0 } );
                
                LOG(Logger::Level::DEBUG) << "ScrollBar component with ID: " + ID + " created." << std::endl;
                return true;
            }
                    
            void ScrollBar::destroy( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a ScrollBar component" << std::endl;
                    return;
                }
                
                auto it = scrollbars.find( ID );
                if ( it == scrollbars.end() )
                {
                    LOG(Logger::Level::ERROR) << "A ScrollBar component with the given key(" + ID + ") does not exist" << std::endl;
                    return;
                }
                
                scrollbars.erase( it );
            }
            
            void ScrollBar::setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a ScrollBar component" << std::endl;
                    return;
                }
                
                auto it = scrollbars.find( ID );
                if ( it == scrollbars.end() )
                {
                    LOG(Logger::Level::ERROR) << "A ScrollBar component with the given key(" + ID + ") does not exist" << std::endl;
                    return;
                }
                
                it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_AREA].setPosition( position );
                it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_UP].setPosition( position );
                auto arrUpHeight = it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_UP].getGlobalBounds().height;
                it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].setPosition( { position.x, position.y + arrUpHeight } );
                auto sAreaHeight = it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_AREA].getGlobalBounds().height;
                auto sArrDHeight = it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_DOWN].getGlobalBounds().height;
                it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_DOWN].setPosition( { position.x, position.y + sAreaHeight - sArrDHeight } );
            }
            
            const sf::Vector2f ScrollBar::getPosition( const std::string& ID )
            {
                
            }
            
            const sf::Vector2f ScrollBar::getSize( const std::string& ID )
            {
                
            }
            
            void ScrollBar::setVisibility( const std::string& ID, const bool visibility )
            {
                
            }
            
            void ScrollBar::setState( const std::string& ID, C_UIScrollBar::Rects rect, C_UIScrollBar::State state )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a ScrollBar component" << std::endl;
                    return;
                }
                
                auto it = scrollbars.find( ID );
                if ( it == scrollbars.end() )
                {
                    LOG(Logger::Level::ERROR) << "A ScrollBar component with the given key(" + ID + ") does not exist" << std::endl;
                    return;
                }
                
                it->second->m_state[rect] = state;
                it->second->m_sprite[rect].setTextureRect( sf::IntRect{ it->second->m_state[rect] * it->second->m_width, 0, it->second->m_width, it->second->m_height } );
            }
            
            void ScrollBar::setScrollAmount( const std::string& ID, const int scrollAmount )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a ScrollBar component" << std::endl;
                    return;
                }
                
                auto it = scrollbars.find( ID );
                if ( it == scrollbars.end() )
                {
                    LOG(Logger::Level::ERROR) << "A ScrollBar component with the given key(" + ID + ") does not exist" << std::endl;
                    return;
                }
                
                it->second->m_scrollAmount = scrollAmount;
            }
            
            void ScrollBar::setRowCount( const std::string& ID, const int rows )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a ScrollBar component" << std::endl;
                    return;
                }
                
                auto it = scrollbars.find( ID );
                if ( it == scrollbars.end() )
                {
                    LOG(Logger::Level::ERROR) << "A ScrollBar component with the given key(" + ID + ") does not exist" << std::endl;
                    return;
                }
                
                float scaleY = it->second->m_scrollHeight / ( it->second->m_scrollAmount * rows * 1.f );
                if ( scaleY < 0.1 )
                    scaleY = 0.1;
                else if ( scaleY > 1.f )
                    scaleY = 1.f;
                it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].scale( 1.f, scaleY );
                
                //it->second->deltaY = 8.f;//= ( it->second->m_scrollHeight * 1.f ) / it->second->m_scrollAmount;
                float diff = it->second->m_scrollHeight * 1.f - it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_DOWN].getGlobalBounds().height * 2.f - it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().height;
                
//                 std::cout << "a: " << it->second->m_scrollHeight * 1.f << std::endl;
//                 std::cout << "b: " << it->second->m_scrollAmount * rows * 1.f << std::endl;
//                 std::cout << "c: " << ( it->second->m_scrollHeight * it->second->m_scrollHeight * 1.f ) / ( it->second->m_scrollAmount * rows * 1.f ) << std::endl;
//                 std::cout << "d: " << it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().height << std::endl;
                
                std::cout << "diff: " << diff << std::endl;
                
                //float amt = diff / ( rows - std::ceil( it->second->m_scrollAmount * rows / ( it->second->m_scrollHeight - it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_DOWN].getGlobalBounds().height * 2.f ) ) );
                int limit;
                float h = 0.f;
                for ( limit = 0; limit <= rows && h < it->second->m_scrollHeight - it->second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_DOWN].getGlobalBounds().height * 2.f; ++limit )
                {
                    h += it->second->m_scrollAmount;
                }
                std::cout << "h: " << h <<std::endl;
                                
                float amt;
                if ( rows != limit )
                    amt = diff / ( rows - limit );
                else
                    amt = 0;
                std::cout << "limit: " << limit << std::endl;
                it->second->deltaY = amt ;
                
                std::cout << "Del: " << it->second->deltaY << std::endl;
            }
            
            void ScrollBar::setCallback( const std::string& ID,
                                         Callback cb,
                                         UIEvent event )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID(" << ID << ") used for accessing ScrollBar component" << std::endl;
                    return;
                }
                
                auto it = scrollbars.find( ID );
                
                if ( it == scrollbars.end() )
                {
                    LOG(Logger::Level::ERROR) << "A ScrollBar component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                scrollbar_callbacks[ std::make_pair(ID, event) ] = cb;
            }
            
            
            ///////////
            // Group //
            ///////////
            
            bool Group::create( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a Group component" << std::endl;
                    return false;
                }
                
                if ( groups.find( ID ) != groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") already exists" << std::endl;
                    return false;
                }
                
                groups[ID] = std::make_shared<C_UIGroup>( );
                
                LOG(Logger::Level::DEBUG) << "New Group component with ID: " + ID + " created." << std::endl;
                
                return true;
            }
            
            bool Group::create( const std::string& ID, const std::vector<std::string>& members )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a Group component" << std::endl;
                    return false;
                }
                
                if ( groups.find( ID ) != groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") already exists" << std::endl;
                    return false;
                }
                
                groups[ID] = std::make_shared<C_UIGroup>( members );
                
                LOG(Logger::Level::DEBUG) << "New Group component with ID: " + ID + " created." << std::endl;
                
                return true;
            }
            
            void Group::destroy( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Group component" << std::endl;
                    return;
                }
                
                auto it = groups.find( ID );
                
                if ( it == groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                groups.erase( it );
                LOG(Logger::Level::DEBUG) << "Destroyed Background component with ID: " + ID << std::endl;
            }
                    
            void Group::add( const std::string& ID, const std::string& wID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Group component" << std::endl;
                    return;
                }
                
                if ( isStrWS( wID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a UI widget" << std::endl;
                    return;
                }
                
                auto it = groups.find( ID );
                
                if ( it == groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                auto w = std::find( it->second->m_members.begin(), it->second->m_members.end(), wID );
                
                if ( w != it->second->m_members.end() )
                {
                    LOG(Logger::Level::ERROR) << "The Group component with the given key(" + ID + ") already contains the widget with ID(" + wID + ")" << std::endl;
                    return;
                }
                
                it->second->m_members.push_back( wID );
            }
            
            int Group:: count( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Group component" << std::endl;
                    return -1;
                }
                
                auto it = groups.find( ID );
                
                if ( it == groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") does not exist." << std::endl;
                    return -1;
                }
                
                return it->second->m_members.size();
            }
            
            std::string Group::first( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Group component" << std::endl;
                    return UI_INVALID_COMPONENT_ID;
                }
                
                auto it = groups.find( ID );
                
                if ( it == groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") does not exist." << std::endl;
                    return UI_INVALID_COMPONENT_ID;
                }
                
                if ( it->second->m_members.size() >= 1 )
                    return it->second->m_members.front();
                return UI_INVALID_COMPONENT_ID;
            }
                    
            std::string Group::last( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Group component" << std::endl;
                    return UI_INVALID_COMPONENT_ID;
                }
                
                auto it = groups.find( ID );
                
                if ( it == groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") does not exist." << std::endl;
                    return UI_INVALID_COMPONENT_ID;
                }
                
                if ( it->second->m_members.size() >= 1 )
                    return it->second->m_members.back();
                return UI_INVALID_COMPONENT_ID;
            }
            
            std::vector<std::string> Group::get( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Group component" << std::endl;
                    return {};
                }
                
                auto it = groups.find( ID );
                
                if ( it == groups.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Group component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return it->second->m_members;
            }
            
            
            // UI update and render operations
            
            void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt )
            {
                // Used only for scrollbars, denotes the amount of scrolling done
                //static float scrollY = 0.f;
                static float scrollStart = 0.f;
                static float scrollPos = 0.f;
                
                // This variable denotes whether a mouse button is currently pressed
                // or not, i.e., it is TRUE between the `sf::Event::MouseButtonPressed`
                // to the `sf::Event::MouseButtonReleased` SFML window events.
                static bool m_mouseDown = false;
                
                // This variable denotes the ID of the Scrollbar component currently
                // pressed by the mouse. If no Scrollbar is currently pressed by the
                // mouse, it equals to `UI_INVALID_COMPONENT_ID`.
                static std::string m_scrollComponentPressed = UI_INVALID_COMPONENT_ID;
                
                // Handle discrete events here
                switch (event.type)
                {
                    case sf::Event::MouseButtonPressed:
                    {
                        m_mouseDown = true;
                        
                        // Handle Background components
                        for ( auto&& bg : Background::backgrounds )
                        {
                            if (bg.second->m_enabled && bg.second->m_visible && bg.second->m_background.getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                            {
                                // Update the state
                                if ( bg.second->m_multiTexMode )
                                    Background::setState( bg.first, C_UIBackground::State::DOWN );
                                
                                // Handle the mouse button release events
                                auto it = Background::background_callbacks.find( {bg.first, UIEvent::MOUSE_PRESSED} );
                                if ( it != Background::background_callbacks.end() )
                                    it->second();
                                
                                auto it2 = Background::background_callbacks.find( {bg.first, UIEvent::TILE_BOX_ITEM_SELECTED } );
                                if ( it2 != Background::background_callbacks.end() )
                                    it2->second();
                            }
                        }
                        
                        // Handle ScrollBar components
                        for ( auto&& sb : ScrollBar::scrollbars )
                        {
                            for ( int rect = C_UIScrollBar::Rects::SCROLL_AREA; rect <= C_UIScrollBar::Rects::SCROLL_ARROW_DOWN; ++rect )
                            {
                                if ( sb.second->m_enabled && sb.second->m_visible && sb.second->m_sprite[rect].getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                                {
                                    ScrollBar::setState( sb.first, static_cast<C_UIScrollBar::Rects>( rect ), C_UIScrollBar::State::DOWN );
                                    
                                    //if ( rect == C_UIScrollBar::Rects::SCROLL_AREA )
                                    if ( rect == C_UIScrollBar::Rects::SCROLL_BAR )
                                    {
                                        scrollStart = mousePos.y;
                                        scrollPos = sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().top;
                                        m_scrollComponentPressed = sb.first;
                                    }
                                    else
                                    {
                                        if ( rect == C_UIScrollBar::Rects::SCROLL_ARROW_UP )
                                        {
                                            if ( sb.second->deltaY > 0.f && sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().top - sb.second->deltaY - 0 >= sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_UP].getGlobalBounds().top + sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_UP].getGlobalBounds().height )
                                            {
                                                sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].setPosition( sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().left, sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().top - sb.second->deltaY );
                                                
                                                auto it = ScrollBar::scrollbar_callbacks.find( { sb.first, UIEvent::SCROLL_DRAGGED_UP } );
                                                if ( it != ScrollBar::scrollbar_callbacks.end() )
                                                    it->second();
                                            }
                                        }
                                        
                                        else if ( rect == C_UIScrollBar::Rects::SCROLL_ARROW_DOWN )
                                        {
                                            if ( sb.second->deltaY > 0.f && sb.second->deltaY + sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().top + sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().height - 1 <= sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_DOWN].getGlobalBounds().top )
                                            {
                                                sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].setPosition( sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().left, sb.second->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().top + sb.second->deltaY );
                                                
                                                auto it = ScrollBar::scrollbar_callbacks.find( { sb.first, UIEvent::SCROLL_DRAGGED_DOWN } );
                                                if ( it != ScrollBar::scrollbar_callbacks.end() )
                                                    it->second();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } break;
                    
                    case sf::Event::MouseMoved:
                    {
                        // Handle Background components
                        if ( m_scrollComponentPressed == UI_INVALID_COMPONENT_ID )
                        {
                            for ( auto&& bg : Background::backgrounds )
                            {
                                if (bg.second->m_enabled && bg.second->m_visible && bg.second->m_background.getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                                {
                                    if ( bg.second->m_multiTexMode )
                                        Background::setState( bg.first, C_UIBackground::State::HOVER );
                                    else
                                    {
                                        bg.second->m_background.setColor( sf::Color( 100, 100, 100 ) );
                                        //Caption::captions[bg.first]->m_text.setFillColor( sf::Color::Red );
                                    }
                                }
                                else
                                {
                                    if ( bg.second->m_multiTexMode )
                                        Background::setState( bg.first, C_UIBackground::State::NORMAL );
                                    else
                                    {
                                        bg.second->m_background.setColor( sf::Color( 255, 255, 255 ) );
                                        //Caption::captions[bg.first]->m_text.setFillColor( sf::Color::White );
                                    }
                                }
                            }
                        }
                        
                        // Handle ScrollBar components
                        for ( auto&& sb : ScrollBar::scrollbars )
                        {
                            for ( int rect = C_UIScrollBar::Rects::SCROLL_AREA; rect <= C_UIScrollBar::Rects::SCROLL_ARROW_DOWN; ++rect )
                            {
                                if ( sb.second->m_enabled && sb.second->m_visible && sb.second->m_sprite[rect].getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                                {
                                    ScrollBar::setState( sb.first, static_cast<C_UIScrollBar::Rects>( rect ), C_UIScrollBar::State::HOVER );
                                }
                                else
                                {
                                    ScrollBar::setState( sb.first, static_cast<C_UIScrollBar::Rects>( rect ), C_UIScrollBar::State::NORMAL );
                                }
                            }
                        }
                    } break;
                    
                    case sf::Event::MouseButtonReleased:
                    {
                        m_mouseDown = false;
                        m_scrollComponentPressed = UI_INVALID_COMPONENT_ID;
                        
                        // Handle Background components
                        for ( auto&& bg : Background::backgrounds )
                        {
                            if (bg.second->m_enabled && bg.second->m_visible && bg.second->m_background.getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                            {
                                // Update the state
                                if ( bg.second->m_multiTexMode )
                                    Background::setState( bg.first, C_UIBackground::State::HOVER );
                                
                                // Handle the mouse button release events
                                auto it = Background::background_callbacks.find( {bg.first, UIEvent::MOUSE_RELEASED} );
                                if ( it != Background::background_callbacks.end() )
                                    it->second();
                            }
                        }
                        
                        // Handle ScrollBar components
                        for ( auto&& sb : ScrollBar::scrollbars )
                        {
                            for ( int rect = C_UIScrollBar::Rects::SCROLL_AREA; rect <= C_UIScrollBar::Rects::SCROLL_ARROW_DOWN; ++rect )
                            {
                                if ( sb.second->m_enabled && sb.second->m_visible && sb.second->m_sprite[rect].getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                                {
                                    ScrollBar::setState( sb.first, static_cast<C_UIScrollBar::Rects>( rect ), C_UIScrollBar::State::HOVER );
                                }
                            }
                        }
                        
                    } break;
                    
                    default:
                        return;
                }
                
                // Handle real-time events here
                
                // Handle mouse dragging event
                if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
                {
                    // Handle the mouse drag event if it pertains to a Scrollbar component
                    if ( m_scrollComponentPressed != UI_INVALID_COMPONENT_ID )
                    {
                        // Here two cases of real time input are possible:
                        //  1. Scrollbar is being dragged
                        //  2. Scrollbar arrows are being pressed
                        
                        auto scrollID = m_scrollComponentPressed;
                        auto sb = ScrollBar::scrollbars[scrollID];                    
                        int rect = C_UIScrollBar::Rects::SCROLL_BAR;
                                                
                        // Handle case 1
                        if ( sb->deltaY > 0.f && sb->m_enabled && sb->m_visible )
                        {
                            rect = C_UIScrollBar::Rects::SCROLL_BAR;
                            ScrollBar::setState( scrollID, static_cast<C_UIScrollBar::Rects>( rect ), C_UIScrollBar::State::DOWN );
                            
                            if ( std::abs( mousePos.y - scrollStart ) > sb->deltaY )
                            {
                                int sign = ( mousePos.y - scrollStart < 0 ? -1 : 1 );
                                
                                if ( scrollPos + sign * sb->deltaY + 1 >= sb->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_UP].getGlobalBounds().top + sb->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_UP].getGlobalBounds().height &&
                                        scrollPos + sign * sb->deltaY + sb->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].getGlobalBounds().height - 1 <= sb->m_sprite[C_UIScrollBar::Rects::SCROLL_ARROW_DOWN].getGlobalBounds().top )
                                {
                                    sb->m_sprite[C_UIScrollBar::Rects::SCROLL_BAR].setPosition( sb->m_sprite[rect].getGlobalBounds().left, scrollPos + sign * sb->deltaY );
                                    scrollPos += sign * sb->deltaY;
                                    scrollStart += sign * sb->deltaY;
                                    
                                    // Execute the callable if one bound to the scrollbar
                                    
                                    UIEvent scrollType = sign < 1 ? UIEvent::SCROLL_DRAGGED_UP : UIEvent::SCROLL_DRAGGED_DOWN;
                                    
                                    auto it = ScrollBar::scrollbar_callbacks.find( { scrollID, scrollType } );
                                    if ( it != ScrollBar::scrollbar_callbacks.end() )
                                        it->second();
                                }
                            }
                        }
                    }
                }
            }
            
            void renderUIComponents( sf::RenderWindow& window )
            {
                for ( auto&& bg : Background::backgrounds )
                {
                    if ( bg.second->m_visible )
                    {
                        window.draw( *bg.second);
                    }
                }
                
                for ( auto&& sb : ScrollBar::scrollbars )
                {
                    if ( sb.second->m_visible )
                    {
                        window.draw( *sb.second );
                    }
                }
                
                for ( auto&& cap : Caption::captions )
                {
                    if ( cap.second->m_visible )
                    {
                        window.draw( *cap.second );
                    }
                }
            }
        }
    }
}
