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
#include "GameStates/MainMenuState.hpp"

namespace rts
{    
    MainMenuState::MainMenuState(Game::Ptr game)
    {
        m_game = game;
        
        UIManager::UILabelDefault::create( "test", "Options" );
        UIManager::UILabelDefault::setFont( "test", FontID::SOURCE_HAN_SANS_CN_NORMAL );
        //UIManager::UILabelDefault::setPosition( "test", { 100, 100 } );
        UIManager::UILabelDefault::setCharSize( "test", 15 );
//         UIManager::UILabelDefault::setPosition( "test", {0,0} );
         r.setFillColor( sf::Color::Blue );
         auto s = UIManager::UILabelDefault::getSize( "test" );
        r.setSize( { 200, 35 } );
//         //r.setSize( { s.x * 1.4, s.y * 2.1 } );
//         //r.setSize( { s.x + 50, s.y + 50 } );
         r.setPosition( {100,100} );
// //         if ( lower )
              UIManager::UILabelDefault::setOrigin( "test", { s.x/2, s.y/2 } );
// //         else
// //             UIManager::UILabelDefault::setOrigin( "test", { s.x/2, s.y/1.1 } );
//         //UIManager::UILabelDefault::setPosition( "test", {s.x * 0.075 / 2, s.y * 0.15 / 2} );
         //UIManager::UILabelDefault::setPosition( "test", { r.getPosition().x + r.getSize().x / 2, r.getPosition().y + r.getSize().y / 2 } );
// //         UIManager::UILabelDefault::setPosition( "test", { r.getSize().x / 2, r.getSize().y / 2 } );
         UIManager::UILabelDefault::setPosition( "test", { r.getPosition().x + r.getSize().x / 2, r.getPosition().y + r.getSize().y / 2 } );
        
        //////////////////
        
//         // Create the title label
//         UIManager::UILabel::create( "TitleLabel", "RTS-Feat" );
//         UIManager::UILabel::setFont( "TitleLabel", FontID::MONACO );
//         UIManager::UILabel::setCharSize( "TitleLabel", 70 );        
//         sf::Vector2f tSize = UIManager::UILabel::getSize( "TitleLabel" );
//         UIManager::UILabel::setPosition( "TitleLabel", sf::Vector2f{ m_game->m_window.getSize().x / 2.f - tSize.x / 2.f, tSize.y + 45 } );
//         
//         UIManager::UIButton::create( "PlayButton", "   Play   " );
//         UIManager::UIButton::setCharSize( "PlayButton", 20 );
//         sf::Vector2f pbSize = UIManager::UIButton::getSize( "PlayButton" );
//         UIManager::UIButton::setPosition( "PlayButton",
//                                            sf::Vector2f{ m_game->m_window.getSize().x / 2.f - pbSize.x / 2.f,
//                                                          UIManager::UILabel::getPosition( "TitleLabel").y + tSize.y + 50 } );
//         
//         UIManager::UIButton::create( "MapEditorButton", "Map Editor" );
//         UIManager::UIButton::setCharSize( "MapEditorButton", 20);
//         sf::Vector2f mebSize = UIManager::UIButton::getSize( "MapEditorButton" );
//         UIManager::UIButton::setPosition( "MapEditorButton",
//                                           sf::Vector2f{ m_game->m_window.getSize().x / 2.f - mebSize.x / 2.f,
//                                                         UIManager::UIButton::getPosition( "PlayButton").y + pbSize.y + 15 } );
//         
//         UIManager::UIButton::create( "OptionButton", " Options  " );
//         UIManager::UIButton::setCharSize( "OptionButton", 20);
//         sf::Vector2f obSize = UIManager::UIButton::getSize( "OptionButton" );
//         UIManager::UIButton::setPosition( "OptionButton",
//                                           sf::Vector2f{ m_game->m_window.getSize().x / 2.f - obSize.x / 2.f,
//                                                         UIManager::UIButton::getPosition( "MapEditorButton").y + mebSize.y + 15 } );
//         
//         UIManager::UIButton::create( "AboutButton", "  About   " );
//         UIManager::UIButton::setCharSize( "AboutButton", 20);
//         sf::Vector2f abSize = UIManager::UIButton::getSize( "AboutButton" );
//         UIManager::UIButton::setPosition( "AboutButton",
//                                           sf::Vector2f{ m_game->m_window.getSize().x / 2.f - abSize.x / 2.f,
//                                                         UIManager::UIButton::getPosition( "OptionButton").y + obSize.y + 15 } );
//         
//         UIManager::UIButton::create( "QuitButton", "   Quit   " );
//         UIManager::UIButton::setCharSize( "QuitButton", 20);
//         sf::Vector2f qbSize = UIManager::UIButton::getSize( "QuitButton" );
//         UIManager::UIButton::setPosition( "QuitButton",
//                                           sf::Vector2f{ m_game->m_window.getSize().x / 2.f - qbSize.x / 2.f,
//                                                         UIManager::UIButton::getPosition( "AboutButton").y + abSize.y + 15 } );
        
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
        
        LOG(Logger::Level::DEBUG) << "MainMenuState object created" << std::endl;
    }
    
    MainMenuState::~MainMenuState()
    {
        LOG(Logger::Level::DEBUG) << "MainMenuState object destroyed" << std::endl;
    }

    void MainMenuState::draw(const sf::Time dt)
    {
        m_game->m_window.draw( r );
    }

    void MainMenuState::update(const sf::Time dt)
    {
        //m_console.update(dt);
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
                    } break;
                    
                    case sf::Event::MouseMoved:
                    {
                    }
                }
            }
            
            CManager::UIComponent::updateUIComponents( event, mousePos, FRAME_TIME );
        }
    }
    
}
