//#include <SFML/System/Vector2.hpp>

#include "Utility/Log.hpp"
#include "Utility/Constants.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "UIManager/UIManager.hpp"

namespace rts
{
    namespace UIManager
    {
        namespace UILabel
        {
            bool create( const std::string& ID, const std::string& text )
            {
                if ( CManager::UIComponent::Caption::create( ID, text ) )
                {
                    LOG(Logger::Level::DEBUG) << "UILabel instance with ID: " + ID + " and Caption: " + text + " created." << std::endl;
                    return true;
                }
                
                LOG(Logger::Level::ERROR) << "Unable to create UILabel instance with ID: " + ID << std::endl;
                return false;
            }
            
            void destroy( const std::string& ID )
            {
                CManager::UIComponent::Caption::destroy( ID );
                LOG(Logger::Level::DEBUG) << "UILabel instance with ID: " + ID + " destroyed." << std::endl;
            }
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
            }
            
            const std::string getCaption( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getCaption( ID );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Caption::setPosition( ID, position );
            }
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getPosition( ID );
            }
            
            void setCharSize( const std::string& ID, const int size )
            {
                CManager::UIComponent::Caption::setCharSize( ID, size );
            }
            
            void setFont( const std::string& ID, FontID font )
            {
                CManager::UIComponent::Caption::setFont( ID, font );
            }
            
            void setVisibility( const std::string& ID, const bool visibility )
            {
                CManager::UIComponent::Caption::setVisibility( ID, visibility );
            }
        }
        
        namespace UIButton
        {
            bool create( const std::string& ID, const std::string& text )
            {
                // A UIButton uses two components - Background & Caption
                
                if ( !CManager::UIComponent::Caption::create( ID, text ) )
                {
                    //LOG(Logger::Level::ERROR) << "Unable to create Caption instance with ID: " + ID << std::endl;
                    return false;
                }
                
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Background::create( ID, TextureID::UI_BUTTON, UI_BUTTON_TEXTURE_WIDTH, UI_BUTTON_TEXTURE_HEIGHT );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 20, cSize.y + 15 } );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + 10, bgPos.y + 5 } );
                
                LOG(Logger::Level::DEBUG) << "UIButton instance with ID: " + ID + " and Caption: " + text + " created." << std::endl;
                
                return true;
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Background::setPosition( ID, position );
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + 10, bgPos.y + 5 } );
            }
        }
    }
}
