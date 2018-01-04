/*
 * ----------------------------
 *  Module    : GameStates
 *  Submodule : MapEditorState
 * ----------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 02-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods & classes declared
 *  in MainMenuState submodule.
 */

#include <functional>

#include <SFML/Window/Event.hpp>

#include "Utility/Constants.hpp"
#include "Utility/Log.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "UIManager/UIManager.hpp"
#include "GameStates/MapEditorState.hpp"

namespace rts
{
    MapEditorState::MapEditorState( Game* game )
    {
        m_game = game;
        
        sf::Color rectFillColor = sf::Color( 30, 30, 30 );
        sf::Color rectOutlineColor = sf::Color( 70, 70, 70 );
        
        m_rects[MAIN_TITLE].setPosition( sf::Vector2f{ 5, 5 } );
        m_rects[MAIN_TITLE].setSize( sf::Vector2f{ 130, 45 } );
        m_rects[MAIN_TITLE].setFillColor( rectFillColor );
        m_rects[MAIN_TITLE].setOutlineThickness( 1 );
        m_rects[MAIN_TITLE].setOutlineColor( rectOutlineColor );
                
        m_rects[MENU_BAR].setPosition( sf::Vector2f{ 142, 5 } );
        m_rects[MENU_BAR].setSize( sf::Vector2f{ 652, 45 } );
        m_rects[MENU_BAR].setFillColor( rectFillColor );
        m_rects[MENU_BAR].setOutlineThickness( 1 );
        m_rects[MENU_BAR].setOutlineColor( rectOutlineColor );
        
        UIManager::UILabel::create( "MapEditorTitleLabel", "MAP EDITOR" );
        UIManager::UILabel::setFont( "MapEditorTitleLabel", FontID::ROBOTO_BOLD );
        UIManager::UILabel::setCharSize( "MapEditorTitleLabel", 18 );
        auto lbSize = UIManager::UILabel::getSize( "MapEditorTitleLabel" );
        UIManager::UILabel::setOrigin( "MapEditorTitleLabel", { lbSize.x / 2.f, lbSize.y / 1.5f } );
        auto tSize = m_rects[MAIN_TITLE].getSize();
        UIManager::UILabel::setPosition( "MapEditorTitleLabel", { tSize.x / 2.f, tSize.y / 2.f } );
        
        UIManager::UIButton::create( "OpenButton", "OPEN" );
        UIManager::UIButton::setCharSize( "OpenButton", 16 );
        auto tbSize = m_rects[MENU_BAR].getPosition();
        UIManager::UIButton::setPosition( "OpenButton", { tbSize.x + 5, 11 } );
        
        UIManager::UIButton::create( "SaveButton", "SAVE" );
        UIManager::UIButton::setCharSize( "SaveButton", 16 );
        auto obPos = UIManager::UIButton::getPosition( "OpenButton" );
        auto obSize = UIManager::UIButton::getSize( "OpenButton" );
        UIManager::UIButton::setPosition( "SaveButton", { obPos.x + obSize.x + 5, 11 } );
        
        UIManager::UIButton::create( "AboutMEButton", "ABOUT" );
        UIManager::UIButton::setCharSize( "AboutMEButton", 16 );
        auto sbPos = UIManager::UIButton::getPosition( "SaveButton" );
        auto sbSize = UIManager::UIButton::getSize( "SaveButton" );
        UIManager::UIButton::setPosition( "AboutMEButton", { sbPos.x + sbSize.x + 5, 11 } );
        
        UIManager::UIButton::create( "ExitMEButton", "EXIT EDITOR" );
        UIManager::UIButton::setCharSize( "ExitMEButton", 16 );
        auto abPos = UIManager::UIButton::getPosition( "AboutMEButton" );
        auto abSize = UIManager::UIButton::getSize( "AboutMEButton" );
        UIManager::UIButton::setPosition( "ExitMEButton", { abPos.x + abSize.x + 5, 11 } );
        
        // Set the callbacks
        //UIManager::UIButton::setCallback( "ExitMEButton", std::bind( &Game::popState, m_game ), CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        
        UIManager::UITileBox::create( "atb" );
        UIManager::UITileBox::setPosition( "atb", { 4, 60 } );
        
//         UIManager::UIPictureFrame::create( "pic", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
//         UIManager::UIPictureFrame::setSize( "pic", { 50, 25 } );
//         UIManager::UIPictureFrame::setPosition( "pic", { 5, 100 } );
//         
//         UIManager::UIPictureFrame::create( "pic2", TextureID::TERRAIN_TILE_WATER_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "water.png" );
//         UIManager::UIPictureFrame::setSize( "pic2", { 50, 25 } );
//         UIManager::UIPictureFrame::setPosition( "pic2", { 60, 100 } );
//         
//         UIManager::UIPictureFrame::create( "pic3", TextureID::TERRAIN_TILE_LAND_DEFAULT, TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT, "tile.png" );
//         UIManager::UIPictureFrame::setSize( "pic3", { 50, 25 } );
//         UIManager::UIPictureFrame::setPosition( "pic3", { 115, 100 } );
        
        LOG(Logger::Level::DEBUG) << "MapEditorState object created" << std::endl;
    }
    
    MapEditorState::~MapEditorState()
    {
        UIManager::UILabel::destroy( "MapEditorTitleLabel" );
        UIManager::UIMenuButton::destroy( "OpenButton" );
        UIManager::UIMenuButton::destroy( "SaveButton" );
        UIManager::UIMenuButton::destroy( "AboutMEButton" );
        UIManager::UIMenuButton::destroy( "ExitMEButton" );
        
        LOG(Logger::Level::DEBUG) << "MapEditorState object destroyed" << std::endl;
    }
    
    void MapEditorState::handleInput()
    {
        if (m_game->m_window.isOpen())
        {
            sf::Event event;            
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_game->m_window);

            while (m_game->m_window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                    {
                        m_game->m_window.close();
                    } break;
                    
                    case sf::Event::Resized:
                    {
                        m_game->m_backgroundSprite.scale( event.size.width / m_game->m_backgroundSprite.getGlobalBounds().width,
                                                           event.size.height / m_game->m_backgroundSprite.getGlobalBounds().height );
                        m_game->m_window.setView(sf::View(sf::FloatRect{0, 0, event.size.width, event.size.height}));
                        
                    } break;
                                        
                    case sf::Event::MouseButtonReleased:
                    {
                    } break;
                    
                    case sf::Event::MouseMoved:
                    {
                    }
                }
            }
            
            CManager::UIComponent::updateUIComponents( event, mousePos, FRAME_TIME );
        }
    }
    
    void MapEditorState::update( const sf::Time dt )
    {
        
    }
    
    void MapEditorState::draw( const sf::Time dt )
    {
        for ( auto&& rect : m_rects )
            m_game->m_window.draw( rect );
    }
    
    void MapEditorState::freeze(bool f)
    {
        auto tex = ResourceManager::getTexture( TextureID::MAP_EDITOR_BACKGROUND );
        m_game->m_backgroundSprite.setTexture( *tex );
        m_game->m_backgroundSprite.setTextureRect( sf::IntRect{ 0, 0, tex->getSize().x, tex->getSize().y } );
        
        UIManager::UILabel::setVisibility( "MapEditorTitleLabel", !f );
        UIManager::UIMenuButton::setVisibility( "OpenButton", !f );
        UIManager::UIMenuButton::setVisibility( "SaveButton", !f );
        UIManager::UIMenuButton::setVisibility( "AboutMEButton", !f );
        UIManager::UIMenuButton::setVisibility( "ExitMEButton", !f );
    }
}
