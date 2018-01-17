#ifndef ANIMATION_MANAGER_HPP
#define ANIMATION_MANAGER_HPP

#include <functional>
#include <string>
#include <map>

#include "ResourceManager/ResourceManager.hpp"
#include "WorldEntities/EntityComponents/Animation.hpp"

namespace rts
{
    namespace AnimationManager
    {
        class AnimationManager
        {
            public:
                
                static bool createAnimation( const std::string& id        ,
                                             sf::Sprite* entitySprite     ,
                                             const sf::Vector2i frameSize ,
                                             const unsigned maxFrame      ,
                                             const sf::Time frameDuration );
                
            private:
                
                static std::map<std::string, WorldEntities::EntityComponents::AnimationComponent::Ptr> m_animations;
        };
    }
}

#endif // ANIMATION_MANAGER_HPP
