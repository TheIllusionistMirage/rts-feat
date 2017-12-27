#include <functional>

#include <SFML/Window/Event.hpp>

#include "Utility/Constants.hpp"
#include "Utility/Log.hpp"
#include "UIManager/UIManager.hpp"
#include "GameStates/MainMenuState.hpp"

namespace rts
{    
    MainMenuState::MainMenuState(Game::Ptr game)
    {
        m_game = game;
        
//         std::string a = "007", b = "MyCaption";
//         UIManager::UILabel::create( a, b );
        
//         UIManager::UILabel::create( "007", "Koushtav Chakrabarty (koushtavc@gmail.com)" );
//         //UIManager::UILabel::setCaption( "007", "OtherCaption" );
//         UIManager::UILabel::setPosition( "007", { 100, 100 } );
//         UIManager::UILabel::setFont( "007", FontID::DEFAULT );
//         UIManager::UILabel::setCharSize( "007", 12 );
//         
//         UIManager::UILabel::create( "asd", "Iron Maiden" );
//         //UIManager::UILabel::setPosition( "asd", UIManager::UILabel::getPosition() + sf::Vector2f{ 100, 100 } );
//         UIManager::UILabel::setPosition( "asd", { 400, 200 } );
//         UIManager::UILabel::setVisibility( "asd", false );
//         UIManager::UILabel::setVisibility( "asd", true );
//         UIManager::UILabel::setFont( "asd", FontID::DEFAULT );
//         UIManager::UILabel::setFont( "asdsd", FontID::DEFAULT );
//         
//         UIManager::UIButton::create( "id", "ABOUT" );
//         UIManager::UIButton::setPosition( "id", { 500, 200 } );
//         UIManager::UIButton::setFont( "id", FontID::ROBOTO_BOLD );
//         
//         UIManager::UIButton::create( "008", "KOUSHTAV THE GREAT y" );
//         UIManager::UIButton::setPosition( "008", { 10, 250 } );        
//         UIManager::UIButton::setCharSize( "008", 20 );
//         UIManager::UIButton::setFont( "008", FontID::MONACO );
        
        UIManager::UILabel::create( "TitleLabel", "RTS-Feat" );
        UIManager::UILabel::setPosition( "TitleLabel", sf::Vector2f{ 225, 100 } );
        UIManager::UILabel::setFont( "TitleLabel", FontID::MONACO );
        UIManager::UILabel::setCharSize( "TitleLabel", 70 );
        
        UIManager::UIButton::create( "PlayButton", "   PLAY   " );
        sf::Vector2f pos = { UIManager::UILabel::getPosition( "TitleLabel" ).x + 100,
                              UIManager::UILabel::getPosition( "TitleLabel" ).y + 150 };
        UIManager::UIButton::setPosition( "PlayButton", pos );
        UIManager::UIButton::setCharSize( "PlayButton", 20);
        
        UIManager::UIButton::create( "MapEditorButton", "MAP EDITOR" );
        sf::Vector2f pos2 = { UIManager::UIButton::getPosition( "PlayButton" ).x,
                              UIManager::UIButton::getPosition( "PlayButton" ).y + 50 };
        
        UIManager::UIButton::setPosition( "MapEditorButton", pos2 );
        UIManager::UIButton::setCharSize( "MapEditorButton", 20);
        
        UIManager::UIButton::create( "OptionButton", " OPTIONS  " );
        sf::Vector2f pos3 = { UIManager::UIButton::getPosition( "MapEditorButton" ).x,
                              UIManager::UIButton::getPosition( "MapEditorButton" ).y + 50 };
        UIManager::UIButton::setPosition( "OptionButton", pos3 );
        UIManager::UIButton::setCharSize( "OptionButton", 20);
        
        UIManager::UIButton::create( "QuitButton", "   QUIT   " );
        sf::Vector2f pos4 = { UIManager::UIButton::getPosition( "OptionButton" ).x,
                              UIManager::UIButton::getPosition( "OptionButton" ).y + 50 };
        UIManager::UIButton::setPosition( "QuitButton", pos4 );
        UIManager::UIButton::setCharSize( "QuitButton", 20);
        
        LOG(Logger::Level::DEBUG) << "MainMenuState object created" << std::endl;
    }
    
    MainMenuState::~MainMenuState()
    {
        LOG(Logger::Level::DEBUG) << "MainMenuState object destroyed" << std::endl;
    }

    void MainMenuState::draw(const sf::Time dt)
    {
        
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
