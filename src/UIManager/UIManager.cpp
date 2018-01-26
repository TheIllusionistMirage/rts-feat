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
#include <cmath>
#include <cmath>

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
            
            void setFontColor( const std::string& ID, const sf::Color fontColor )
            {
                CManager::UIComponent::Caption::setFontColor( ID, fontColor );
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
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        //                                      UI Tilebox                                         //
        /////////////////////////////////////////////////////////////////////////////////////////////
        
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
                CManager::UIComponent::Background::setSize( ID + "-box-bg", { tbgSize.x, 280 } );
                
                CManager::UIComponent::ScrollBar::create( ID, CManager::UIComponent::Background::getSize( ID + "-box-bg" ).y );
                //CManager::UIComponent::ScrollBar::setScrollAmount( ID, 20 );
                
//                 UIManager::UITileBox::setPosition( ID, { 0, 0 } );
                
                // Tile box picture frames
                
                UIManager::UIPictureFrame::create( ID + "t1", TextureID::TERRAIN_TILE_WATER_01, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water-01" );
                UIManager::UIPictureFrame::setSize( ID + "t1", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( ID + "t2", TextureID::TERRAIN_TILE_GRASS_0_0000, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-01" );
                UIManager::UIPictureFrame::setSize( ID + "t2", { 50, 25 } );
                
                UIManager::UIPictureFrame::create( ID + "t3", TextureID::TERRAIN_TILE_DESERT_0_0000, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "desert-01" );
                UIManager::UIPictureFrame::setSize( ID + "t3", { 50, 25 } );
                
//                 UIManager::UIPictureFrame::create( ID + "t1", TextureID::TERRAIN_TILE_DESERT_01, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "desert-01" );
//                 UIManager::UIPictureFrame::setSize( ID + "t1", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t2", TextureID::TERRAIN_TILE_GRASS_01, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-01" );
//                 UIManager::UIPictureFrame::setSize( ID + "t2", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t3", TextureID::TERRAIN_TILE_WATER_01, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water-01" );
//                 UIManager::UIPictureFrame::setSize( ID + "t3", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t4", TextureID::TERRAIN_TILE_GRASS_DESERT_01, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-01" );
//                 UIManager::UIPictureFrame::setSize( ID + "t4", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t5", TextureID::TERRAIN_TILE_GRASS_DESERT_02, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-02" );
//                 UIManager::UIPictureFrame::setSize( ID + "t5", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t6", TextureID::TERRAIN_TILE_GRASS_DESERT_03, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-03" );
//                 UIManager::UIPictureFrame::setSize( ID + "t6", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t7", TextureID::TERRAIN_TILE_GRASS_DESERT_04, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-04" );
//                 UIManager::UIPictureFrame::setSize( ID + "t7", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t8", TextureID::TERRAIN_TILE_GRASS_DESERT_112, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-112" );
//                 UIManager::UIPictureFrame::setSize( ID + "t8", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t9", TextureID::TERRAIN_TILE_GRASS_DESERT_114, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-112" );
//                 UIManager::UIPictureFrame::setSize( ID + "t9", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t10", TextureID::TERRAIN_TILE_GRASS_DESERT_132, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-112" );
//                 UIManager::UIPictureFrame::setSize( ID + "t10", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t11", TextureID::TERRAIN_TILE_GRASS_DESERT_134, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-112" );
//                 UIManager::UIPictureFrame::setSize( ID + "t11", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t12", TextureID::TERRAIN_TILE_GRASS_DESERT_013, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-013" );
//                 UIManager::UIPictureFrame::setSize( ID + "t12", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t13", TextureID::TERRAIN_TILE_GRASS_DESERT_113, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-13" );
//                 UIManager::UIPictureFrame::setSize( ID + "t13", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t14", TextureID::TERRAIN_TILE_GRASS_DESERT_01432, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-\n01432" );
//                 UIManager::UIPictureFrame::setSize( ID + "t14", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t15", TextureID::TERRAIN_TILE_GRASS_DESERT_11432, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "grass-\ndesert-\n11432" );
//                 UIManager::UIPictureFrame::setSize( ID + "t15", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t16", TextureID::TERRAIN_TILE_BEACH_01, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-01" );
//                 UIManager::UIPictureFrame::setSize( ID + "t16", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t17", TextureID::TERRAIN_TILE_BEACH_02, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-02" );
//                 UIManager::UIPictureFrame::setSize( ID + "t17", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t18", TextureID::TERRAIN_TILE_BEACH_03, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-03" );
//                 UIManager::UIPictureFrame::setSize( ID + "t18", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t19", TextureID::TERRAIN_TILE_BEACH_04, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-04" );
//                 UIManager::UIPictureFrame::setSize( ID + "t19", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t20", TextureID::TERRAIN_TILE_BEACH_013, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-013" );
//                 UIManager::UIPictureFrame::setSize( ID + "t20", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t21", TextureID::TERRAIN_TILE_BEACH_113, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-113" );
//                 UIManager::UIPictureFrame::setSize( ID + "t21", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t22", TextureID::TERRAIN_TILE_BEACH_0013, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-\n0013" );
//                 UIManager::UIPictureFrame::setSize( ID + "t22", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t23", TextureID::TERRAIN_TILE_BEACH_1113, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-\n1113" );
//                 UIManager::UIPictureFrame::setSize( ID + "t23", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t24", TextureID::TERRAIN_TILE_BEACH_032, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-\n032" );
//                 UIManager::UIPictureFrame::setSize( ID + "t24", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t25", TextureID::TERRAIN_TILE_BEACH_014, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-\n014" );
//                 UIManager::UIPictureFrame::setSize( ID + "t25", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t26", TextureID::TERRAIN_TILE_BEACH_023, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-\n023" );
//                 UIManager::UIPictureFrame::setSize( ID + "t26", { 50, 25 } );
//                 
//                 UIManager::UIPictureFrame::create( ID + "t27", TextureID::TERRAIN_TILE_BEACH_123, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "beach-\n123" );
//                 UIManager::UIPictureFrame::setSize( ID + "t27", { 50, 25 } );
        
                std::vector<std::string> members;
                int tiles = 3;
                for ( auto i = 1; i <= tiles; i++ )
                {
                    members.push_back( ID + "t" + std::to_string(i) );
                }
                
                CManager::UIComponent::ScrollBar::setScrollAmount( ID, 25 + 40 + 5 );
                CManager::UIComponent::ScrollBar::setRowCount( ID, std::round( ( tiles + 0.5 ) / 3 ) );
                
                CManager::UIComponent::ScrollBar::setCallback( ID, [ID](){ shiftByRows( ID, 1, -1 ); }, CManager::UIComponent::UIEvent::SCROLL_DRAGGED_DOWN );
                CManager::UIComponent::ScrollBar::setCallback( ID, [ID](){ shiftByRows( ID, 1,  1 ); }, CManager::UIComponent::UIEvent::SCROLL_DRAGGED_UP   );
                
                CManager::UIComponent::Group::create( ID + "-group", members );
                
                //UIManager::UITileBox::setPosition( ID, { 0, 0 } );
                
                sf::Vector2f position{ 0.f, 0.f };
                
                CManager::UIComponent::Background::setPosition( ID + "-title-bg", position );
                //auto tbgSize2 = CManager::UIComponent::Background::getSize( ID + "-title-bg" );
                CManager::UIComponent::Caption::setPosition( ID + "-title-cap", { position.x + tbgSize.x / 2.f, position.y + tbgSize.y / 2.5f } );
                CManager::UIComponent::Background::setPosition( ID + "-box-bg",  { position.x, position.y + tbgSize.y + 5 } );
                CManager::UIComponent::ScrollBar::setPosition( ID, { position.x + tbgSize.x - 15.f, position.y + tbgSize.y + 5 } );
                
                // Align the picture franmes
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                
                UIManager::UIPictureFrame::setPosition( ID + "t1", { bgPos.x + 5, bgPos.y + 5 } );
                
                auto prevPos = CManager::UIComponent::Background::getPosition( ID + "t1" );
                auto prevSize = UIManager::UIPictureFrame::getSize( ID + "t1" );
                
                auto bgSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                sf::FloatRect bounds = { bgPos.x, bgPos.y, bgSize.x, bgSize.y };
                
                for ( int i = 2; i <= CManager::UIComponent::Group::count( ID + "-group" ); ++i )
                {
                    if (i != 0 && (i - 1) % 3 == 0 )
                        UIManager::UIPictureFrame::setPosition( ID + "t" + std::to_string(i) , { bgPos.x + 5, prevPos.y + prevSize.y + 40 } );
                    else
                        UIManager::UIPictureFrame::setPosition( ID + "t" + std::to_string(i) , { prevPos.x + prevSize.x + 5, prevPos.y } );// + prevSize.y + 5 } );
                    
                    prevPos = UIManager::UIPictureFrame::getPosition( ID + "t" + std::to_string(i) );
                    prevSize = UIManager::UIPictureFrame::getSize( ID + "t" + std::to_string(i) );
                    
                    if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                        UIManager::UIPictureFrame::setVisibility( ID + "t" + std::to_string(i), true );
                    else
                        UIManager::UIPictureFrame::setVisibility( ID + "t" + std::to_string(i), false );
                }
                
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
                    UIManager::UIPictureFrame::destroy( ID + "t" + std::to_string(i) );
                }
                
                CManager::UIComponent::Group::destroy( ID + "-group" );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f position )
            {
                // Set the positions of the backgrounds
                
                float offset = CManager::UIComponent::Background::getPosition( ID + "-box-bg" ).y -
                                CManager::UIComponent::Background::getPosition( ID + "t1" ).y + 5;
                
                CManager::UIComponent::Background::setPosition( ID + "-title-bg", position );
                auto tbgSize = CManager::UIComponent::Background::getSize( ID + "-title-bg" );
                CManager::UIComponent::Caption::setPosition( ID + "-title-cap", { position.x + tbgSize.x / 2.f, position.y + tbgSize.y / 2.5f } );
                CManager::UIComponent::Background::setPosition( ID + "-box-bg",  { position.x, position.y + tbgSize.y + 5 } );
                CManager::UIComponent::ScrollBar::setPosition( ID, { position.x + tbgSize.x - 15.f, position.y + tbgSize.y + 5 } );
                
                // Align the picture franmes
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                
                UIManager::UIPictureFrame::setPosition( ID + "t1", { bgPos.x + 5, bgPos.y + 5 - offset } );
                
                auto prevPos = CManager::UIComponent::Background::getPosition( ID + "t1" );
                auto prevSize = UIManager::UIPictureFrame::getSize( ID + "t1" );
                
                //auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                auto bgSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                sf::FloatRect bounds = { bgPos.x, bgPos.y, bgSize.x, bgSize.y };
                
                for ( int i = 2; i <= CManager::UIComponent::Group::count( ID + "-group" ); ++i )
                {
                    if (i != 0 && (i - 1) % 3 == 0 )
                        UIManager::UIPictureFrame::setPosition( ID + "t" + std::to_string(i) , { bgPos.x + 5, prevPos.y + prevSize.y + 40 } );
                    else
                        UIManager::UIPictureFrame::setPosition( ID + "t" + std::to_string(i) , { prevPos.x + prevSize.x + 5, prevPos.y } );// + prevSize.y + 5 } );
                    
                    prevPos = UIManager::UIPictureFrame::getPosition( ID + "t" + std::to_string(i) );
                    prevSize = UIManager::UIPictureFrame::getSize( ID + "t" + std::to_string(i) );
                    
                    if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                        UIManager::UIPictureFrame::setVisibility( ID + "t" + std::to_string(i), true );
                    else
                        UIManager::UIPictureFrame::setVisibility( ID + "t" + std::to_string(i), false );
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
                auto prevPos = CManager::UIComponent::Background::getPosition( ID + "t1" );
                auto prevSize = UIManager::UIPictureFrame::getSize( ID + "t1" );
                
                UIManager::UIPictureFrame::setPosition( ID + "t1", { prevPos.x, prevPos.y + direction * prevSize.y + direction * rows * 40 } );// - rows * 5 } );
                
                float x = prevPos.x;                
                prevPos = CManager::UIComponent::Background::getPosition( ID + "t1" );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID + "-box-bg" );
                auto bgSize = CManager::UIComponent::Background::getSize( ID + "-box-bg" );
                
                sf::FloatRect bounds = { bgPos.x, bgPos.y, bgSize.x, bgSize.y };
                
                if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                    UIManager::UIPictureFrame::setVisibility( ID + "t1", true );
                else
                    UIManager::UIPictureFrame::setVisibility( ID + "t1", false );
                
                for ( int i = 2; i <= CManager::UIComponent::Group::count( ID + "-group" ); ++i )
                {
                    if (i != 0 && (i - 1) % 3 == 0 )
                        UIManager::UIPictureFrame::setPosition( ID + "t" + std::to_string(i) , { x, prevPos.y + prevSize.y + 40 } );
                    else
                        UIManager::UIPictureFrame::setPosition( ID + "t" + std::to_string(i) , { prevPos.x + prevSize.x + 5, prevPos.y } );// + prevSize.y + 5 } );
                    
                    prevPos = UIManager::UIPictureFrame::getPosition( ID + "t" + std::to_string(i) );
                    prevSize = UIManager::UIPictureFrame::getSize( ID + "t" + std::to_string(i) );
                    
                    if ( bounds.contains( prevPos ) && bounds.contains( prevPos.x + prevSize.x, prevPos.y + prevSize.y ) )
                        UIManager::UIPictureFrame::setVisibility( ID + "t" + std::to_string(i), true );
                    else
                        UIManager::UIPictureFrame::setVisibility( ID + "t" + std::to_string(i), false );
                }
            }
            
            void setCallback( const std::string& ID, CManager::UIComponent::Callback2 cb, CManager::UIComponent::UIEvent event )
            {
                if ( event <= CManager::UIComponent::UIEvent::INVALID || event >= CManager::UIComponent::UIEvent::MAX_EVENTS )
                {
                    LOG(Logger::Level::ERROR) << "Invalid UIEvent specified." << std::endl;
                    return;
                }
                
                auto count = CManager::UIComponent::Group::count( ID + "-group" );
                
                for ( int i = 1; i <= count; ++i )
                    CManager::UIComponent::Background::setCallback2( ID + "t" + std::to_string( i ), cb, event );
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
