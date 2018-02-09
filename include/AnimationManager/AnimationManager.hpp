#ifndef ANIMATION_MANAGER_HPP
#define ANIMATION_MANAGER_HPP

#include <functional>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include <SFML/Window/Event.hpp>

#include "ResourceManager/ResourceManager.hpp"
#include "WorldEntities/EntityComponents/Animation.hpp"

namespace rts
{
    namespace AnimationManager
    {
        class AnimationManager
        {
            public:
                
                static bool exists( const std::string& id );
                
                static int count();
                
                static bool createAnimation( const std::string& id        ,
                                             sf::Sprite* entitySprite     ,
                                             const sf::Vector2i frameSize ,
                                             const unsigned maxFrame      ,
                                             const sf::Time frameDuration );
                
                static bool createAnimation( const std::string& id        ,
                                             sf::VertexArray* vertexArray ,
                                             const sf::Vector2i frameSize ,
                                             const unsigned maxFrame      ,
                                             const sf::Time frameDuration );
                
                static void destroyAnimation( const std::string& ID );
                
                // Sync a group of animation components to start together
                static void syncAnimations( const std::vector<std::string>& animations );
                
                static void setVisibility( const std::string& id, bool visibility );
                
                ////////////
                // Update //
                ////////////
                
//                 static void update( const sf::Event& event,
//                                     const sf::Vector2i mousePos,
//                                     const sf::Time dt );
                
                static void update( const sf::Time dt );
                
            private:
                
                static std::unordered_map<std::string, WorldEntities::EntityComponents::AnimationComponent::Ptr> m_animations;
        };
    }
}

#endif // ANIMATION_MANAGER_HPP
