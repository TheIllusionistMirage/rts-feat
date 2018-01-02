/*
 * ---------------
 *  Module : Game
 * ---------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods & classes declared
 *  in Game module.
 */

#include "Utility/Constants.hpp"
#include "Utility/Log.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "GameStates/MainMenuState.hpp"
#include "Game.hpp"

namespace rts
{
    Game::Game()
    {
        // Create a new game window with the default dimensions
        // and title as set in the Utility::Constants module.
        m_window.create( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP ),
                         WINDOW_TITLE,
                         sf::Style::Close );
        
        LOG(Logger::Level::DEBUG) << "Creating Game object." << std::endl;
        
        // Limit the game frame rate as set in Utility::Constants module.
        m_window.setFramerateLimit( FRAMES_PER_SECOND );
                
        /* Import all game assets by invoking the apporiate methods of the resource manager module.
         * 
         * 1. First the textures are imported.
         * 2. Next the fonts are imported.
         */
        
        bool allResLoaded = true;
        
        if ( !ResourceManager::addTexture( TextureID::DEFAULT_BACKGROUND, PATH_TEXTURES + TEXTURE_DEFAULT_BACKGROUND ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add background texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::MAIN_MENU_BACKGROUND, PATH_TEXTURES + TEXTURE_MAIN_MENU_BACKGROUND) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add main menu background texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_BUTTON, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_BUTTON ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI button texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_PICTURE, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_PICTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add default UI picture texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_RADIOBUTTON_NORMAL, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_RADIOBUTTON_NORMAL ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI radio button normal texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_LISTITEM, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_LISTITEM ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI list item texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_COMBOBOX_SELECTED, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_COMBOBOX_SELECTED ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI combo box texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_COMBOBOX_ARROW, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_COMBOBOX_ARROW ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI combo box arrow texture resource." << std::endl;
            allResLoaded = false;
        }
        
        
        // Load all fonts
        
        if ( !ResourceManager::addFont( FontID::DEFAULT, PATH_FONTS + FONT_DEFAULT ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add default font resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::BASKERVILLE_OLD_FACE_REGULAR, PATH_FONTS + FONT_BASKERVILLE_OLD_FACE_REGULAR ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::BASKERVILLE_OLD_FACE_REGULAR ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::BEYOND_WONDERLAND, PATH_FONTS + FONT_BEYOND_WONDERLAND ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::BEYOND_WONDERLAND ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::BOOK_ANTIQUA_BOLD, PATH_FONTS + FONT_BOOK_ANTIQUA_BOLD ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::BOOK_ANTIQUA_BOLD ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::CONSTANTIA_REGULAR, PATH_FONTS + FONT_CONSTANTIA_REGULAR ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::CONSTANTIA_REGULAR ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::DEJAVU_SERIF_BOOK, PATH_FONTS + FONT_DEJAVU_SERIF_BOOK ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::DEJAVU_SERIF_BOOK ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::GARAMOND_BOLD, PATH_FONTS + FONT_GARAMOND_BOLD ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::GARAMOND_BOLD ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::MONACO, PATH_FONTS + FONT_MONACO ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::MONACO ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::OLD_SERIF_GUT_REGULAR, PATH_FONTS + FONT_OLD_SERIF_GUT_REGULAR ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::OLD_SERIF_GUT_REGULAR ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::RINGBEARER_MEDIUM, PATH_FONTS + FONT_RINGBEARER_MEDIUM ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::RINGBEARER_MEDIUM ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::ROBOTO_BOLD, PATH_FONTS + FONT_ROBOTO_BOLD ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::ROBOTO_BOLD ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::SOURCE_HAN_SANS_CN_NORMAL, PATH_FONTS + FONT_SOURCE_HAN_SANS_CN_NORMAL ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::SOURCE_HAN_SANS_CN_NORMAL ) << std::endl;
            allResLoaded = false;
        }
        
        if ( allResLoaded )
        {
            m_backgroundSprite.setTexture( *ResourceManager::getTexture( TextureID::DEFAULT_BACKGROUND ) );
        
            m_fps.setFont( *ResourceManager::getFont( FontID::DEFAULT ) );
            m_fps.setString( "FPS: 0" );
            m_fps.setCharacterSize( 10 );
            m_fps.setPosition( sf::Vector2f{5, 5} );
            m_fps.setFillColor( sf::Color::White );
            
            LOG(Logger::Level::DEBUG) << "Game object created." << std::endl;
            
            m_running = true;
        }
        else
        {
            m_running = false;
            LOG(Logger::Level::ERROR) << "Unable to create Game object" << std::endl;
        }
    }
    
//     Game::~Game()
//     {
//         while ( peekState() )
//             popState();
//         
//         LOG(Logger::Level::DEBUG) << "Game object destroyed." << std::endl;
//     }
    
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
            
            //m_window.draw(m_fps);
            m_window.display();
        }
        
        LOG(Logger::Level::INFO) << "Game stopped..." << std::endl;
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
                auto tex = ResourceManager::getTexture( TextureID::MAIN_MENU_BACKGROUND );
                m_backgroundSprite.setTexture( *tex );
                m_backgroundSprite.setTextureRect( sf::IntRect{ 0, 0, tex->getSize().x, tex->getSize().y } );
            } break;
            
            case State::START_GAME:
            {
                
            } break;
            
            case State::PLAYING:
            {
                
            } break;
            
            case State::MAP_EDITOR:
            {
                
            } break;
            
            case State::PAUSED:
            {
                
            } break;
            
            default:
            {
                LOG(Logger::Level::ERROR) << "Invalid state" << std::endl;
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
