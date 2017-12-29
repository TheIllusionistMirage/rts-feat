#include "Utility/Constants.hpp"
#include "Utility/Log.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "Game.hpp"
#include "GameStates/MainMenuState.hpp"

namespace rts
{
    Game::Game() :
     m_window( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP ), WINDOW_TITLE, sf::Style::Close )
    {
        LOG(Logger::Level::DEBUG) << "Creating Game object." << std::endl;
        
        m_window.setFramerateLimit( FRAMES_PER_SECOND );
        
        // Load all textures
        
        if ( !ResourceManager::addTexture( TextureID::BACKGROUND, TEXTURES_LOCATION + BACKGROUND_TEXTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add background texture resource." << std::endl;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_BUTTON, UI_TEXTURES_LOCATION + UI_BUTTON_TEXTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI button texture resource." << std::endl;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_PICTURE_FRAME, UI_TEXTURES_LOCATION + UI_DEFAULT_PICTURE_TEXTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add default UI picture texture resource." << std::endl;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_RADIO_BUTTON_NORMAL, UI_TEXTURES_LOCATION + UI_RADIOBUTTON_NORMAL_TEXTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI radio button normal texture resource." << std::endl;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_LISTITEM, UI_TEXTURES_LOCATION + UI_LISTITEM_TEXTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI list item texture resource." << std::endl;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_COMBOBOX_SEL, UI_TEXTURES_LOCATION + UI_COMBOBOX_SELECTED_TEXTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI combo box texture resource." << std::endl;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_COMBOBOX_ARROW, UI_TEXTURES_LOCATION + UI_COMBOBOX_ARROW_TEXTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI combo box arrow texture resource." << std::endl;
        }
        
//         if (!ResourceManager::addTexture(TextureID::BUTTON, BUTTON_TEXTURE))
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add button texture resource." << std::endl;
//         }
//         
//         if (!ResourceManager::addTexture(TextureID::PICTURE_FRAME, PICTURE_FRAME_TEXTURE))
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add picture frame texture resource." << std::endl;
//         }
        
        // Load all fonts
        
        if ( !ResourceManager::addFont( FontID::DEFAULT, FONTS_LOCATION + DEFAULT_FONT ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add default font resource." << std::endl;
        }
        
        if (!ResourceManager::addFont(FontID::ROBOTO_BOLD, FONTS_LOCATION + ROBOTO_BOLD_FONT))
        {
            LOG(Logger::Level::DEBUG) << "Unable to add Roboto Bold font resource." << std::endl;
        }
        
        if (!ResourceManager::addFont(FontID::DEJAVU_SERIF, FONTS_LOCATION + DEJAVU_SERIF_FONT))
        {
            LOG(Logger::Level::DEBUG) << "Unable to add Deja Vu Serif font resource." << std::endl;
        }
        
        if (!ResourceManager::addFont(FontID::MONOSPACE, FONTS_LOCATION + MONOSPACE_FONT))
        {
            LOG(Logger::Level::DEBUG) << "Unable to add Monospace font resource." << std::endl;
        }
        
        if (!ResourceManager::addFont(FontID::MONACO, FONTS_LOCATION + MONACO_FONT))
        {
            LOG(Logger::Level::DEBUG) << "Unable to add Monospace font resource." << std::endl;
        }
        
        m_backgroundSprite.setTexture(*(ResourceManager::getTexture(TextureID::BACKGROUND)));
        
        m_fps.setFont(*(ResourceManager::getFont(FontID::DEFAULT)));
        m_fps.setString("FPS: 0");
        m_fps.setCharacterSize(10);
        m_fps.setPosition(sf::Vector2f{5, 5});
        m_fps.setFillColor(sf::Color::White);
        
        LOG(Logger::Level::DEBUG) << "Game object created." << std::endl;
        
        m_running = true;
    }
    
    Game::~Game()
    {
        while ( peekState() )
            popState();
        
        LOG(Logger::Level::DEBUG) << "Game object destroyed." << std::endl;
    }
    
    void Game::run()
    {
        LOG(Logger::Level::INFO) << "Game is running..." << std::endl;
        
        sf::Clock clock;
        sf::Time accumulator = sf::Time::Zero;
        sf::Time updateTime = sf::Time::Zero;
        unsigned frames = 0;
        
        while ( m_window.isOpen() && m_running && !m_states.empty() )
        {
            sf::Time elapsedTime = clock.restart();
            accumulator += elapsedTime;
            
            if ( !peekState() )
                continue;
            
            while ( accumulator > FRAME_TIME )
            {
                accumulator -= FRAME_TIME;
                
                if ( peekState() )
                {
                    peekState()->handleInput();
                    peekState()->update( FRAME_TIME );
                }
                
                // Update the components
                //CManager::UIComponent::updateUIComponents( eveent, FRAME_TIME );
            }
            
            updateTime += elapsedTime;
            frames++;
            
            if ( updateTime >= sf::seconds(1.f) )
            {
                m_fps.setString("FPS: " + std::to_string(frames));
                updateTime -= sf::seconds(1.f);
                frames = 0;
            }
            
            m_window.clear( sf::Color::Black );
            m_window.draw( m_backgroundSprite );
            
            if ( peekState() )
                peekState()->draw(FRAME_TIME);
            
            CManager::UIComponent::renderUIComponents( m_window );
            
            m_window.draw(m_fps);
            m_window.display();
        }
        
        LOG(Logger::Level::INFO) << "Game is stopped..." << std::endl;
        close();
    }
    
    void Game::close()
    {
        m_running = false;
        LOG(Logger::Level::DEBUG) << "Game shutdown" << std::endl;
    }
    
    void rts::Game::pushState(const rts::Game::State state)
    {
        switch ( state )
        {
            case State::MAIN_MENU:
            {
                m_states.push( std::make_shared<MainMenuState>( this ) );
            } break;
            
            case State::MAP_EDITOR:
            {
                
            } break;
            
            case State::GAME_START:
            {
                
            } break;
            
            case State::PLAYING:
            {
                
            } break;
            
            case State::PAUSED:
            {
                
            } break;
            
            default:
            {
                LOG(Logger::Level::ERROR) << "Unkown state" << std::endl;
            }
        }
    }
    
    void rts::Game::popState()
    {
        if ( m_states.empty() )
            return;
        
        m_states.pop();
    }
    
    void rts::Game::changeState(const rts::Game::State state)
    {
        if ( m_states.empty() )
            return;
        
        popState();
        pushState( state );
    }
    
    std::shared_ptr<GameState> Game::peekState()
    {
        if ( m_states.empty() )
            return nullptr;        
        return m_states.top();
    }
}
