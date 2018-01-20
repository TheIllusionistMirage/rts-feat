/*
 * ------------------
 *  Module : TileMap
 * ------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 15-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods & classes declared
 *  in TileMap module.
 */

#include <climits>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/View.hpp>

#include "Utility/Constants.hpp"
#include "Utility/Log.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "AnimationManager/AnimationManager.hpp"
#include "TileMap/TileMap.hpp"

namespace rts
{
    namespace WorldEntities
    {
        Tile::Tile() :
        m_tileQuad{ sf::Quads, 4 }
        {
            m_tileQuad[0].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, 0.f };
            m_tileQuad[1].texCoords = sf::Vector2f{ TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT * 0.5 };
            m_tileQuad[2].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, TERRAIN_TILE_HEIGHT };
            m_tileQuad[3].texCoords = sf::Vector2f{ 0.f, TERRAIN_TILE_HEIGHT * 0.5 };
            
            setPosition( sf::Vector2f{ 0.f, 0.f} );
            
            TextureID texture = TextureID::TERRAIN_TILE_DESERT_01;
            
            m_tileTexPtr = ResourceManager::getTexture( texture ).get();
            if ( !m_tileTexPtr )
                LOG(Logger::Level::ERROR) << "Unable to load tile texture: " << textureIDToStr( texture ) << std::endl;
            
            // Attach an animation to the tile
            if ( isAnimatedTexture( texture ) )
            {
                AnimationManager::AnimationManager::createAnimation( "tile-anim-" + std::to_string( long(getQuad()) ), &m_tileQuad, sf::Vector2i{ 128, 64 }, 2, sf::seconds(1.5f) );
                setAnimated(true);
            }
            else
                setAnimated(false);
            
            // By default each tile created is assumed to be in the camera view
            m_inView = false;
        }
        
        Tile::~Tile()
        {
            if ( tileAnimated() )
                AnimationManager::AnimationManager::destroyAnimation( "tile-anim-" + std::to_string( long(getQuad()) ) );
        }

        void Tile::setPosition( const sf::Vector2f position )
        {
            m_tileQuad[0].position = position;
            m_tileQuad[1].position = sf::Vector2f{ m_tileQuad[0].position.x + TERRAIN_TILE_HEIGHT, m_tileQuad[0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
            m_tileQuad[2].position = sf::Vector2f{ m_tileQuad[0].position.x, m_tileQuad[0].position.y + TERRAIN_TILE_HEIGHT };
            m_tileQuad[3].position = sf::Vector2f{ m_tileQuad[0].position.x - TERRAIN_TILE_HEIGHT, m_tileQuad[0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
        }

        const sf::Vector2f Tile::getPosition( int vertex )
        {
            if ( vertex < 0 || vertex > 3 )
            {
                LOG(Logger::Level::ERROR) << "Vertex must be an integer between 0 and 4." << std::endl;
                return sf::Vector2f{ UINT16_MAX, UINT16_MAX }; // Indicates invalid tile
            }
            return m_tileQuad[vertex].position;
        }

        void Tile::setFillColor( const sf::Color fillColor )
        {
            m_tileQuad[0].color = fillColor;
            m_tileQuad[1].color = fillColor;
            m_tileQuad[2].color = fillColor;
            m_tileQuad[3].color = fillColor;
        }

        // https://stackoverflow.com/questions/27100729/find-which-tile-was-clicked-in-a-isometric-staggered-column-system
        bool Tile::contains( const sf::Vector2f mouse )
        {
            sf::Vector2f center{ m_tileQuad[3].position.x + TERRAIN_TILE_WIDTH * 0.5f, m_tileQuad[0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
            float dx = std::abs( mouse.x - center.x );
            float dy = std::abs( mouse.y - center.y );
            
            return dx / ( TERRAIN_TILE_WIDTH * 0.5f ) + dy / ( TERRAIN_TILE_HEIGHT * 0.5f ) < 1;
        }

        void Tile::setTexture( const TextureID texID )
        {
            m_tileTexPtr = ResourceManager::getTexture( texID ).get();
            if ( !m_tileTexPtr )
                LOG(Logger::Level::ERROR) << "Unable to load tile texture: " << textureIDToStr( texID ) << std::endl;
        }
        
        bool Tile::inWorldView( const sf::View worldView ) const
        {
            //return m_inView;
            float viewLeft  = worldView.getCenter().x - worldView.getSize().x * 0.5f - TERRAIN_TILE_WIDTH;
            float viewTop   = worldView.getCenter().y - worldView.getSize().y * 0.5f - TERRAIN_TILE_HEIGHT;
            float viewRight = worldView.getCenter().x + worldView.getSize().x * 0.5f + TERRAIN_TILE_WIDTH;
            float viewDown  = worldView.getCenter().y + worldView.getSize().y * 0.5f + TERRAIN_TILE_HEIGHT;
            
            return m_tileQuad[0].position.y >= viewTop && m_tileQuad[0].position.y <= viewDown &&
                    m_tileQuad[2].position.y >= viewTop && m_tileQuad[2].position.y <= viewDown &&
                     m_tileQuad[1].position.x >= viewLeft && m_tileQuad[1].position.x <= viewRight &&
                      m_tileQuad[3].position.x >= viewLeft && m_tileQuad[3].position.x <= viewRight;
        }
        
        void Tile::setAnimated( bool animated )
        {
            m_animated = animated;
            
            m_tileQuad[0].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, 0.f };
            m_tileQuad[1].texCoords = sf::Vector2f{ TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT * 0.5f };
            m_tileQuad[2].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, TERRAIN_TILE_HEIGHT };
            m_tileQuad[3].texCoords = sf::Vector2f{ 0.f, TERRAIN_TILE_HEIGHT * 0.5f };
        }
        
        bool Tile::tileAnimated() const
        {
            return m_animated;
        }
        
        sf::VertexArray* Tile::getQuad()
        {
            return &m_tileQuad;
        }

        void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = m_tileTexPtr;
            target.draw( m_tileQuad, states);
        }
        
        ///////////////////////////////////////////////////////////////////////////////////////////
        
        TileMap::TileMap( const int size, sf::RenderWindow& window ) :
         m_size( size ),
         m_selectedTile( TextureID::TERRAIN_TILE_DESERT_01 ),
         m_window( &window )
        {
            LOG(Logger::Level::INFO) << "Creating TileMap..." << std::endl;
            
            // Create a sizexsize 2D grid of tiles
            //m_tiles.resize( m_size, std::vector<Tile>( m_size, Tile() ) );
            for ( int y = 0; y < m_size; ++y )
            {
                m_tiles.push_back( std::vector<Tile::Ptr>() );
                for ( int x = 0; x < m_size; ++x )
                    m_tiles[y].push_back( std::make_shared<Tile>() );
            }
            
            // Position of tile (0,0)
            const sf::Vector2f gridPos{ window.getSize().x / 2.f, 0.f };
            
            for ( int y = 0; y < m_size; ++y )
            {
                for ( int x = 0; x < m_size; ++x )
                {
                    float cX = (TERRAIN_TILE_HEIGHT - 2) * x;
                    float cY = (TERRAIN_TILE_HEIGHT - 2) * y;
                    
                    sf::Vector2f iso{ cX - cY + gridPos.x,
                                      ( cX + cY ) / 2.f + gridPos.y };
                                      
                    m_tiles[y][x]->setPosition( iso );
                }
            }
            
            m_mapView.setSize( sf::Vector2f{ WINDOW_WIDTH, WINDOW_HEIGHT } );
            m_mapView.setCenter( sf::Vector2f{ WINDOW_WIDTH / 2.f, m_size * TERRAIN_TILE_HEIGHT * 0.5f } );
            window.setView( m_mapView );
            
            LOG(Logger::Level::INFO) << "TileMap successfully created" << std::endl;
        }
        
        TileMap::~TileMap()
        {
            for ( int y = 0; y < m_size; ++y )
            {
                for ( int x = 0; x < m_size; ++x )
                {
                    m_tiles[y][x].reset();
                }
            }
            LOG(Logger::Level::INFO) << "TileMap destroyed." << std::endl;
        }
        
//         bool TileMap::generate( const int size, sf::RenderWindow& window )
//         {
//             m_size = size;
//             m_selectedTile = TextureID::TERRAIN_TILE_LAND_DEFAULT;
//             m_window = &window;
//          
//             LOG(Logger::Level::INFO) << "Creating TileMap..." << std::endl;
//             
//             // Create a sizexsize 2D grid of tiles
//             m_tiles.resize( m_size, std::vector<Tile>( m_size, Tile() ) );
//             
//             // Position of tile (0,0)
//             const sf::Vector2f gridPos{ window.getSize().x / 2.f, 0.f };
//             
//             for ( int y = 0; y < m_size; ++y )
//             {
//                 for ( int x = 0; x < m_size; ++x )
//                 {
//                     float cX = 63.f * x;
//                     float cY = 63.f * y;
//                     
//                     sf::Vector2f iso{ cX - cY + gridPos.x,
//                                       ( cX + cY ) / 2.f + gridPos.y };
//                     
//                     m_tiles[y][x].setPosition( iso );
//                 }
//             }
//             
//             m_mapView.setSize( sf::Vector2f{ WINDOW_WIDTH, WINDOW_HEIGHT } );
//             m_mapView.setCenter( sf::Vector2f{ WINDOW_WIDTH / 2.f, m_size * TERRAIN_TILE_HEIGHT * 0.5f } );
//             window.setView( m_mapView );
//             
//             LOG(Logger::Level::INFO) << "TileMap successfully created" << std::endl;
//             
//             return true;
//         }
                
        void TileMap::handleInput()
        {
            
        }
        
        void TileMap::update( const sf::Time dt )
        {
            if ( m_window->isOpen() && !CManager::UIComponent::m_mouseOverUIWidget )
            {
                auto screenMousePos = sf::Mouse::getPosition(*m_window);
                auto mousePos = static_cast<sf::Vector2f>( m_window->mapPixelToCoords( sf::Mouse::getPosition(*m_window) ) );

                float scroll = 350.f;
                bool mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
                
                for ( auto&& tileRow : m_tiles )
                {
                    for ( auto&& tile : tileRow )
                    {
                        // Highlight mouseover tile
                        if ( tile->contains( mousePos ) )
                                tile->setFillColor( sf::Color( 200, 200, 200, 200 ) );
                            else
                                tile->setFillColor( sf::Color( 255, 255, 255, 255 ) );
                        
                        // Update tile texture
                        if ( mouseDown && tile->contains( mousePos ) )
                        {
                            if ( tile->tileAnimated() )
                            {
                                AnimationManager::AnimationManager::destroyAnimation( "tile-anim-" + std::to_string( long(tile->getQuad()) ) );
                                tile->setAnimated(false);
                            }
                            
                            // Change tile to the current selected tile
                            if ( isAnimatedTexture( m_selectedTile ) )
                            {
                                AnimationManager::AnimationManager::createAnimation( "tile-anim-" + std::to_string( long(tile->getQuad()) ), tile->getQuad(), sf::Vector2i{ 128, 64 }, 2, sf::seconds(1.f) );
                                tile->setAnimated(true);
                            }
                            
                            tile->setTexture( m_selectedTile );
                        }
                    }
                }
                
                // View scrolling
                
                if ( screenMousePos.x <= 0 )
                {
                    if ( m_mapView.getCenter().x - m_mapView.getSize().x * 0.5f > m_tiles[m_size - 1][0]->getPosition(3).x )
                    {
                        m_mapView.move( sf::Vector2f{ -scroll * dt.asSeconds(), 0 } );
                        m_window->setView( m_mapView );
                    }
                }
                else if ( screenMousePos.x >= WINDOW_WIDTH - 1 )
                {
                    if ( m_mapView.getCenter().x + m_mapView.getSize().x * 0.5f < m_tiles[0][m_size - 1]->getPosition(1).x )
                    {
                        m_mapView.move( sf::Vector2f{ scroll * dt.asSeconds(), 0 } );
                        m_window->setView( m_mapView );
                    }
                }
                if ( screenMousePos.y <= 0 )
                {
                    if ( m_mapView.getCenter().y - m_mapView.getSize().y * 0.5f > m_tiles[0][0]->getPosition(0).y )
                    {
                        m_mapView.move( sf::Vector2f{ 0, -scroll * dt.asSeconds() } );
                        m_window->setView( m_mapView );
                    }
                }
                else if ( screenMousePos.y >= WINDOW_HEIGHT - 1 )
                {
                    if ( m_mapView.getCenter().y + m_mapView.getSize().y * 0.5f < m_tiles[m_size - 1][m_size - 1]->getPosition(2).y )
                    {
                        m_mapView.move( sf::Vector2f{ 0, scroll * dt.asSeconds() } );
                        m_window->setView( m_mapView );
                    }
                }
                
//                 
//                 // Panning
//                 if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) && event.type == sf::Event::MouseMoved )
//                 {
//                     /*auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
//                     m_mapView.setCenter( { std::abs( mousePos.x + 0 ), std::abs( mousePos.y + 0 ) } );
//                     window.setView(m_mapView);*/
//                 }
            }            
            //m_tiles[0][1].inWorldView( m_mapView );
        }
        
        void TileMap::setSelectedTile( const TextureID texID )
        {
            m_selectedTile = texID;
        }
        
        void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            
            // TODO: After testing, make the rendering follow depth order
//             for ( auto&& tileRow : m_tiles )
//                 for ( auto&& tile : tileRow )
//                     target.draw( tile, states);
            for ( int y = 0; y < m_size ; ++y )
            {
                for ( int x = 0; x < m_size ; ++x )
                {
                    if ( m_tiles[y][x]->inWorldView( m_mapView ) )
                        target.draw( *m_tiles[y][x], states);
                }
            }
        }
    }
}
