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
#include "TileMap/TileMap.hpp"

namespace rts
{
    namespace WorldEntities
    {
        Tile::Tile() :
        m_tileQuad{ sf::Quads, 4 }
        {
            m_tileQuad[0].texCoords = sf::Vector2f{ 64.f, 0.f };
            m_tileQuad[1].texCoords = sf::Vector2f{ 128.f, 32.f };
            m_tileQuad[2].texCoords = sf::Vector2f{ 64.f, 64.f };
            m_tileQuad[3].texCoords = sf::Vector2f{ 0.f, 32.f };
            
            setPosition( sf::Vector2f{ 0.f, 0.f} );
            
            m_tileTexPtr = ResourceManager::getTexture( TextureID::TERRAIN_TILE_LAND_DEFAULT ).get();
            if ( !m_tileTexPtr )
                LOG(Logger::Level::ERROR) << "Unable to load tile texture: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_DEFAULT ) << std::endl;
        }

        void Tile::setPosition( const sf::Vector2f position )
        {
            m_tileQuad[0].position = position;
            m_tileQuad[1].position = sf::Vector2f{ m_tileQuad[0].position.x + 64.f, m_tileQuad[0].position.y + 32.f };
            m_tileQuad[2].position = sf::Vector2f{ m_tileQuad[0].position.x, m_tileQuad[0].position.y + 64.f };
            m_tileQuad[3].position = sf::Vector2f{ m_tileQuad[0].position.x - 64.f, m_tileQuad[0].position.y + 32.f };
        }

        const sf::Vector2f Tile::getPosition( int vertex )
        {
            if ( vertex < 0 || vertex > 3 )
            {
                LOG(Logger::Level::ERROR) << "Unable to load tile texture: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_DEFAULT ) << std::endl;
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
            sf::Vector2f center{ m_tileQuad[3].position.x + 128 * 0.5f, m_tileQuad[0].position.y + 64 * 0.5f };
            float dx = std::abs( mouse.x - center.x );
            float dy = std::abs( mouse.y - center.y );
            
            return dx / ( 128 * 0.5f ) + dy / ( 64 * 0.5f ) < 1;
        }

//         bool Tile::inView( const sf::RenderWindow& window )
//         {
//             //sf::View v = window.getView();
//             //return m_tileQuad[3].position.x >= 0 && m_tileQuad[0].position.y >= 0 && m_tileQuad[1].position.x <= 1365 && m_tileQuad[2].position.y <= 767;
//             return true;
//         }

        void Tile::setTexture( const TextureID texID )
        {
            m_tileTexPtr = ResourceManager::getTexture( texID ).get();
            if ( !m_tileTexPtr )
                LOG(Logger::Level::ERROR) << "Unable to load tile texture: " << textureIDToStr( texID ) << std::endl;
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
         m_selectedTile( TextureID::TERRAIN_TILE_WATER_DEFAULT ),
         m_window( &window )
        {
            LOG(Logger::Level::INFO) << "Creating TileMap..." << std::endl;
            
            // Create a sizexsize 2D grid of tiles
            m_tiles.resize( m_size, std::vector<Tile>( m_size, Tile() ) );
            
            // Position of tile (0,0)
            const sf::Vector2f gridPos{ window.getSize().x / 2.f, 0.f };
            
            for ( int y = 0; y < m_size; ++y )
            {
                for ( int x = 0; x < m_size; ++x )
                {
                    float cX = TERRAIN_TILE_WIDTH * 0.5f * x;
                    float cY = TERRAIN_TILE_HEIGHT * y;
                    
                    sf::Vector2f iso{ cX - cY + gridPos.x,
                                      ( cX + cY ) / 2.f + gridPos.y };
                    
                    m_tiles[y][x].setPosition( iso );
                }
            }
            
            m_mapView.setSize( sf::Vector2f{ WINDOW_WIDTH, WINDOW_HEIGHT } );
            m_mapView.setCenter( sf::Vector2f{ WINDOW_WIDTH / 2.f, m_size * TERRAIN_TILE_HEIGHT * 0.5f } );
            window.setView( m_mapView );
            
            LOG(Logger::Level::INFO) << "TileMap successfully created" << std::endl;
        }
                
        void TileMap::handleInput()
        {
            
        }
        
        void TileMap::update( const sf::Time dt )
        {
            if ( m_window->isOpen() )
            {
                auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*m_window));
                //auto mousePos = m_window->mapPixelToCoords( static_cast<sf::Vector2i>( sf::Mouse::getPosition(*m_window) ) );
                float scroll = 250.f;
            
                // Highlight mouseover tile
                for ( auto&& tileRow : m_tiles )
                {
                    for ( auto&& tile : tileRow )
                    {
                        if ( tile.contains( m_window->mapPixelToCoords( static_cast<sf::Vector2i>( mousePos ) ) ) )
                        //if ( tile.contains( mousePos ) )
                            tile.setFillColor( sf::Color( 200, 200, 200, 200 ) );
                        else
                            tile.setFillColor( sf::Color( 255, 255, 255, 255 ) );
                        
                        if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) && tile.contains( m_window->mapPixelToCoords( static_cast<sf::Vector2i>( mousePos ) ) ) )
                        //if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) && tile.contains( mousePos ) )
                        {
                            // Change tile to the current selected tile
                            tile.setTexture( m_selectedTile );
                        }
                    }
                }
                
                // View scrolling
                
                if ( mousePos.x <= 0 )
                {
                    if ( m_mapView.getCenter().x - m_mapView.getSize().x * 0.5f > m_tiles[m_size - 1][0].getPosition(3).x )
                    {
                        m_mapView.move( sf::Vector2f{ -scroll * dt.asSeconds(), 0 } );
                        m_window->setView( m_mapView );
                    }
                }
                else if ( mousePos.x >= WINDOW_WIDTH - 1 )
                {
                    if ( m_mapView.getCenter().x + m_mapView.getSize().x * 0.5f < m_tiles[0][m_size - 1].getPosition(1).x )
                    {
                        m_mapView.move( sf::Vector2f{ scroll * dt.asSeconds(), 0 } );
                        m_window->setView( m_mapView );
                    }
                }
                if ( mousePos.y <= 0 )
                {
                    if ( m_mapView.getCenter().y - m_mapView.getSize().y * 0.5f > m_tiles[0][0].getPosition(0).y )
                    {
                        m_mapView.move( sf::Vector2f{ 0, -scroll * dt.asSeconds() } );
                        m_window->setView( m_mapView );
                    }
                }
                else if ( mousePos.y >= WINDOW_HEIGHT - 1 )
                {
                    if ( m_mapView.getCenter().y + m_mapView.getSize().y * 0.5f < m_tiles[m_size - 1][m_size - 1].getPosition(2).y )
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
        }
        
        void TileMap::setSelectedTile( const TextureID texID )
        {
            m_selectedTile = texID;
        }
        
        void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            
            // TODO: After testing, make the rendering follow depth order
            for ( auto&& tileRow : m_tiles )
                for ( auto&& tile : tileRow )
                    target.draw( tile, states);
        }
    }
}
