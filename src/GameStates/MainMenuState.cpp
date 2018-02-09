/*
 * ---------------------------
 *  Module    : GameStates
 *  Submodule : MainMenuState
 * ---------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
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
#include "AnimationManager/AnimationManager.hpp"
#include "GameStates/MainMenuState.hpp"
#include "GameStates/MapEditorState.hpp"

namespace rts
{    
    MainMenuState::MainMenuState(Game::Ptr game) : m_testVArr{ sf::Quads, 4 }
    {
        m_game = game;
        
        //////////////////
        
        // Create the title label
        UIManager::UILabel::create( "TitleLabel", "Kings & Queens" );
        UIManager::UILabel::setFont( "TitleLabel", FontID::CLOISTER_BLACK_LIGHT );
        UIManager::UILabel::setCharSize( "TitleLabel", 70 );        
        UIManager::UILabel::setFontColor( "TitleLabel", sf::Color( 45, 45, 45 ) );
        sf::Vector2f tSize = UIManager::UILabel::getSize( "TitleLabel" );
        UIManager::UILabel::setPosition( "TitleLabel", sf::Vector2f{ m_game->m_window.getSize().x / 2.f - tSize.x / 2.f, tSize.y + 10 } );
        
        // Create the play menu button
        UIManager::UIMenuButton::create( "PlayButton", "Play" );
        sf::Vector2f pbSize = UIManager::UIMenuButton::getSize( "PlayButton" );
        UIManager::UIMenuButton::setPosition( "PlayButton",
                                              sf::Vector2f{ m_game->m_window.getSize().x / 2.f - pbSize.x / 2.f,
                                                            UIManager::UILabel::getPosition( "TitleLabel").y + tSize.y + 40 } );
        
        // Create the map editor menu button
        UIManager::UIMenuButton::create( "MapEditorButton", "Map Editor" );
        sf::Vector2f mebSize = UIManager::UIMenuButton::getSize( "MapEditorButton" );
        UIManager::UIMenuButton::setPosition( "MapEditorButton",
                                              sf::Vector2f{ m_game->m_window.getSize().x / 2.f - mebSize.x / 2.f,
                                                            UIManager::UIMenuButton::getPosition( "PlayButton").y + pbSize.y + 5 } );
        
        // Create the options menu button
        UIManager::UIMenuButton::create( "OptionButton", "Options" );
        sf::Vector2f obSize = UIManager::UIMenuButton::getSize( "OptionButton" );
        UIManager::UIMenuButton::setPosition( "OptionButton",
                                              sf::Vector2f{ m_game->m_window.getSize().x / 2.f - obSize.x / 2.f,
                                                            UIManager::UIMenuButton::getPosition( "MapEditorButton").y + mebSize.y + 5 } );
        
        // Create the about menu button
        UIManager::UIMenuButton::create( "AboutButton", "About" );
        sf::Vector2f abSize = UIManager::UIMenuButton::getSize( "AboutButton" );
        UIManager::UIMenuButton::setPosition( "AboutButton",
                                              sf::Vector2f{ m_game->m_window.getSize().x / 2.f - abSize.x / 2.f,
                                                            UIManager::UIMenuButton::getPosition( "OptionButton").y + obSize.y + 5 } );
        
        // Create the quit menu button
        UIManager::UIMenuButton::create( "QuitButton", "Quit" );
        sf::Vector2f qbSize = UIManager::UIMenuButton::getSize( "QuitButton" );
        UIManager::UIMenuButton::setPosition( "QuitButton",
                                              sf::Vector2f{ m_game->m_window.getSize().x / 2.f - qbSize.x / 2.f,
                                                            UIManager::UIMenuButton::getPosition( "AboutButton").y + abSize.y + 5 } );
        
        
        // Set the callbacks for the buttons
        
        //UIManager::UIMenuButton::setCallback( "MapEditorButton", std::bind( &Game::pushState, m_game, Game::State::MAP_EDITOR ), CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        
        //UIManager::UIMenuButton::setCallback( "MapEditorButton", std::bind( &MainMenuState::stateTransition, this, Game::State::MAP_EDITOR ), CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        UIManager::UIMenuButton::setCallback( "MapEditorButton", [this,&m_game = m_game](){ this->stateTransition( Game::State::MAP_EDITOR ); }, CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        
        //UIManager::UIMenuButton::setCallback( "QuitButton", std::bind( &Game::close, m_game ), CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        UIManager::UIMenuButton::setCallback( "QuitButton", [this, &m_game = m_game](){ m_game->close(); }, CManager::UIComponent::UIEvent::MOUSE_RELEASED );
        
//         static sf::Texture tex;
//         tex.loadFromFile( "spritestrip.png" );
//         m_testSprite.setTexture( tex );
//         AnimationManager::AnimationManager::createAnimation( "anim", &m_testSprite, sf::Vector2i{ 256, 256 }, 5, sf::seconds(0.5) );
//         
//         m_testVArr[0].texCoords = sf::Vector2f{ 64.f, 0.f };
//         m_testVArr[1].texCoords = sf::Vector2f{ 128.f, 32.f };
//         m_testVArr[2].texCoords = sf::Vector2f{ 64.f, 64.f };
//         m_testVArr[3].texCoords = sf::Vector2f{ 0.f, 32.f };
//         
//         sf::Vector2f position{ 200.f, 0.f };
//         m_testVArr[0].position = position;
//         m_testVArr[1].position = sf::Vector2f{ m_testVArr[0].position.x + 64.f, m_testVArr[0].position.y + 32.f };
//         m_testVArr[2].position = sf::Vector2f{ m_testVArr[0].position.x, m_testVArr[0].position.y + 64.f };
//         m_testVArr[3].position = sf::Vector2f{ m_testVArr[0].position.x - 64.f, m_testVArr[0].position.y + 32.f };
//         
//         AnimationManager::AnimationManager::createAnimation( "anim2", &m_testVArr, sf::Vector2i{ 128, 64 }, 3, sf::seconds(1.f) );
        
        /////////////
        
//         UIManager::UIPicture::create( "T", TextureID::UI_PICTURE_FRAME, UI_DEFAULT_PICTURE_TEXTURE_WIDTH, UI_DEFAULT_PICTURE_TEXTURE_HEIGHT , "This is a picture\nFrame" );
//         UIManager::UIPicture::setPosition( "T", { 500, 300 } );
        
//         UIManager::UIRadioButton::create( "T", "RadioButton" );
//         UIManager::UIRadioButton::setPosition( "T", { 500, 300 } );
//         
//         UIManager::UIRadioButton::create( "T1", "AnotherRadioButton" );
//         UIManager::UIRadioButton::setPosition( "T1", { 500, 320 } );
//         
//         UIManager::UIRadioButton::create( "T2", "YetAnotherRadioButton" );
//         UIManager::UIRadioButton::setPosition( "T2", { 500, 340 } );
//         
//         UIManager::UIRadioButton::create( "T3", "KLOLZISTOPPED!!!" );
//         UIManager::UIRadioButton::setPosition( "T3", { 500, 360 } );
        
//         UIManager::UIListItem::create( "li", "  Indians  " );
// //         UIManager::UIListItem::setPosition( "li", { 500, 200 } );
// //         
//          UIManager::UIListItem::create( "li2", " Americans " );
//          UIManager::UIListItem::create( "li3", "  Germans  " );
//          UIManager::UIListItem::create( "li4", " Japanese  " );
//          UIManager::UIListItem::create( "li5", "  Chinese  " );
//          UIManager::UIListItem::create( "li6", "   Korean  " );
//          UIManager::UIListItem::create( "li7", "  Spanish  " );
//          UIManager::UIListItem::create( "li8", "  Persian  " );
//          UIManager::UIListItem::create( "li9", "   Azects  " );
//          UIManager::UIListItem::create( "li10", "  Britons  " );
// //         
// //         UIManager::UIListBox::create( "lb" );
// //         UIManager::UIListBox::add( "lb", "li" );
// //         UIManager::UIListBox::add( "lb", "li2" );
// //         UIManager::UIListBox::add( "lb", "li3" );
// //         UIManager::UIListBox::add( "lb", "li4" );
// //         UIManager::UIListBox::add( "lb", "li5" );
//         
//         auto foo = std::vector<std::string>{ "li", "li2", "li3", "li4", "li5", "li6", "li7", "li8", "li9", "li10" };
//         UIManager::UIComboBox::create( "cb", foo );
//         UIManager::UIComboBox::setPosition( "cb", {200, 50} );
        
        //std::cout << "Ref counts: " << ResourceManager::getTexture( TextureID::TERRAIN_TILE_DESERT_0_0000 ).use_count() << std::endl;
        
        LOG(Logger::Level::DEBUG) << "MainMenuState object created" << std::endl;
    }
    
    MainMenuState::~MainMenuState()
    {
        LOG(Logger::Level::DEBUG) << "MainMenuState object destroyed" << std::endl;
    }
    
    void MainMenuState::handleInput()
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
                        auto foo = (long)ResourceManager::getTexture( TextureID::TERRAIN_TILE_DESERT_0_0000 ).get();
                        //std::cout << "Addr: " << foo << std::endl;
                    } break;
                    
                    case sf::Event::MouseMoved:
                    {
                    } break;
                    
                    case sf::Event::LostFocus:
                    {
                        m_game->m_active = false;
                    } break;
                    
                    case sf::Event::GainedFocus:
                    {
                        m_game->m_active = true;
                        //std::cout << "AAAAAAAAAAAA" << std::endl;
                    } break;
                }
            }
            
            //CManager::UIComponent::updateUIComponents( event, mousePos, FRAME_TIME );
            if ( m_game->m_active )
            {
                CManager::UIComponent::updateUIComponents( event, static_cast<sf::Vector2i>( m_game->m_window.mapPixelToCoords( mousePos ) ), FRAME_TIME );
                //AnimationManager::AnimationManager::update( event, static_cast<sf::Vector2i>( m_game->m_window.mapPixelToCoords( mousePos ) ), FRAME_TIME );
            }
        }
    }

    void MainMenuState::update(const sf::Time dt)
    {
        //m_console.update(dt);
        //AnimationManager::AnimationManager::update( FRAME_TIME );
    }
    
    void MainMenuState::draw(const sf::Time dt)
    {
        //m_game->m_window.draw( m_testSprite );
        //auto tex = ResourceManager::getTexture( TextureID::TERRAIN_ANIMATED_TILE_WATER_DEFAULT );
        //m_game->m_window.draw( m_testVArr, tex.get() );
    }
    
    void MainMenuState::freeze(bool f)
    {
        auto tex = ResourceManager::getTexture( TextureID::MAIN_MENU_BACKGROUND );
        m_game->m_backgroundSprite.setTexture( *tex );
        m_game->m_backgroundSprite.setTextureRect( sf::IntRect{ 0, 0, tex->getSize().x, tex->getSize().y } );
        
        UIManager::UILabel::setVisibility( "TitleLabel", !f );
        UIManager::UIMenuButton::setVisibility( "PlayButton", !f );
        UIManager::UIMenuButton::setVisibility( "MapEditorButton", !f );
        UIManager::UIMenuButton::setVisibility( "OptionButton", !f );
        UIManager::UIMenuButton::setVisibility( "AboutButton", !f );
        UIManager::UIMenuButton::setVisibility( "QuitButton", !f );
    }
    
    void MainMenuState::stateTransition( Game::State state )
    {
        freeze(true);
        m_game->pushState( state );
    }
}
