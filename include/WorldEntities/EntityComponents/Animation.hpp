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
 *  This module contains the animation component for any game entity
 *  that wishes to use animation.
 * 
 *  NOTE:
 *  The AnimationComponent is an abstraction for dealing with
 *  animation for in game entities. For some entities, the animation
 *  can be an intrinsic property, e.g. a water tile in the terrain map.
 *  In this case the entity uses the AnimationComponent to animate
 *  itself.
 * 
 */

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Time.hpp>

namespace rts
{
    namespace WorldEntities
    {
        namespace EntityComponents
        {
            /*
             * The AnimationComponent needs access to the sprite of the
             * entity for animation, along with other required parameters
             * like frametime etc.
             */
            struct AnimationComponent
            {
                public:
                    
                    typedef std::shared_ptr<AnimationComponent> Ptr;
                    
                    AnimationComponent();
                    
                    // One using sf::Sprite as the renderable
                    AnimationComponent( sf::Sprite* entitySprite,
                                        const sf::Vector2i frameSize,
                                        const unsigned maxFrame,
                                        const sf::Time duration );
                    
                    // One using sf::VertexArray as the renderable
                    AnimationComponent( sf::VertexArray* vertexArray,
                                        const sf::Vector2i frameSize,
                                        const unsigned maxFrame,
                                        const sf::Time duration );
                    
                    // The sprite of the entity
                   
                    enum class SpriteType
                    {
                        NONE,
                        SF_SPRITE,
                        SF_VERTEX_ARRAY
                    };
                    
                    SpriteType m_type;
                    
                    union
                    {
                        sf::Sprite* m_spritePtr;
                        sf::VertexArray* m_vertexArrayPtr;
                    } m_entitySprite;
                    
                    // The texture rect for the sprite of the entity
                    sf::IntRect m_textureRect;
                    
                    // The width x height of each frame
                    sf::Vector2i m_frameSize;
                    
                    // The current frame number of the animation
                    int m_currentFrame;
                    
                    // The maximum frame number of the animation
                    int m_maxFrame;
                    
                    // The duration (in seconds) of each frame of the animation
                    sf::Time m_duration;
                    
                    // Time elapsed since the last frame change occurred
                    sf::Time m_elapsedTime;
                    
                    // Loop the animation?
                    bool m_loop;
                    
                    bool m_visible;
            };
        }
    }
}

#endif // ANIMATION_HPP
