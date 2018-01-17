#include <climits>

#include "Utility/Constants.hpp"
#include "Utility/Log.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "WorldEntities/EntityComponents/Animation.hpp"

namespace rts
{
    namespace WorldEntities
    {
        namespace EntityComponents
        {
            AnimationComponent::AnimationComponent() :
             m_entitySprite{ nullptr },
             m_textureRect{ INT_MIN, INT_MIN, INT_MIN, INT_MIN },
             m_frameSize{ INT_MIN, INT_MIN },
             m_currentFrame{ -1 },
             m_maxFrame{ INT_MAX },
             m_frameDuration{ sf::Time::Zero },
             m_elapsedTime{ sf::Time::Zero },
             m_loop{ false }
            {
                //LOG(Logger::Level::DEBUG) << "Empty AnimationComponent created." << std::endl;
            }
            
            AnimationComponent::AnimationComponent( sf::Sprite* entitySprite,
                                                    const sf::Vector2i frameSize,
                                                    const unsigned maxFrame,
                                                    const sf::Time frameDuration ) :
             m_entitySprite{ entitySprite },
             m_frameSize{ frameSize },
             m_currentFrame{ 0 },
             m_maxFrame{ static_cast<int>( maxFrame ) },
             m_frameDuration{ frameDuration },
             m_elapsedTime{ sf::Time::Zero },
             m_loop{ false }
            {
                //LOG(Logger::Level::DEBUG) << "AnimationComponent created." << std::endl;
                m_textureRect = sf::IntRect{ 0, 0, m_frameSize.x, m_frameSize.y };
                m_entitySprite->setTextureRect( m_textureRect );
            }
        }
    }
}
