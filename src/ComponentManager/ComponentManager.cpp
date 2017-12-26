#include <memory>

#include <SFML/Window/Event.hpp>

#include "Utility/Log.hpp"
#include "Utility/Constants.hpp"
#include "Utility/System.hpp"
#include "ComponentManager/ComponentManager.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {   
            // Initialize the static maps
            std::map<std::string, C_UICaption::Ptr> Caption::captions = {};
            std::map<std::string, C_UIBackground::Ptr> Background::backgrounds = {};
            
            ////////////////////////
            // Caption operations //
            ////////////////////////
            
            bool Caption::create( const std::string& ID, const std::string& text )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a Caption component" << std::endl;
                    return false;
                }
                
                if ( isStrWS( text ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid caption text used for creating a Caption component" << std::endl;
                    return false;
                }
                
                if ( captions.find( ID ) != captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") already exists" << std::endl;
                    return false;
                }
                
                //captions[ID] = std::make_shared<C_UICaption>( UI_DEFAULT_CAPTION_COMPONENT_TEXT );
                captions[ID] = std::make_shared<C_UICaption>( text );
                
                LOG(Logger::Level::DEBUG) << "New Caption component with ID: " + ID + " created." << std::endl;
                return true;
            }
            
            void Caption::destroy( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                auto it = captions.find( ID );
                
                if ( it == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                captions.erase( it );
                LOG(Logger::Level::DEBUG) << "Destroyed Caption component with ID: " + ID << std::endl;
            }
            
            void Caption::setCaption( const std::string& ID, const std::string& text )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                captions[ID]->m_text.setString( text );
            }
            
            const std::string Caption::getCaption( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return UI_INVALID_STRING;
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return UI_INVALID_STRING;
                }
                
                return captions[ID]->m_text.getString().toAnsiString();
            }
            
            void Caption::setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                captions[ID]->m_text.setPosition( position );
            }
            
            const sf::Vector2f Caption::getPosition( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return {};
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return captions[ID]->m_text.getPosition();
            }
            
            const sf::Vector2f Caption::getSize( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return {};
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return sf::Vector2f{ captions[ID]->m_text.getGlobalBounds().width,
                                      captions[ID]->m_text.getGlobalBounds().height };
            }
            
            void Caption::setCharSize( const std::string& ID, const int size )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                if ( size < 10 || size > 72 )
                {
                    LOG(Logger::Level::ERROR) << "Invalid character size for Caption component: " << size << std::endl;
                    return;
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                captions[ID]->m_text.setCharacterSize(size);
            }
            
            void Caption::setFont( const std::string& ID, FontID font )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                captions[ID]->m_text.setFont( *ResourceManager::getFont( font ) );
            }
            
            void Caption::setVisibility( const std::string& ID, const bool visibility )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Caption component" << std::endl;
                    return;
                }
                
                if ( captions.find( ID ) == captions.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Caption component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                captions[ID]->m_visible = visibility;
            }
            
            
            ///////////////////////////
            // Background operations //
            ///////////////////////////
            
            bool Background::create( const std::string& ID, const TextureID texID, const int sWidth, const int sHeight )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for creating a Background component" << std::endl;
                    return false;
                }
                
                if ( backgrounds.find( ID ) != backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") already exists" << std::endl;
                    return false;
                }
                
                backgrounds[ID] = std::make_shared<C_UIBackground>( texID, sWidth, sHeight );
                
                LOG(Logger::Level::DEBUG) << "New Background component with ID: " + ID + " created." << std::endl;
                return true;
            }
                    
            void Background::destroy( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                backgrounds.erase( it );
                LOG(Logger::Level::DEBUG) << "Destroyed Background component with ID: " + ID << std::endl;
            }
            
            void Background::setTexture( const std::string& ID, TextureID texID, const int sWidth, const int sHeight )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_sWidth = sWidth;
                it->second->m_sHeight = sHeight;
                it->second->m_state = C_UIBackground::State::NORMAL;
                
                it->second->m_background.setTexture( *ResourceManager::getTexture( texID ) );
                it->second->m_background.setTextureRect( sf::IntRect{ it->second->m_state * sWidth, 0, sWidth, sHeight } );
                
                LOG(Logger::Level::DEBUG) << "Updated the texture of Background component with ID(" + ID + ") to (" + textureIDToStr( texID ) + ")" << std::endl;
            }
            
            void Background::setState( const std::string& ID, C_UIBackground::State state )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                if ( state == C_UIBackground::State::INVALID )
                {
                    LOG(Logger::Level::ERROR) << "Cannot change state of Background component to an invalid state" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_state = state;                
                it->second->m_background.setTextureRect( sf::IntRect{ it->second->m_state * it->second->m_sWidth, 0, it->second->m_sWidth, it->second->m_sHeight } );
                
                //LOG(Logger::Level::DEBUG) << "Updated the state of Background component with ID(" + ID + ")" << std::endl;
            }
            
            C_UIBackground::State Background::getState( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return C_UIBackground::State::INVALID;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return C_UIBackground::State::INVALID;
                }
                
                return it->second->m_state;
            }
            
            void Background::setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_background.setPosition( position );
            }
            
            const sf::Vector2f Background::getPosition( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return {};
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return it->second->m_background.getPosition();
            }
            
            void Background::setSize( const std::string& ID, const sf::Vector2f& size )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                sf::Vector2f bgSize{ it->second->m_background.getGlobalBounds().width,
                                      it->second->m_background.getGlobalBounds().height };
                it->second->m_background.setScale( size.x / bgSize.x, size.y / bgSize.y );
            }
            
            const sf::Vector2f Background::getSize( const std::string& ID )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return {};
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return {};
                }
                
                return { it->second->m_background.getGlobalBounds().width,
                          it->second->m_background.getGlobalBounds().height };
            }
            
            void Background::setVisibility( const std::string& ID, const bool visibility )
            {
                if ( isStrWS( ID ) )
                {
                    LOG(Logger::Level::ERROR) << "Invalid ID used for accessing a Background component" << std::endl;
                    return;
                }
                
                auto it = backgrounds.find( ID );
                
                if ( it == backgrounds.end() )
                {
                    LOG(Logger::Level::ERROR) << "A Background component with the given key(" + ID + ") does not exist." << std::endl;
                    return;
                }
                
                it->second->m_visible = visibility;
            }
            
            // UI update and render operations
            
            void updateUIComponents( const sf::Event& event, const sf::Vector2i mousePos, const sf::Time dt )
            {
                switch (event.type)
                {
                    case sf::Event::MouseButtonPressed:
                    {
                        for ( auto&& bg : Background::backgrounds )
                        {
                            if (bg.second->m_enabled && bg.second->m_visible && bg.second->m_background.getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                            {
                                Background::setState( bg.first, C_UIBackground::State::DOWN );
                            }
                        }
                    } break;
                    
                    case sf::Event::MouseButtonReleased:
                    {
                        for ( auto&& bg : Background::backgrounds )
                        {
                            if (bg.second->m_enabled && bg.second->m_visible && bg.second->m_background.getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                            {
                                Background::setState( bg.first, C_UIBackground::State::NORMAL );
                            }
                        }
                    } break;
                    
                    case sf::Event::MouseMoved:
                    {
                        for ( auto&& bg : Background::backgrounds )
                        {
                            if (bg.second->m_enabled && bg.second->m_visible && bg.second->m_background.getGlobalBounds().contains( mousePos.x, mousePos.y ) )
                            {
                                Background::setState( bg.first, C_UIBackground::State::HOVER );
                            }
                            else
                            {
                                Background::setState( bg.first, C_UIBackground::State::NORMAL );
                            }
                        }
                    } break;
                }
            }
            
            void renderUIComponents( sf::RenderWindow& window )
            {
                for ( auto&& bg : Background::backgrounds )
                {
                    if ( bg.second->m_visible )
                    {
                        window.draw( *bg.second);
                    }
                }
                
                for ( auto&& cap : Caption::captions )
                {
                    if ( cap.second->m_visible )
                    {
                        window.draw( *cap.second );
                    }
                }
            }
        }
    }
}
