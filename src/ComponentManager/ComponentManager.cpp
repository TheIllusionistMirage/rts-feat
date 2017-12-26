#include <memory>

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
//             namespace Caption
//             {
            
            std::map<std::string, C_UICaption::Ptr> Caption::captions = {};
            
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
            
            void Caption::setCharSize( const std::string& ID, const int size )
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
//             }
            
            void updateUIComponents( const sf::Event& event, const sf::Time dt )
            {
                // Handle UI events
            }
            
            void renderUIComponents( sf::RenderWindow& window )
            {
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
