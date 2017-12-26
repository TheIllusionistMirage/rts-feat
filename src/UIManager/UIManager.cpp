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
                
            }
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Caption::setPosition( ID, position );
            }
        }
    }
}
