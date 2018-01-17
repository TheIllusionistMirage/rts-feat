#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

namespace rts
{
    namespace WorldEntities
    {
        namespace EntityComponents
        {
            struct AnimationComponent
            {
                public:
                    
                    typedef std::shared_ptr<AnimationComponent> Ptr;
                    
                    AnimationComponent();
                    
                    AnimationComponent( sf::Sprite* entitySprite,
                                        const sf::Vector2i frameSize,
                                        const unsigned maxFrame,
                                        const sf::Time frameDuration );
                    
                    // The sprite of the entity
                    sf::Sprite* m_entitySprite;
                    
                    // The texture rect for the sprite of the entity
                    sf::IntRect m_textureRect;
                    
                    // The width x height of each frame
                    sf::Vector2i m_frameSize;
                    
                    // The current frame number of the animation
                    int m_currentFrame;
                    
                    // The maximum frame number of the animation
                    int m_maxFrame;
                    
                    // The duration (in seconds) of each frame of the animation
                    sf::Time m_frameDuration;
                    
                    // Time elapsed since the last frame change occurred
                    sf::Time m_elapsedTime;
                    
                    // Loop the animation?
                    bool m_loop;
            };
        }
    }
}

#endif // ANIMATION_HPP
