#include <functional>

#include <SFML/Window/Event.hpp>

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
        
        UIManager::UILabel::create( "007", "MyCaption" );
        UIManager::UILabel::setCaption( "007", "OtherCaption" );
        UIManager::UILabel::setPosition( "007", { 100, 100 } );
        
        UIManager::UILabel::create( "asd", "Iron Maiden" );
        //UIManager::UILabel::setPosition( "asd", UIManager::UILabel::getPosition() + sf::Vector2f{ 100, 100 } );
        UIManager::UILabel::setPosition( "asd", { 400, 200 } );
        
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
        }
    }
    
}
