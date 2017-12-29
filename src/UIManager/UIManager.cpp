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
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getSize( ID );
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
                    LOG(Logger::Level::ERROR) << "Unable to create Caption instance with ID: " + ID << std::endl;
                    return false;
                }
                
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                
                if ( !CManager::UIComponent::Background::create( ID, TextureID::UI_BUTTON, UI_BUTTON_TEXTURE_WIDTH, UI_BUTTON_TEXTURE_HEIGHT ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Background instance with ID: " + ID << std::endl;
                    return false;
                }
                
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 30, cSize.y + 20 } );
                
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );
                
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2, bgPos.y + bgSize.y / 2.5f } );
                
                LOG(Logger::Level::DEBUG) << "UIButton instance with ID: " + ID + " and Caption: " + text + " created." << std::endl;
                
                return true;
            }
            
            void destroy( const std::string& ID )
            {
                CManager::UIComponent::Background::destroy( ID );
                CManager::UIComponent::Caption::destroy( ID );
                
                LOG(Logger::Level::DEBUG) << "UIButton instance with ID: " + ID + " destroyed." << std::endl;
            }
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 30, cSize.y + 20 } );
                
                setPosition( ID, getPosition( ID ) );
            }
            
            const std::string getCaption( const std::string& ID )
            {
                return CManager::UIComponent::Caption::getCaption( ID );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Background::setPosition( ID, position );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                auto bgPos = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2, bgPos.y + bgSize.y / 2.5f } );
            }
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Background::getPosition( ID );
            }
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                return CManager::UIComponent::Background::getSize( ID );
            }
            
            void setCharSize( const std::string& ID, const int size )
            {
                CManager::UIComponent::Caption::setCharSize( ID, size );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 1.5f } );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 30, cSize.y + 20 } );
                //CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x * 1.05f, cSize.y * 1.6f } );
                setPosition( ID, getPosition( ID ) );
            }
            
            void setFont( const std::string& ID, FontID font )
            {
                CManager::UIComponent::Caption::setFont( ID, font );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                CManager::UIComponent::Background::setSize( ID, sf::Vector2f{ cSize.x + 30, cSize.y + 20 } );
            }
            
            void setVisibility( const std::string& ID, const bool visibility )
            {
                CManager::UIComponent::Caption::setVisibility( ID, visibility );
                CManager::UIComponent::Background::setVisibility( ID, visibility );
            }
        }
        
        namespace UIPicture
        {
            bool create( const std::string& ID, const TextureID tID, const int sWidth, const int sHeight, const std::string& text )
            {
                if ( !CManager::UIComponent::Background::create( ID, tID, sWidth, sHeight) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Background instance with ID: " + ID << std::endl;
                    return false;
                }
                
                if ( !CManager::UIComponent::Caption::create( ID, text ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create Caption instance with ID: " + ID << std::endl;
                    return false;
                }
                
                CManager::UIComponent::Caption::setFont( ID, FontID::DEFAULT );
                CManager::UIComponent::Caption::setCharSize( ID, 11 );
                
                auto bgPos  = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 2.f } );                
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2.f,
                                                                                bgPos.y + bgSize.y + cSize.y / 2.f } );
                
                return true;
            }
            
            void setPicture( const std::string& ID, const TextureID tID, const int sWidth, const int sHeight )
            {
                CManager::UIComponent::Background::setTexture( ID, tID, sWidth, sHeight );
            }
            
            void setCaption( const std::string& ID, const std::string& text )
            {
                CManager::UIComponent::Caption::setCaption( ID, text );
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Background::setPosition( ID, position );
                
                auto bgPos  = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 2.f } );                
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2.f,
                                                                                bgPos.y + bgSize.y + cSize.y / 2.f } );
            }
            
            const sf::Vector2f getPosition( const std::string& ID )
            {
                return CManager::UIComponent::Background::getPosition( ID );
            }
            
            void setSize( const std::string& ID, const sf::Vector2f& size )
            {
                CManager::UIComponent::Background::setSize( ID, size );
                
                auto bgPos  = CManager::UIComponent::Background::getPosition( ID );
                auto bgSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ cSize.x / 2.f, cSize.y / 2.f } );
                
                CManager::UIComponent::Caption::setPosition( ID, sf::Vector2f{ bgPos.x + bgSize.x / 2.f,
                                                                                bgPos.y + bgSize.y + cSize.y / 2.f } );
            }
            
            const sf::Vector2f getSize( const std::string& ID )
            {
                return CManager::UIComponent::Background::getSize( ID );
            }
        }
        
        namespace UIRadioButton
        {
            bool create( const std::string& ID, const std::string& text )
            {
                if ( !CManager::UIComponent::Background::create( ID, TextureID::UI_RADIO_BUTTON_NORMAL, UI_RADIOBUTTON_TEXTURE_WIDTH, UI_RADIOBUTTON_TEXTURE_HEIGHT ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create UIRadioButton instance with ID: " << ID << std::endl;
                    return false;
                }
                
                if ( !CManager::UIComponent::Caption::create( ID, text ) )
                {
                    LOG(Logger::Level::ERROR) << "Unable to create UIRadioButton instance with ID: " << ID << std::endl;
                    return false;
                }
                
                auto bPos = CManager::UIComponent::Background::getPosition( ID );
                auto bSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ 0, cSize.y / 2.5f } );
                CManager::UIComponent::Caption::setPosition( ID, { bPos.x + bSize.x + 10, bPos.y + bSize.y / 2.5f } );
                
                return true;
            }
            
            void setPosition( const std::string& ID, const sf::Vector2f& position )
            {
                CManager::UIComponent::Background::setPosition( ID, position );
                auto bPos = CManager::UIComponent::Background::getPosition( ID );
                auto bSize = CManager::UIComponent::Background::getSize( ID );
                auto cSize = CManager::UIComponent::Caption::getSize( ID );
                
                CManager::UIComponent::Caption::setOrigin( ID, sf::Vector2f{ 0, cSize.y / 2.5f } );
                CManager::UIComponent::Caption::setPosition( ID, { bPos.x + bSize.x + 10, bPos.y + bSize.y / 2.5f } );
            }
        }
    }
}
