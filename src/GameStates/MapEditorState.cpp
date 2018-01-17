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
    MapEditorState::MapEditorState( Game* game ) :
     m_map( 20, game->m_window ),
     m_selectedTex( TextureID::TERRAIN_TILE_LAND_DEFAULT )
    {   
        m_game = game;
        
        sf::Color rectFillColor = sf::Color( 30, 30, 30 );
        sf::Color rectOutlineColor = sf::Color( 70, 70, 70 );
        
        //m_rects[MAIN_TITLE].setPosition( sf::Vector2f{ 5, 5 } );
        m_rects[MAIN_TITLE].setPosition( m_game->m_window.mapPixelToCoords( { 5, 5 } ) );
        m_rects[MAIN_TITLE].setPosition( m_game->m_window.mapPixelToCoords( sf::Vector2i{ 5, 5 } ) );
        m_rects[MAIN_TITLE].setSize( sf::Vector2f{ 130, 45 } );
        m_rects[MAIN_TITLE].setFillColor( rectFillColor );
        m_rects[MAIN_TITLE].setOutlineThickness( 1 );
        m_rects[MAIN_TITLE].setOutlineColor( rectOutlineColor );
                
        //m_rects[MENU_BAR].setPosition( sf::Vector2f{ 142, 5 } );
        m_rects[MENU_BAR].setPosition( m_game->m_window.mapPixelToCoords( sf::Vector2i{ 142, 5 } ) );
        m_rects[MENU_BAR].setSize( sf::Vector2f{ 539, 45 } );
        m_rects[MENU_BAR].setFillColor( rectFillColor );
        m_rects[MENU_BAR].setOutlineThickness( 1 );
        m_rects[MENU_BAR].setOutlineColor( rectOutlineColor );
        
        UIManager::UILabel::create( "MapEditorTitleLabel", "MAP EDITOR" );
        UIManager::UILabel::setFont( "MapEditorTitleLabel", FontID::ROBOTO_BOLD );
        UIManager::UILabel::setCharSize( "MapEditorTitleLabel", 18 );
        UIManager::UILabel::setPosition( "MapEditorTitleLabel", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { 15, 16 } ) ) );
        
        UIManager::UIButton::create( "OpenButton", "OPEN" );
        UIManager::UIButton::setCharSize( "OpenButton", 16 );
        UIManager::UIButton::setPosition( "OpenButton", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { 200, 11 } ) ) );
         
        UIManager::UIButton::create( "SaveButton", "SAVE" );
        UIManager::UIButton::setCharSize( "SaveButton", 16 );
        auto obPos = UIManager::UIButton::getPosition( "OpenButton" );
        auto obSize = UIManager::UIButton::getSize( "OpenButton" );
        UIManager::UIButton::setPosition( "SaveButton", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { obPos.x + obSize.x + 5, 11 } ) ) );
        
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
        
        UIManager::UITileBox::create( "MapTileBox" );
        UIManager::UITileBox::setPosition( "MapTileBox", { 4, 60 } );
        
        // Set the callbacks
        //UIManager::UIButton::setCallback( "ExitMEButton", std::bind( &Game::popState, m_game ), CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        UIManager::UIButton::setCallback( "ExitMEButton", [ this, &m_game=m_game ](){ m_game->popState(); }, CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        UIManager::UITileBox::setCallback( "MapTileBox", [this]( TextureID texID ){ m_map.setSelectedTile( texID ); }, CManager::UIComponent::UIEvent::TILE_BOX_ITEM_SELECTED );
                
        LOG(Logger::Level::DEBUG) << "MapEditorState object created" << std::endl;
    }
    
    MapEditorState::~MapEditorState()
    {
        UIManager::UILabel::destroy( "MapEditorTitleLabel" );
        UIManager::UIMenuButton::destroy( "OpenButton" );
        UIManager::UIMenuButton::destroy( "SaveButton" );
        UIManager::UIMenuButton::destroy( "AboutMEButton" );
        UIManager::UIMenuButton::destroy( "ExitMEButton" );
        UIManager::UITileBox::destroy( "MapTileBox" );
        
        m_game->m_window.setView( m_game->m_window.getDefaultView() );
        
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
            
            CManager::UIComponent::updateUIComponents( event, static_cast<sf::Vector2i>( m_game->m_window.mapPixelToCoords( mousePos ) ), FRAME_TIME );
        }
    }
    
    void MapEditorState::update( const sf::Time dt )
    {
        m_map.update( dt );
        
        m_rects[MAIN_TITLE].setPosition( m_game->m_window.mapPixelToCoords( sf::Vector2i{ 5, 5 } ) );
        m_rects[MENU_BAR].setPosition( m_game->m_window.mapPixelToCoords( sf::Vector2i{ 142, 5 } ) );   
        
        UIManager::UILabel::setPosition( "MapEditorTitleLabel", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( sf::Vector2i{ 16, 16 } ) ) );
        UIManager::UIButton::setPosition( "OpenButton", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { 148, 12 } ) ) );
        UIManager::UIButton::setPosition( "SaveButton", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { 148 + 118, 12 } ) ) );
        UIManager::UIButton::setPosition( "AboutMEButton", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { 148 + 118 + 113, 12 } ) ) );
        UIManager::UIButton::setPosition( "ExitMEButton", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { 148 + 118 + 113 + 131, 12 } ) ) );
                
        UIManager::UITileBox::setPosition( "MapTileBox", static_cast<sf::Vector2f>( m_game->m_window.mapPixelToCoords( { 5, 60 } ) ) );
    }
    
    void MapEditorState::draw( const sf::Time dt )
    {
        m_game->m_window.draw( m_map );
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
