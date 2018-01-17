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
                LOG(Logger::Level::ERROR) << "Invalid ID used to created a new AnimationComponent instance." << std::endl;
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
                LOG(Logger::Level::ERROR) << "Invalid ID used to created a new AnimationComponent instance." << std::endl;
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
                LOG(Logger::Level::ERROR) << "Invalid ID used to created a new AnimationComponent instance." << std::endl;
                return;
            }
            
            auto it = m_animations.find( id );
            if ( it == m_animations.end() )
            {
                LOG(Logger::Level::ERROR) << "An AnimationComponent with ID(" + id + ") does not exist." << std::endl;
                return;
            }
            
            m_animations.erase( it );
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
        
        void AnimationManager::update( const sf::Event& event,
                     const sf::Vector2i mousePos,
                     const sf::Time dt )
        {
            for ( auto&& anim : m_animations )
            {
                // The duration fo one frame of the animation
                sf::Time frameTime = anim.second->m_duration / float(anim.second->m_maxFrame);
                
                // Time elapsed since last frame change
                anim.second->m_elapsedTime += dt;
                
                // If the elpased time since last frame change is greater than
                // or equal to the time per animation frame, we update the frame
                while ( anim.second->m_elapsedTime >= frameTime )
                {
                    anim.second->m_currentFrame = ( anim.second->m_currentFrame + 1 ) % ( anim.second->m_maxFrame + 1 );
                    anim.second->m_textureRect = sf::IntRect{ anim.second->m_frameSize.x * anim.second->m_currentFrame,
                                                              0,
                                                              anim.second->m_frameSize.x,
                                                              anim.second->m_frameSize.y };
                    anim.second->m_entitySprite.m_spritePtr->setTextureRect( anim.second->m_textureRect );
                    
//                     m_tileQuad[0].texCoords = sf::Vector2f{ 64.f, 0.f };
//                     m_tileQuad[1].texCoords = sf::Vector2f{ 128.f, 32.f };
//                     m_tileQuad[2].texCoords = sf::Vector2f{ 64.f, 64.f };
//                     m_tileQuad[3].texCoords = sf::Vector2f{ 0.f, 32.f };
            
//                     //if ( anim.second->m_entitySprite.m_vertexArrayPtr )
//                     {
//                         //(*anim.second->m_entitySprite.m_vertexArrayPtr)[0].texCoords = sf::Vector2f{ 128 + 64.f, 0.f };
//                         auto v = anim.second->m_entitySprite.m_vertexArrayPtr->getBounds().top;
//                         std::cout << v.getBounds().top << std::endl;
//                         //std::cout << << std::endl;
// //                         (*anim.second->m_entitySprite.m_vertexArrayPtr)[0].texCoords = sf::Vector2f{ 128 + 64.f, 0.f };
// //                         (*anim.second->m_entitySprite.m_vertexArrayPtr)[1].texCoords = sf::Vector2f{ 128 + 128.f, 32.f };
// //                         (*anim.second->m_entitySprite.m_vertexArrayPtr)[2].texCoords = sf::Vector2f{ 128 + 64.f, 64.f };
// //                         (*anim.second->m_entitySprite.m_vertexArrayPtr)[3].texCoords = sf::Vector2f{ 128 + 0.f, 32.f };
//                     }
                    
                    anim.second->m_elapsedTime -= frameTime;
                }
            }
        }
    }
}
