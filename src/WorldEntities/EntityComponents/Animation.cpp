/*
 * ------------------------------
 *  Module    : AnimationManager
 *  Submodule : Animation
 * ------------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 17-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods & classes declared
 *  in Animation submodule.
 * 
 */

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
             m_textureRect{ INT_MIN, INT_MIN, INT_MIN, INT_MIN },
             m_frameSize{ INT_MIN, INT_MIN },
             m_currentFrame{ -1 },
             m_maxFrame{ INT_MAX },
             m_duration{ sf::Time::Zero },
             m_elapsedTime{ sf::Time::Zero },
             m_loop{ true }
            {
                //LOG(Logger::Level::DEBUG) << "Empty AnimationComponent created." << std::endl;
                m_entitySprite.m_spritePtr = nullptr;
                m_entitySprite.m_vertexArrayPtr = nullptr;
            }
            
            AnimationComponent::AnimationComponent( sf::Sprite* entitySprite,
                                                    const sf::Vector2i frameSize,
                                                    const unsigned maxFrame,
                                                    const sf::Time duration ) :
             m_frameSize{ frameSize },
             m_currentFrame{ 0 },
             m_maxFrame{ static_cast<int>( maxFrame ) },
             m_duration{ duration },
             m_elapsedTime{ sf::Time::Zero },
             m_loop{ true }
            {
                m_entitySprite.m_spritePtr = entitySprite;
                m_textureRect = sf::IntRect{ 0, 0, m_frameSize.x, m_frameSize.y };
                m_entitySprite.m_spritePtr->setTextureRect( m_textureRect );
            }
            
            AnimationComponent::AnimationComponent( sf::VertexArray* vertexArray,
                                                    const sf::Vector2i frameSize,
                                                    const unsigned maxFrame,
                                                    const sf::Time duration ) :
             m_frameSize{ frameSize },
             m_currentFrame{ 0 },
             m_maxFrame{ static_cast<int>( maxFrame ) },
             m_duration{ duration },
             m_elapsedTime{ sf::Time::Zero },
             m_loop{ true }
            {
                m_entitySprite.m_vertexArrayPtr = vertexArray;
                m_textureRect = sf::IntRect{ 0, 0, m_frameSize.x, m_frameSize.y };
                m_entitySprite.m_spritePtr->setTextureRect( m_textureRect );
            }
        }
    }
}
