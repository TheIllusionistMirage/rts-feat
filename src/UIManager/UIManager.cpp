/*
 * ---------------------------
 *  Module : UIManager
 * ---------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods declared in UIManager
 *  module.
 */

#include "Utility/Log.hpp"
#include "Utility/Constants.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "UIManager/UIManager.hpp"

namespace rts
{
    namespace UIManager
    {
        //////////////////////////////////////////////////////////////////////
        //                         UI Default Label                         //
        //////////////////////////////////////////////////////////////////////
        
        namespace UILabel
        {
            bool create( const std::string& ID,
                         const std::string& text )
            {
                if ( CManager::UIComponent::Caption::create( ID, text, FontID::SOURCE_HAN_SANS_CN_NORMAL, 11, sf::Color::White ) )
                {
                    LOG(Logger::Level::DEBUG) << "UILabel instance with ID: " + ID + " and Caption: " + text + " created." << std::endl;
                    return true;
                }
                
                LOG(Logger::Level::ERROR) << "Unable to create UILabel instance with ID: " + ID << std::endl;
                return false;
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            void destroy( const std::string& ID )
            {
                CManager::UIComponent::Caption::destroy( ID );
                LOG(Logger::Level::DEBUG) << "UILabel instance with ID: " + ID + " destroyed." << std::endl;
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
            }
            
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            const std::string getCaption( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getCaption( ID );
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Caption::setPosition( ID, position );
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getPosition( ID );
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getSize( ID );
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            void setCharSize( const std::string& ID, const int size )
            {
                CManager::UIComponent::Caption::setCharSize( ID, size );
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            void setFont( const std::string& ID, FontID font )
            {
                CManager::UIComponent::Caption::setFont( ID, font );
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            void setVisibility( const std::string& ID, const bool visibility )
            {
                CManager::UIComponent::Caption::setVisibility( ID, visibility );
            }
            
            ////////////////////////////////////////////////////////////////////////////////////
            
            void setOrigin( const std::string& ID,
                                   const sf::Vector2f& origin )
            {
                CManager::UIComponent::Caption::setOrigin( ID, origin );
            }
        }
        
        //////////////////////////////////////////////////////////////////////
        //                        UI Default Button                         //
        //////////////////////////////////////////////////////////////////////
        
        namespace UIButton
        {
            bool create( const std::string& ID, const std::string& text )
            {
                // A UIButton uses two components - Background & Caption
                
                if ( !CManager::UIComponent::Caption::create( ID, text, FontID::SOURCE_HAN_SANS_CN_NORMAL, 12, sf::Color::White ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Caption instance with ID: " + ID << std::endl;
                    return false;
                }
                
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                
                if ( !CManager::UIComponent::Background::create( ID, TextureID::UI_DEFAULT_BUTTON, UI_DEFAULT_BUTTON_TEXTURE_WIDTH, UI_DEFAULT_BUTTON_TEXTURE_HEIGHT, true ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Background instance with ID: " + ID << std::endl;
                    return false;
                }
                
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 20 } );
                //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ 200, 50 } );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );
                
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2, bgPos.y + bgSize.y / 2.5f } );
                
                LOG(Logger::Level::DEBUG) << "UIButton instance with ID: " + ID + " and Caption: " + text + " created." << std::endl;
                
                return true;
            }
            
            void destroy( const std::string& ID )
            {
                CManager::UIComponent::Background::destroy( ID );
                CManager::UIComponent::Caption::destroy( ID );
                
                LOG(Logger::Level::DEBUG) << "UIButton instance with ID: " + ID + " destroyed." << std::endl;
            }
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 30 } );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ 200, 50 } );
                
                setPosition( ID, getPosition( ID ) );
            }
            
            const std::string getCaption( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getCaption( ID );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Background::setPosition( ID, position );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2, bgPos.y + bgSize.y / 2.5f } );
            }
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Background::getPosition( ID );
            }
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                return CManager::UIComponent::Background::getSize( ID );
            }
            
            void setCharSize( const std::string& ID, const int size )
            {
                CManager::UIComponent::Caption::setCharSize( ID, size );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 20 } );
                //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ 200, 50 } );
                //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x * 1.05f, cSize.y * 1.6f } );
                setPosition( ID, getPosition( ID ) );
            }
            
            void setFont( const std::string& ID, FontID font )
            {
                CManager::UIComponent::Caption::setFont( ID, font );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 30 } );
            }
            
            void setVisibility( const std::string& ID, const bool visibility )
            {
                CManager::UIComponent::Caption::setVisibility( ID, visibility );
                CManager::UIComponent::Background::setVisibility( ID, visibility );
            }
            
            void setCallback( const std::string& ID, CManager::UIComponent::Callback cb, CManager::UIComponent::UIEvent event )
            {
                if ( event <= CManager::UIComponent::UIEvent::INVALID || event >= CManager::UIComponent::UIEvent::MAX_EVENTS )
                {
                    LOG(Logger::Level::ERROR) << "Invalid UIEvent specified." << std::endl;
                    return;
                }
                
                CManager::UIComponent::Background::setCallback( ID, cb, event );
            }
        }
        
        //////////////////////////////////////////////////////////////////////
        //                          UI Menu Button                          //
        //////////////////////////////////////////////////////////////////////
        
        namespace UIMenuButton
        {
            bool create( const std::string& ID, const std::string& text )
            {
                // A UIButton uses two components - Background & Caption
                
                if ( !CManager::UIComponent::Caption::create( ID, text, FontID::GARAMOND_BOLD, 20, sf::Color::White ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Caption instance with ID: " + ID << std::endl;
                    return false;
                }
                
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                
                if ( !CManager::UIComponent::Background::create( ID, TextureID::UI_MENU_BUTTON, UI_MENU_BUTTON_TEXTURE_WIDTH, UI_MENU_BUTTON_TEXTURE_HEIGHT, true ) )
                //if ( !CManager::UIComponent::Background::create( ID, TextureID::UI_DEFAULT_BUTTON, UI_DEFAULT_BUTTON_TEXTURE_WIDTH, UI_DEFAULT_BUTTON_TEXTURE_HEIGHT ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Background instance with ID: " + ID << std::endl;
                    return false;
                }
                
                //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 30 } );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ 250, 60 } );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );
                
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2, bgPos.y + bgSize.y / 2.5f } );
                
                LOG(Logger::Level::DEBUG) << "UIButton instance with ID: " + ID + " and Caption: " + text + " created." << std::endl;
                
                return true;
            }
            
            void destroy( const std::string& ID )
            {
                CManager::UIComponent::Background::destroy( ID );
                CManager::UIComponent::Caption::destroy( ID );
                
                LOG(Logger::Level::DEBUG) << "UIButton instance with ID: " + ID + " destroyed." << std::endl;
            }
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 30 } );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ 200, 50 } );
                
                setPosition( ID, getPosition( ID ) );
            }
            
            const std::string getCaption( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getCaption( ID );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Background::setPosition( ID, position );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2, bgPos.y + bgSize.y / 2.5f } );
            }
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Background::getPosition( ID );
            }
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                return CManager::UIComponent::Background::getSize( ID );
            }
            
//             void setCharSize( const std::string& ID, const int size )
//             {
//                 CManager::UIComponent::Caption::setCharSize( ID, size );
//                 auto cSize = CManager::UIComponent::Caption::getSize( ID );
//                 CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
//                 //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 30 } );
//                 CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ 200, 50 } );
//                 //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x * 1.05f, cSize.y * 1.6f } );
//                 setPosition( ID, getPosition( ID ) );
//             }
//             
//             void setFont( const std::string& ID, FontID font )
//             {
//                 CManager::UIComponent::Caption::setFont( ID, font );
//                 auto cSize = CManager::UIComponent::Caption::getSize( ID );
//                 CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 70, cSize.y + 30 } );
//             }
            
            void setVisibility( const std::string& ID, const bool visibility )
            {
                CManager::UIComponent::Caption::setVisibility( ID, visibility );
                CManager::UIComponent::Background::setVisibility( ID, visibility );
            }
            
            void setCallback( const std::string& ID, CManager::UIComponent::Callback cb, CManager::UIComponent::UIEvent event )
            {
                if ( event <= CManager::UIComponent::UIEvent::INVALID || event >= CManager::UIComponent::UIEvent::MAX_EVENTS )
                {
                    LOG(Logger::Level::ERROR) << "Invalid UIEvent specified." << std::endl;
                    return;
                }
                
                CManager::UIComponent::Background::setCallback( ID, cb, event );
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        //                                      UI Picture                                         //
        /////////////////////////////////////////////////////////////////////////////////////////////
        
        namespace UIPictureFrame
        {
            bool create( const std::string& ID, const TextureID tID, const int sWidth, const int sHeight, const std::string& text )
            {
                if ( !CManager::UIComponent::Background::create( ID, tID, sWidth, sHeight, false ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Background instance with ID: " + ID << std::endl;
                    return false;
                }
                
                if ( !CManager::UIComponent::Caption::create( ID, text, FontID::SOURCE_HAN_SANS_CN_NORMAL, 11, sf::Color::White ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Caption instance with ID: " + ID << std::endl;
                    return false;
                }
                
                auto bgPos  = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, 0 } );                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2.f,
                                                                                bgPos.y + bgSize.y + 5 } );
                
                return true;
            }
            
            void setPicture( const std::string& ID, const TextureID tID, const int sWidth, const int sHeight )
            {
                CManager::UIComponent::Background::setTexture( ID, tID, sWidth, sHeight );
            }
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Background::setPosition( ID, position );
                
                auto bgPos  = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, 0 } );
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2.f,
                                                                                bgPos.y + bgSize.y + 5 } );
            }
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Background::getPosition( ID );
            }
            
            void setSize( const std::string& ID, const sf::Vector2f& size )
            {
                CManager::UIComponent::Background::setSize( ID, size );
                
                auto bgPos  = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, 0 } );
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2.f,
                                                                                bgPos.y + bgSize.y + 5 } );
            }
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                return CManager::UIComponent::Background::getSize( ID );
            }
        }
        
        namespace UITileBox
        {
            bool create( const std::string& ID )
            {
                if ( !CManager::UIComponent::Caption::create( ID + "-title-cap", "   Available Tiles:   ", FontID::SOURCE_HAN_SANS_CN_NORMAL, 11, sf::Color::White ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create UITileBox instance with ID: " + ID << std::endl;
                    return false;
                }
                
                auto tcSize = CManager::UIComponent::Caption::getSize( ID + "-title-cap" );
                CManager::UIComponent::Caption::setOrigin( ID + "-title-cap", { tcSize.x / 2.f, tcSize.y / 2.f } );
                
                if ( !CManager::UIComponent::Background::create( ID + "-title-bg", TextureID::UI_TILEBOX, UI_TILEBOX_TEXTURE_WIDTH, UI_TILEBOX_TEXTURE_HEIGHT, true ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create UITileBox instance with ID: " + ID << std::endl;
                    return false;
                }
                
                CManager::UIComponent::Background::setSize( ID + "-title-bg", { tcSize.x + 100, tcSize.y + 20 } );
                
                if ( !CManager::UIComponent::Background::create( ID + "-box-bg", TextureID::UI_TILEBOX, UI_TILEBOX_TEXTURE_WIDTH, UI_TILEBOX_TEXTURE_HEIGHT, true ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create UITileBox instance with ID: " + ID << std::endl;
                    return false;
                }
                
                auto tbgSize = CManager::UIComponent::Background::getSize( ID + "-title-bg" );
                CManager::UIComponent::Background::setSize( ID + "-box-bg", { tbgSize.x, 200 } );
                
                CManager::UIComponent::ScrollBar::create( ID, CManager::UIComponent::Background::getSize( ID + "-box-bg" ).y );
                CManager::UIComponent::ScrollBar::setScrollAmount( ID, 20 );
                
                UIManager::UITileBox::setPosition( ID, { 0, 0 } );
                
                // Tile box picture frames
                
                UIManager::UIPictureFrame::create( "t1", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t1", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic", { 5, 100 } );
        
                UIManager::UIPictureFrame::create( "t2", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t2", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic2", { 60, 100 } );
                
                UIManager::UIPictureFrame::create( "t3", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t3", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic3", { 115, 100 } );
                
                std::vector<std::string> members = { "t1", "t2", "t3" };
                
                CManager::UIComponent::Group::create( ID + "-group", members );
                
                // Align the picture franmes
                
//                 auto bgPos = CManager::UIComponent::Background(  );
//                 UIManager::UIPictureFrame::setPosition( "t1",  );
                
                return true;
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f position )
            {
                CManager::UIComponent::Background::setPosition( ID + "-title-bg", position );
                auto tbgSize = CManager::UIComponent::Background::getSize( ID + "-title-bg" );
                CManager::UIComponent::Caption::setPosition( ID + "-title-cap", { position.x + tbgSize.x / 2.f, position.y + tbgSize.y / 2.5f } );
                CManager::UIComponent::Background::setPosition( ID + "-box-bg",  { position.x, position.y + tbgSize.y + 5 } );
                CManager::UIComponent::ScrollBar::setPosition( ID, { position.x + tbgSize.x - 15.f, position.y + tbgSize.y + 5 } );
            }
        }
//         
//         namespace UIRadioButton
//         {
//             bool create( const std::string& ID, const std::string& text )
//             {
//                 if ( !CManager::UIComponent::Background::create( ID, TextureID::UI_RADIO_BUTTON_NORMAL, UI_RADIOBUTTON_TEXTURE_WIDTH, UI_RADIOBUTTON_TEXTURE_HEIGHT ) )
//                 {
//                     LOG(Logger::Level::ERROR) << "Unable to create UIRadioButton instance with ID: " << ID << std::endl;
//                     return false;
//                 }
//                 
//                 if ( !CManager::UIComponent::Caption::create( ID, text ) )
//                 {
//                     LOG(Logger::Level::ERROR) << "Unable to create UIRadioButton instance with ID: " << ID << std::endl;
//                     return false;
//                 }
//                 
//                 auto bPos = CManager::UIComponent::Background::getPosition( ID );
//                 auto bSize = CManager::UIComponent::Background::getSize( ID );
//                 auto cSize = CManager::UIComponent::Caption::getSize( ID );
//                 
//                 CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ 0, cSize.y / 2.5f } );
//                 CManager::UIComponent::Caption::setPosition( ID, { bPos.x + bSize.x + 10, bPos.y + bSize.y / 2.5f } );
//                 
//                 return true;
//             }
//             
//             void setPosition( const std::string& ID, const sf::Vector2f& position )
//             {
//                 CManager::UIComponent::Background::setPosition( ID, position );
//                 auto bPos = CManager::UIComponent::Background::getPosition( ID );
//                 auto bSize = CManager::UIComponent::Background::getSize( ID );
//                 auto cSize = CManager::UIComponent::Caption::getSize( ID );
//                 
//                 CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ 0, cSize.y / 2.5f } );
//                 CManager::UIComponent::Caption::setPosition( ID, { bPos.x + bSize.x + 10, bPos.y + bSize.y / 2.5f } );
//             }
//         }
//         
//         namespace UIListItem
//         {
//             bool create( const std::string& ID, const std::string& text )
//             {
//                 if ( !CManager::UIComponent::Background::create( ID, TextureID::UI_LISTITEM, UI_LISTITEM_TEXTURE_WIDTH, UI_LISTITEM_TEXTURE_HEIGHT ) )
//                 {
//                     LOG(Logger::Level::ERROR) << "Unable to create UIListItem instance with ID: " << ID << std::endl;
//                     return false;
//                 }
//                 
//                 if ( !CManager::UIComponent::Caption::create( ID, text ) )
//                 {
//                     LOG(Logger::Level::ERROR) << "Unable to create UIListItem instance with ID: " << ID << std::endl;
//                     return false;
//                 }
//                 
//                 CManager::UIComponent::Caption::setCharSize( ID, 11 );
//                 auto cSize = CManager::UIComponent::Caption::getSize( ID );
//                 //CManager::UIComponent::Background::setSize( ID, { cSize.x + 50, cSize.y + 20 } );
//                 CManager::UIComponent::Background::setSize( ID, { cSize.x + 70, cSize.y + 20 } );
//                 setPosition( ID, { 0, 0 } );
//                 
//                 return true;
//             }
//             
//             void setPosition( const std::string& ID, const sf::Vector2f& position )
//             {
//                 CManager::UIComponent::Background::setPosition( ID, position );
//                 auto bPos = CManager::UIComponent::Background::getPosition( ID );
//                 auto bSize = CManager::UIComponent::Background::getSize( ID );
//                 auto cSize = CManager::UIComponent::Caption::getSize( ID );
//                 
//                 CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 2.5f } );
//                 CManager::UIComponent::Caption::setPosition( ID, { bPos.x + bSize.x / 2.f, bPos.y + bSize.y / 2.5f } );
//             }
//             
//             const sf::Vector2f getPosition( const std::string& ID )
//             {
//                 return CManager::UIComponent::Background::getPosition( ID );
//             }
//             
//             const sf::Vector2f getSize( const std::string& ID )
//             {
//                 return CManager::UIComponent::Background::getSize( ID );
//             }
//         }
//         
//         namespace UIListBox
//         {
//             bool create( const std::string& ID ) //, const std::string& text )
//             {
//                 if ( !CManager::UIComponent::Group::create( ID ) )
//                 {
//                     LOG(Logger::Level::ERROR) << "Unable to create UIListBox instance with ID: " << ID << std::endl;
//                     return false;
//                 }
//                 
// //                 if ( !CManager::UIComponent::Group::create( ID ) )
// //                 {
// //                     LOG(Logger::Level::ERROR) << "Unable to create UIListBox instance with ID: " << ID << std::endl;
// //                     return false;
// //                 }
//                 
//                 return true;
//             }
//             
//             // TODO: Fix this
//             
//             void add( const std::string& ID, const std::string& wID )
//             {
//                 CManager::UIComponent::Group::add( ID, wID);
//                 
//                 if ( CManager::UIComponent::Group::count( ID ) == 1 )
//                     return;
//                 
//                 auto IDs = CManager::UIComponent::Group::get( ID );
//                 auto lastM = IDs[ IDs.size() - 2 ];
//                 
// //                 if ( CManager::UIComponent::Group::count( ID ) == 1 )
// //                 {
// //                     
// //                 }
// //                 else
//                 
//                 auto iPos = UIManager::UIListItem::getPosition( lastM );
//                 auto iSize = UIManager::UIListItem::getSize( lastM );
//                 
//                 UIManager::UIListItem::setPosition( wID, { iPos.x, iPos.y + iSize.y } );
//             }
//             
//             void setPosition( const std::string& ID, const sf::Vector2f& position )
//             {
//                 
//             }
//         }
//         
//         namespace UIComboBox
//         {
//             bool create( const std::string& ID, std::vector<std::string>& wID )
//             {
//                 if ( wID.empty() )
//                 {
//                     LOG(Logger::Level::ERROR) << "Unable to create UIComboBox instance from " << std::endl;
//                     return false;
//                 }
//                 
//                 CManager::UIComponent::Background::create( ID, TextureID::UI_COMBOBOX_SEL, UI_COMBOBOX_SELECTED_TEXTURE_WIDTH, UI_COMBOBOX_SELECTED_TEXTURE_HEIGHT );
//                 CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ 147, 30 } );
//                 auto bPos = CManager::UIComponent::Background::getPosition( ID );
//                 auto bSize = CManager::UIComponent::Background::getSize( ID );
//                 
//                 CManager::UIComponent::Background::create( ID + "-arrow", TextureID::UI_COMBOBOX_ARROW, UI_COMBOBOX_ARROW_TEXTURE_WIDTH, UI_COMBOBOX_ARROW_TEXTURE_HEIGHT );
//                 CManager::UIComponent::Background::setSize( ID + "-arrow", sf::Vector2f{ 20, 30 } );
//                 CManager::UIComponent::Background::setPosition( ID + "-arrow", sf::Vector2f{ bPos.x + bSize.x, bPos.y } );
//                 
//                 CManager::UIComponent::Group::create( ID );
//                 
//                 auto lSize = UIManager::UIListItem::getSize( wID[0] );
//                 UIManager::UIListItem::setPosition( wID[0], { bPos.x , bPos.y + bSize.y } );
//                 CManager::UIComponent::Group::add( ID, wID[0] );
//                 
//                 for ( int i = 1; i < wID.size(); ++i )
//                 {
//                     auto iPos = UIManager::UIListItem::getPosition( wID[i - 1] );
//                     auto iSize = UIManager::UIListItem::getSize( wID[i - 1] );
//                     
//                     UIManager::UIListItem::setPosition( wID[i], { iPos.x , iPos.y + iSize.y } );
//                     CManager::UIComponent::Group::add( ID, wID[i] );
//                 }
//                 
//                 
//                 
//                 return true;
//             }
//             
//             void add( const std::string& ID, const std::string& wID )
//             {
//                 
//             }
//             
//             void setPosition( const std::string& ID, const sf::Vector2f& position )
//             {
//                 auto wID = CManager::UIComponent::Group::get( ID );
//                 
//                 CManager::UIComponent::Background::setPosition( ID, position );
//                 
//                 auto bPos = CManager::UIComponent::Background::getPosition( ID );
//                 auto bSize = CManager::UIComponent::Background::getSize( ID );
//                 
//                 CManager::UIComponent::Background::setPosition( ID + "-arrow", sf::Vector2f{ bPos.x + bSize.x, bPos.y } );
//                 
//                 auto lSize = UIManager::UIListItem::getSize( wID[0] );
//                 UIManager::UIListItem::setPosition( wID[0], { bPos.x , bPos.y + bSize.y } );
//                 
//                 for ( int i = 1; i < wID.size(); ++i )
//                 {
//                     auto iPos = UIManager::UIListItem::getPosition( wID[i - 1] );
//                     auto iSize = UIManager::UIListItem::getSize( wID[i - 1] );
//                     
//                     UIManager::UIListItem::setPosition( wID[i], { iPos.x , iPos.y + iSize.y } );
//                 }
//             }
//         }

//         ////////////////////////////////////////////////////////////////////////////////////////
//         //                                  UI Event Handler                                  //
//         ////////////////////////////////////////////////////////////////////////////////////////
//         
//         std::map<std::pair<std::string, EventHandler::UIEvent>, Callback> EventHandler::menu_button_callbacks = {};
//         
//         /* FIXME This method *assumes* a widget with the given ID already exists and no error checking done here. */
//         void EventHandler::addEventCallback( const std::string& ID, Callback cb, UIEvent event )
//         {
//             if ( event == UIEvent::BUTTON_PRESSED )
//                 menu_button_callbacks[ std::make_pair(ID, event) ] = cb;
//         }
//         
//         void EventHandler::handleEvents()
//         {
//             
//         }
    }
}
