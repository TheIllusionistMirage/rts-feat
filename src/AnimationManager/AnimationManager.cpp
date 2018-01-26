#include "Utility/System.hpp"
#include "Utility/Log.hpp"
#include "AnimationManager/AnimationManager.hpp"

namespace rts
{
    namespace AnimationManager
    {
        std::map<std::string, WorldEntities::EntityComponents::AnimationComponent::Ptr> AnimationManager::m_animations = {};
        
        bool AnimationManager::exists( const std::string& id )
        {
            if ( isStrWS( id ) )
            {
                LOG(Logger::Level::ERROR) << "Invalid ID used access an AnimationComponent instance." << std::endl;
                return false;
            }
            
            return m_animations.find( id ) != m_animations.end();
        }
        
        bool AnimationManager::createAnimation( const std::string& id        ,
                                                sf::Sprite* entitySprite     ,
                                                const sf::Vector2i frameSize ,
                                                const unsigned maxFrame      ,
                                                const sf::Time frameDuration )
        {
            if ( isStrWS( id ) )
            {
                LOG(Logger::Level::ERROR) << "Invalid ID used to create a new AnimationComponent instance." << std::endl;
                return false;
            }
            
            auto it = m_animations.find( id );
            if ( it != m_animations.end() )
            {
                LOG(Logger::Level::ERROR) << "An AnimationComponent with ID(" + id + ") already exists." << std::endl;
                return false;
            }
            
            m_animations[id] = std::make_shared<WorldEntities::EntityComponents::AnimationComponent>( entitySprite, frameSize, maxFrame, frameDuration );
            LOG(Logger::Level::DEBUG) << "An AnimationComponent with ID(" + id + ") created." << std::endl;
            
            return true;
        }
        
        bool AnimationManager::createAnimation( const std::string& id        ,
                                                sf::VertexArray* vertexArray ,
                                                const sf::Vector2i frameSize ,
                                                const unsigned maxFrame      ,
                                                const sf::Time frameDuration )
        {
            if ( isStrWS( id ) )
            {
                LOG(Logger::Level::ERROR) << "Invalid ID used to create a new AnimationComponent instance." << std::endl;
                return false;
            }
            
            auto it = m_animations.find( id );
            if ( it != m_animations.end() )
            {
                LOG(Logger::Level::ERROR) << "An AnimationComponent with ID(" + id + ") already exists." << std::endl;
                return false;
            }
            
            m_animations[id] = std::make_shared<WorldEntities::EntityComponents::AnimationComponent>( vertexArray, frameSize, maxFrame, frameDuration );
            LOG(Logger::Level::DEBUG) << "An AnimationComponent with ID(" + id + ") created." << std::endl;
            return true;
        }
        
        void AnimationManager::destroyAnimation( const std::string& id )
        {
            if ( isStrWS( id ) )
            {
                LOG(Logger::Level::ERROR) << "Invalid ID used to access an AnimationComponent instance." << std::endl;
                return;
            }
            
            auto it = m_animations.find( id );
            if ( it == m_animations.end() )
            {
                LOG(Logger::Level::ERROR) << "An AnimationComponent with ID(" + id + ") does not exist." << std::endl;
                return;
            }
            
            m_animations.erase( it );
            
            LOG(Logger::Level::DEBUG) << "Destroyed AnimationComponent with ID: " + id + "." << std::endl;
        }
        
        void AnimationManager::syncAnimations( const std::vector<std::string>& IDs )
        {
            for ( auto&& id : IDs )
            {
                if ( exists( id ) )
                {
                    
                }
                else
                    LOG(Logger::Level::ERROR) << "An AnimationComponent with ID(" + id + ") does not exist." << std::endl;
            }
        }
        
        void AnimationManager::setVisibility( const std::string& id, bool visibility )
        {
            if ( isStrWS( id ) )
            {
                LOG(Logger::Level::ERROR) << "Invalid ID used to access an AnimationComponent instance." << std::endl;
                return;
            }
            
            auto it = m_animations.find( id );
            if ( it == m_animations.end() )
            {
                LOG(Logger::Level::ERROR) << "An AnimationComponent with ID(" + id + ") does not exist." << std::endl;
                return;
            }
            
            //std::cout << "ZZZZZZZZZZZZZ" << std::endl;
            it->second->m_visible = visibility;
        }
        
        void AnimationManager::update( const sf::Event& event,
                     const sf::Vector2i mousePos,
                     const sf::Time dt )
        {
            for ( auto&& anim : m_animations )
            {
                if ( anim.second->m_type == WorldEntities::EntityComponents::AnimationComponent::SpriteType::NONE )
                    continue;
                
                if ( !anim.second->m_visible )
                    continue;
            
                // The duration fo one frame of the animation
                sf::Time frameTime = anim.second->m_duration / float(anim.second->m_maxFrame);
                
                // Time elapsed since last frame change
                anim.second->m_elapsedTime += dt;
                
                // If the elpased time since last frame change is greater than
                // or equal to the time per animation frame, we update the frame
                if ( anim.second->m_elapsedTime >= frameTime )
                {
                    // Update the current frame to the next frame
                    anim.second->m_currentFrame = ( anim.second->m_currentFrame + 1 ) % ( anim.second->m_maxFrame + 1 );
                    
                    // Update the texture rects for the sprite, according to its type, i.e., sf::Sprite or sf::VertexArray                    
                    if ( anim.second->m_type == WorldEntities::EntityComponents::AnimationComponent::SpriteType::SF_SPRITE )
                    {
                        anim.second->m_textureRect = sf::IntRect{ anim.second->m_frameSize.x * anim.second->m_currentFrame,
                                                                  0,
                                                                  anim.second->m_frameSize.x,
                                                                  anim.second->m_frameSize.y };
                                                              
                        anim.second->m_entitySprite.m_spritePtr->setTextureRect( anim.second->m_textureRect );
                    }
                    else
                    {
                        if ( anim.second->m_currentFrame == 0 )
                        {   
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[0].texCoords.x = anim.second->m_frameSize.x / 2;
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[1].texCoords.x = anim.second->m_frameSize.x;
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[2].texCoords.x = anim.second->m_frameSize.x / 2;
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[3].texCoords.x = 0;
                        }
                        else
                        {
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[0].texCoords.x += anim.second->m_frameSize.x;
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[1].texCoords.x += anim.second->m_frameSize.x;
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[2].texCoords.x += anim.second->m_frameSize.x;
                            (*anim.second->m_entitySprite.m_vertexArrayPtr)[3].texCoords.x += anim.second->m_frameSize.x;
                        }
                    }
                    
                    anim.second->m_elapsedTime -= frameTime;
                }
            }
        }
    }
}
