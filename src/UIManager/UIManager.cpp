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
            
            void destroy( const std::string& ID )
            {
                CManager::UIComponent::Caption::destroy( ID );
                CManager::UIComponent::Background::destroy( ID );
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
            
            void setVisibility( const std::string& ID, const bool visibility )
            {
                CManager::UIComponent::Caption::setVisibility( ID, visibility );
                CManager::UIComponent::Background::setVisibility( ID, visibility );
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
                CManager::UIComponent::Background::setSize( ID + "-box-bg", { tbgSize.x, 400 } );
                
                CManager::UIComponent::ScrollBar::create( ID, CManager::UIComponent::Background::getSize( ID + "-box-bg" ).y );
                //CManager::UIComponent::ScrollBar::setScrollAmount( ID, 20 );
                
//                 UIManager::UITileBox::setPosition( ID, { 0, 0 } );
                
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
                
                UIManager::UIPictureFrame::create( "t4", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t4", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t5", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t5", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t6", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t6", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic3", { 115, 100 } );
                
                UIManager::UIPictureFrame::create( "t7", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t7", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t8", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t8", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t9", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t9", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic3", { 115, 100 } );
                
                UIManager::UIPictureFrame::create( "t10", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t10", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t11", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t11", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t12", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t12", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t13", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t13", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t14", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t14", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t15", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t15", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t16", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t16", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t17", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t17", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic3", { 115, 100 } );
                
                UIManager::UIPictureFrame::create( "t18", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t18", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t19", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t19", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic", { 5, 100 } );
        
                UIManager::UIPictureFrame::create( "t20", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t20", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic2", { 60, 100 } );
                
                UIManager::UIPictureFrame::create( "t21", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t21", { 50, 25 } );
                //UIManager::UIPictureFrame::setPosition( "pic3", { 115, 100 } );
                
                UIManager::UIPictureFrame::create( "t22", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
                UIManager::UIPictureFrame::setSize( "t22", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t23", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t23", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( "t24", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
                UIManager::UIPictureFrame::setSize( "t24", { 50, 25 } );
                
                std::vector<std::string> members;
                int rows = 24;
                for ( auto i = 1; i <= rows; i++ )
                {
                    members.push_back( "t" + std::to_string(i) );
                }
                
                auto fm = std::bind( shiftByRows, ID, 1, -1 );
                auto fn = std::bind( shiftByRows, ID, 1, std::placeholders::_1 );
                
                CManager::UIComponent::ScrollBar::setScrollAmount( ID, 25 + 40 + 5 );
                CManager::UIComponent::ScrollBar::setRowCount( ID, rows / 3 );
                //CManager::UIComponent::ScrollBar::setCallback( ID, std::bind( shiftByRows, ID, 1, -1 ), CManager::UIComponent::UIEvent::SCROLL_DRAGGED_DOWN );
//                 CManager::UIComponent::ScrollBar::setCallback( ID, std::bind( shiftByRows, ID, 1, -1 ), CManager::UIComponent::UIEvent::SCROLL_DRAGGED_DOWN );
//                 CManager::UIComponent::ScrollBar::setCallback( ID, std::bind( shiftByRows, ID, 1, 1 ), CManager::UIComponent::UIEvent::SCROLL_DRAGGED_UP );
                
                //CallbackManager::Callback<void, int, float>::Callable c = [ ID ]( int i, float y ){ shiftByRows( ID, 1, i ); y++; };
                
                CManager::UIComponent::ScrollBar::setCallback( ID, [ID](){ shiftByRows( ID, 1, -1 ); }, CManager::UIComponent::UIEvent::SCROLL_DRAGGED_DOWN );
                CManager::UIComponent::ScrollBar::setCallback( ID, std::bind( shiftByRows, ID, 1, 1 ), CManager::UIComponent::UIEvent::SCROLL_DRAGGED_UP );
                                
                CManager::UIComponent::Group::create( ID + "-group", members );
                
                UIManager::UITileBox::setPosition( ID, { 0, 0 } );
                
                return true;
            }
            
            void destroy( const std::string& ID )
            {
                CManager::UIComponent::Background::destroy( ID + "-title-bg" );;
                CManager::UIComponent::Caption::destroy( ID + "-title-cap" );
                CManager::UIComponent::Background::destroy( ID + "-box-bg" );
                CManager::UIComponent::ScrollBar::destroy( ID );
                
                std::vector<std::string> members = CManager::UIComponent::Group::get( ID + "-group" );
                for ( auto i = 1u; i <= members.size(); i++ )
                {
                    UIManager::UIPictureFrame::destroy( "t" + std::to_string(i) );
                }
                
                CManager::UIComponent::Group::destroy( ID + "-group" );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f position )
            {
                // Set the positions of the backgrounds
                
                CManager::UIComponent::Background::setPosition( ID + "-title-bg", position );
                auto tbgSize = CManager::UIComponent::Background::getSize( ID + "-title-bg" );
                CManager::UIComponent::Caption::setPosition( ID + "-title-cap", { position.x + tbgSize.x / 2.f, position.y + tbgSize.y / 2.5f } );
                CManager::UIComponent::Background::setPosition( ID + "-box-bg",  { position.x, position.y + tbgSize.y + 5 } );
                CManager::UIComponent::ScrollBar::setPosition( ID, { position.x + tbgSize.x - 15.f, position.y + tbgSize.y + 5 } );
                
                // Align the picture franmes
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                
                UIManager::UIPictureFrame::setPosition( "t1", { bgPos.x + 5, bgPos.y + 5 } );
                
                auto prevPos = CManager::UIComponent::Background::getPosition( "t1" );
                auto prevSize = UIManager::UIPictureFrame::getSize( "t1" );
                
                //auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                auto bgSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                sf::FloatRect bounds = { bgPos.x, bgPos.y, bgSize.x, bgSize.y };
                
                for ( int i = 2; i <= CManager::UIComponent::Group::count( ID + "-group" ); ++i )
                {
                    if (i != 0 && (i - 1) % 3 == 0 )
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { bgPos.x + 5, prevPos.y + prevSize.y + 40 } );
                    else
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { prevPos.x + prevSize.x + 5, prevPos.y } );// + prevSize.y + 5 } );
                    
                    prevPos = UIManager::UIPictureFrame::getPosition( "t" + std::to_string(i) );
                    prevSize = UIManager::UIPictureFrame::getSize( "t" + std::to_string(i) );
                    
                    if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), true );
                    else
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), false );
                    
//                     std::cout  << "Pos: " << prevPos.x << ", " << prevPos.y << std::endl;
//                     std::cout  << "Size: " << prevSize.x << ", " << prevSize.y << std::endl << std::endl;
                }
            }
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Background::getPosition( ID + "-title-bg" );
            }
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                auto bgTitleSize = CManager::UIComponent::Background::getSize( ID + "-title-bg" );
                auto bgBoxSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                return { bgTitleSize.x, bgTitleSize.y + 5.f + bgBoxSize.y };
            }
            
            void shiftByRows( const std::string& ID, const int rows, const int direction )
            {
                auto prevPos = CManager::UIComponent::Background::getPosition( "t1" );
                auto prevSize = UIManager::UIPictureFrame::getSize( "t1" );
                
                UIManager::UIPictureFrame::setPosition( "t1", { prevPos.x, prevPos.y + direction * prevSize.y + direction * rows * 40 } );// - rows * 5 } );
                
                float x = prevPos.x;                
                prevPos = CManager::UIComponent::Background::getPosition( "t1" );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                auto bgSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                sf::FloatRect bounds = { bgPos.x, bgPos.y, bgSize.x, bgSize.y };
                
                if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                    UIManager::UIPictureFrame::setVisibility( "t1", true );
                else
                    UIManager::UIPictureFrame::setVisibility( "t1", false );
                
                for ( int i = 2; i <= CManager::UIComponent::Group::count( ID + "-group" ); ++i )
                {
                    if (i != 0 && (i - 1) % 3 == 0 )
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { x, prevPos.y + prevSize.y + 40 } );
                    else
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { prevPos.x + prevSize.x + 5, prevPos.y } );// + prevSize.y + 5 } );
                    
                    prevPos = UIManager::UIPictureFrame::getPosition( "t" + std::to_string(i) );
                    prevSize = UIManager::UIPictureFrame::getSize( "t" + std::to_string(i) );
                    
                    if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), true );
                    else
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), false );
                }
            }
            
            void shiftUpByRows( const std::string& ID, const int rows )
            {
                auto prevPos = CManager::UIComponent::Background::getPosition( "t1" );
                auto prevSize = UIManager::UIPictureFrame::getSize( "t1" );
                
                UIManager::UIPictureFrame::setPosition( "t1", { prevPos.x, prevPos.y - prevSize.y - rows * 40 } );// - rows * 5 } );
                
                float x = prevPos.x;                
                prevPos = CManager::UIComponent::Background::getPosition( "t1" );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                auto bgSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                sf::FloatRect bounds = { bgPos.x, bgPos.y, bgSize.x, bgSize.y };
                
                if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                    UIManager::UIPictureFrame::setVisibility( "t1", true );
                else
                    UIManager::UIPictureFrame::setVisibility( "t1", false );
                
                for ( int i = 2; i <= CManager::UIComponent::Group::count( ID + "-group" ); ++i )
                {
                    if (i != 0 && (i - 1) % 3 == 0 )
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { x, prevPos.y + prevSize.y + 40 } );
                    else
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { prevPos.x + prevSize.x + 5, prevPos.y } );// + prevSize.y + 5 } );
                    
                    prevPos = UIManager::UIPictureFrame::getPosition( "t" + std::to_string(i) );
                    prevSize = UIManager::UIPictureFrame::getSize( "t" + std::to_string(i) );
                    
                    if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), true );
                    else
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), false );
                }
            }
            
            void shiftDownByRows( const std::string& ID, const int rows )
            {
                auto prevPos = CManager::UIComponent::Background::getPosition( "t1" );
                auto prevSize = UIManager::UIPictureFrame::getSize( "t1" );
                
                UIManager::UIPictureFrame::setPosition( "t1", { prevPos.x, prevPos.y + prevSize.y + rows * 40 } );// - rows * 5 } );
                
                float x = prevPos.x;
                prevPos = CManager::UIComponent::Background::getPosition( "t1" );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                auto bgSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                sf::FloatRect bounds = { bgPos.x, bgPos.y, bgSize.x, bgSize.y };
                
                if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                    UIManager::UIPictureFrame::setVisibility( "t1", true );
                else
                    UIManager::UIPictureFrame::setVisibility( "t1", false );
                
                for ( int i = 2; i <= CManager::UIComponent::Group::count( ID + "-group" ); ++i )
                {
                    if (i != 0 && (i - 1) % 3 == 0 )
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { x, prevPos.y + prevSize.y + 40 } );
                    else
                        UIManager::UIPictureFrame::setPosition( "t" + std::to_string(i) , { prevPos.x + prevSize.x + 5, prevPos.y } );// + prevSize.y + 5 } );
                    
                    prevPos = UIManager::UIPictureFrame::getPosition( "t" + std::to_string(i) );
                    prevSize = UIManager::UIPictureFrame::getSize( "t" + std::to_string(i) );
                    
                    if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), true );
                    else
                        UIManager::UIPictureFrame::setVisibility( "t" + std::to_string(i), false );
                }
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
