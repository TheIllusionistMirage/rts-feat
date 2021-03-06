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
        std::map<TerrainType, int> Tile::m_precedences =
        {
            { TerrainType::WATER, 0 },
            { TerrainType::GRASS, 1 },
            { TerrainType::DESERT, 2 },
            { TerrainType::SNOW, 3 },
        };
        
        TextureID Tile::getOverlayTexture( const std::string& id )
        {
            static std::map<std::string, TextureID> m_overlayMap =
            {
//                 { "0-0000", TextureID::TERRAIN_TILE_GRASS_0_0000 },
//                 { "0-0001", TextureID::TERRAIN_TILE_GRASS_0_0001 },
//                 { "0-0010", TextureID::TERRAIN_TILE_GRASS_0_0010 },
//                 { "0-0011", TextureID::TERRAIN_TILE_GRASS_0_0011 },
//                 { "0-0100", TextureID::TERRAIN_TILE_GRASS_0_0100 },
//                 { "0-0101", TextureID::TERRAIN_TILE_GRASS_0_0101 },
//                 { "0-0110", TextureID::TERRAIN_TILE_GRASS_0_0110 },
//                 { "0-0111", TextureID::TERRAIN_TILE_GRASS_0_0111 },
//                 { "0-1000", TextureID::TERRAIN_TILE_GRASS_0_1000 },
//                 { "0-1001", TextureID::TERRAIN_TILE_GRASS_0_1001 },
//                 { "0-1010", TextureID::TERRAIN_TILE_GRASS_0_1010 },
//                 { "0-1011", TextureID::TERRAIN_TILE_GRASS_0_1011 },
//                 { "0-1100", TextureID::TERRAIN_TILE_GRASS_0_1100 },
//                 { "0-1101", TextureID::TERRAIN_TILE_GRASS_0_1101 },
//                 { "0-1110", TextureID::TERRAIN_TILE_GRASS_0_1110 },
//                 { "0-1111", TextureID::TERRAIN_TILE_GRASS_0_1111 },
//                 
//                 { "1-0000", TextureID::TERRAIN_TILE_GRASS_1_0000 },
//                 { "1-0001", TextureID::TERRAIN_TILE_GRASS_1_0001 },
//                 { "1-0010", TextureID::TERRAIN_TILE_GRASS_1_0010 },
//                 { "1-0011", TextureID::TERRAIN_TILE_GRASS_1_0011 },
//                 { "1-0100", TextureID::TERRAIN_TILE_GRASS_1_0100 },
//                 { "1-0101", TextureID::TERRAIN_TILE_GRASS_1_0101 },
//                 { "1-0110", TextureID::TERRAIN_TILE_GRASS_1_0110 },
//                 { "1-0111", TextureID::TERRAIN_TILE_GRASS_1_0111 },
//                 { "1-1000", TextureID::TERRAIN_TILE_GRASS_1_1000 },
//                 { "1-1001", TextureID::TERRAIN_TILE_GRASS_1_1001 },
//                 { "1-1010", TextureID::TERRAIN_TILE_GRASS_1_1010 },
//                 { "1-1011", TextureID::TERRAIN_TILE_GRASS_1_1011 },
//                 { "1-1100", TextureID::TERRAIN_TILE_GRASS_1_1100 },
//                 { "1-1101", TextureID::TERRAIN_TILE_GRASS_1_1101 },
//                 { "1-1110", TextureID::TERRAIN_TILE_GRASS_1_1110 },
//                 { "1-1111", TextureID::TERRAIN_TILE_GRASS_1_1111 }
                
                { "0-0-0000", TextureID::INVALID },
                { "0-0-0001", TextureID::INVALID },
                { "0-0-0010", TextureID::INVALID },
                { "0-0-0011", TextureID::INVALID },
                { "0-0-0100", TextureID::INVALID },
                { "0-0-0101", TextureID::INVALID },
                { "0-0-0110", TextureID::INVALID },
                { "0-0-0111", TextureID::INVALID },
                { "0-0-1000", TextureID::INVALID },
                { "0-0-1001", TextureID::INVALID },
                { "0-0-1010", TextureID::INVALID },
                { "0-0-1011", TextureID::INVALID },
                { "0-0-1100", TextureID::INVALID },
                { "0-0-1101", TextureID::INVALID },
                { "0-0-1110", TextureID::INVALID },
                { "0-0-1111", TextureID::INVALID },
                
                { "0-1-0000", TextureID::INVALID },
                { "0-1-0001", TextureID::INVALID },
                { "0-1-0010", TextureID::INVALID },
                { "0-1-0011", TextureID::INVALID },
                { "0-1-0100", TextureID::INVALID },
                { "0-1-0101", TextureID::INVALID },
                { "0-1-0110", TextureID::INVALID },
                { "0-1-0111", TextureID::INVALID },
                { "0-1-1000", TextureID::INVALID },
                { "0-1-1001", TextureID::INVALID },
                { "0-1-1010", TextureID::INVALID },
                { "0-1-1011", TextureID::INVALID },
                { "0-1-1100", TextureID::INVALID },
                { "0-1-1101", TextureID::INVALID },
                { "0-1-1110", TextureID::INVALID },
                { "0-1-1111", TextureID::INVALID },
                
//                 { "0-0-0000", TextureID::TERRAIN_TILE_GRASS_0_0000 },
//                 { "0-0-0001", TextureID::TERRAIN_TILE_GRASS_0_0001 },
//                 { "0-0-0010", TextureID::TERRAIN_TILE_GRASS_0_0010 },
//                 { "0-0-0011", TextureID::TERRAIN_TILE_GRASS_0_0011 },
//                 { "0-0-0100", TextureID::TERRAIN_TILE_GRASS_0_0100 },
//                 { "0-0-0101", TextureID::TERRAIN_TILE_GRASS_0_0101 },
//                 { "0-0-0110", TextureID::TERRAIN_TILE_GRASS_0_0110 },
//                 { "0-0-0111", TextureID::TERRAIN_TILE_GRASS_0_0111 },
//                 { "0-0-1000", TextureID::TERRAIN_TILE_GRASS_0_1000 },
//                 { "0-0-1001", TextureID::TERRAIN_TILE_GRASS_0_1001 },
//                 { "0-0-1010", TextureID::TERRAIN_TILE_GRASS_0_1010 },
//                 { "0-0-1011", TextureID::TERRAIN_TILE_GRASS_0_1011 },
//                 { "0-0-1100", TextureID::TERRAIN_TILE_GRASS_0_1100 },
//                 { "0-0-1101", TextureID::TERRAIN_TILE_GRASS_0_1101 },
//                 { "0-0-1110", TextureID::TERRAIN_TILE_GRASS_0_1110 },
//                 { "0-0-1111", TextureID::TERRAIN_TILE_GRASS_0_1111 },
//                 
//                 { "0-1-0000", TextureID::TERRAIN_TILE_GRASS_1_0000 },
//                 { "0-1-0001", TextureID::TERRAIN_TILE_GRASS_1_0001 },
//                 { "0-1-0010", TextureID::TERRAIN_TILE_GRASS_1_0010 },
//                 { "0-1-0011", TextureID::TERRAIN_TILE_GRASS_1_0011 },
//                 { "0-1-0100", TextureID::TERRAIN_TILE_GRASS_1_0100 },
//                 { "0-1-0101", TextureID::TERRAIN_TILE_GRASS_1_0101 },
//                 { "0-1-0110", TextureID::TERRAIN_TILE_GRASS_1_0110 },
//                 { "0-1-0111", TextureID::TERRAIN_TILE_GRASS_1_0111 },
//                 { "0-1-1000", TextureID::TERRAIN_TILE_GRASS_1_1000 },
//                 { "0-1-1001", TextureID::TERRAIN_TILE_GRASS_1_1001 },
//                 { "0-1-1010", TextureID::TERRAIN_TILE_GRASS_1_1010 },
//                 { "0-1-1011", TextureID::TERRAIN_TILE_GRASS_1_1011 },
//                 { "0-1-1100", TextureID::TERRAIN_TILE_GRASS_1_1100 },
//                 { "0-1-1101", TextureID::TERRAIN_TILE_GRASS_1_1101 },
//                 { "0-1-1110", TextureID::TERRAIN_TILE_GRASS_1_1110 },
//                 { "0-1-1111", TextureID::TERRAIN_TILE_GRASS_1_1111 },
                
                { "1-0-0000", TextureID::TERRAIN_TILE_GRASS_0_0000 },
                { "1-0-0001", TextureID::TERRAIN_TILE_GRASS_0_0001 },
                { "1-0-0010", TextureID::TERRAIN_TILE_GRASS_0_0010 },
                { "1-0-0011", TextureID::TERRAIN_TILE_GRASS_0_0011 },
                { "1-0-0100", TextureID::TERRAIN_TILE_GRASS_0_0100 },
                { "1-0-0101", TextureID::TERRAIN_TILE_GRASS_0_0101 },
                { "1-0-0110", TextureID::TERRAIN_TILE_GRASS_0_0110 },
                { "1-0-0111", TextureID::TERRAIN_TILE_GRASS_0_0111 },
                { "1-0-1000", TextureID::TERRAIN_TILE_GRASS_0_1000 },
                { "1-0-1001", TextureID::TERRAIN_TILE_GRASS_0_1001 },
                { "1-0-1010", TextureID::TERRAIN_TILE_GRASS_0_1010 },
                { "1-0-1011", TextureID::TERRAIN_TILE_GRASS_0_1011 },
                { "1-0-1100", TextureID::TERRAIN_TILE_GRASS_0_1100 },
                { "1-0-1101", TextureID::TERRAIN_TILE_GRASS_0_1101 },
                { "1-0-1110", TextureID::TERRAIN_TILE_GRASS_0_1110 },
                { "1-0-1111", TextureID::TERRAIN_TILE_GRASS_0_1111 },
                
                { "1-1-0000", TextureID::TERRAIN_TILE_GRASS_1_0000 },
                { "1-1-0001", TextureID::TERRAIN_TILE_GRASS_1_0001 },
                { "1-1-0010", TextureID::TERRAIN_TILE_GRASS_1_0010 },
                { "1-1-0011", TextureID::TERRAIN_TILE_GRASS_1_0011 },
                { "1-1-0100", TextureID::TERRAIN_TILE_GRASS_1_0100 },
                { "1-1-0101", TextureID::TERRAIN_TILE_GRASS_1_0101 },
                { "1-1-0110", TextureID::TERRAIN_TILE_GRASS_1_0110 },
                { "1-1-0111", TextureID::TERRAIN_TILE_GRASS_1_0111 },
                { "1-1-1000", TextureID::TERRAIN_TILE_GRASS_1_1000 },
                { "1-1-1001", TextureID::TERRAIN_TILE_GRASS_1_1001 },
                { "1-1-1010", TextureID::TERRAIN_TILE_GRASS_1_1010 },
                { "1-1-1011", TextureID::TERRAIN_TILE_GRASS_1_1011 },
                { "1-1-1100", TextureID::TERRAIN_TILE_GRASS_1_1100 },
                { "1-1-1101", TextureID::TERRAIN_TILE_GRASS_1_1101 },
                { "1-1-1110", TextureID::TERRAIN_TILE_GRASS_1_1110 },
                { "1-1-1111", TextureID::TERRAIN_TILE_GRASS_1_1111 },//,
                
                { "2-0-0000", TextureID::TERRAIN_TILE_DESERT_0_0000 },
                { "2-0-0001", TextureID::TERRAIN_TILE_DESERT_0_0001 },
                { "2-0-0010", TextureID::TERRAIN_TILE_DESERT_0_0010 },
                { "2-0-0011", TextureID::TERRAIN_TILE_DESERT_0_0011 },
                { "2-0-0100", TextureID::TERRAIN_TILE_DESERT_0_0100 },
                { "2-0-0101", TextureID::TERRAIN_TILE_DESERT_0_0101 },
                { "2-0-0110", TextureID::TERRAIN_TILE_DESERT_0_0110 },
                { "2-0-0111", TextureID::TERRAIN_TILE_DESERT_0_0111 },
                { "2-0-1000", TextureID::TERRAIN_TILE_DESERT_0_1000 },
                { "2-0-1001", TextureID::TERRAIN_TILE_DESERT_0_1001 },
                { "2-0-1010", TextureID::TERRAIN_TILE_DESERT_0_1010 },
                { "2-0-1011", TextureID::TERRAIN_TILE_DESERT_0_1011 },
                { "2-0-1100", TextureID::TERRAIN_TILE_DESERT_0_1100 },
                { "2-0-1101", TextureID::TERRAIN_TILE_DESERT_0_1101 },
                { "2-0-1110", TextureID::TERRAIN_TILE_DESERT_0_1110 },
                { "2-0-1111", TextureID::TERRAIN_TILE_DESERT_0_1111 },
                
                { "2-1-0000", TextureID::TERRAIN_TILE_DESERT_1_0000 },
                { "2-1-0001", TextureID::TERRAIN_TILE_DESERT_1_0001 },
                { "2-1-0010", TextureID::TERRAIN_TILE_DESERT_1_0010 },
                { "2-1-0011", TextureID::TERRAIN_TILE_DESERT_1_0011 },
                { "2-1-0100", TextureID::TERRAIN_TILE_DESERT_1_0100 },
                { "2-1-0101", TextureID::TERRAIN_TILE_DESERT_1_0101 },
                { "2-1-0110", TextureID::TERRAIN_TILE_DESERT_1_0110 },
                { "2-1-0111", TextureID::TERRAIN_TILE_DESERT_1_0111 },
                { "2-1-1000", TextureID::TERRAIN_TILE_DESERT_1_1000 },
                { "2-1-1001", TextureID::TERRAIN_TILE_DESERT_1_1001 },
                { "2-1-1010", TextureID::TERRAIN_TILE_DESERT_1_1010 },
                { "2-1-1011", TextureID::TERRAIN_TILE_DESERT_1_1011 },
                { "2-1-1100", TextureID::TERRAIN_TILE_DESERT_1_1100 },
                { "2-1-1101", TextureID::TERRAIN_TILE_DESERT_1_1101 },
                { "2-1-1110", TextureID::TERRAIN_TILE_DESERT_1_1110 },
                { "2-1-1111", TextureID::TERRAIN_TILE_DESERT_1_1111 },
                
                { "3-0-0000", TextureID::TERRAIN_TILE_SNOW_0_0000 },
                { "3-0-0001", TextureID::TERRAIN_TILE_SNOW_0_0001 },
                { "3-0-0010", TextureID::TERRAIN_TILE_SNOW_0_0010 },
                { "3-0-0011", TextureID::TERRAIN_TILE_SNOW_0_0011 },
                { "3-0-0100", TextureID::TERRAIN_TILE_SNOW_0_0100 },
                { "3-0-0101", TextureID::TERRAIN_TILE_SNOW_0_0101 },
                { "3-0-0110", TextureID::TERRAIN_TILE_SNOW_0_0110 },
                { "3-0-0111", TextureID::TERRAIN_TILE_SNOW_0_0111 },
                { "3-0-1000", TextureID::TERRAIN_TILE_SNOW_0_1000 },
                { "3-0-1001", TextureID::TERRAIN_TILE_SNOW_0_1001 },
                { "3-0-1010", TextureID::TERRAIN_TILE_SNOW_0_1010 },
                { "3-0-1011", TextureID::TERRAIN_TILE_SNOW_0_1011 },
                { "3-0-1100", TextureID::TERRAIN_TILE_SNOW_0_1100 },
                { "3-0-1101", TextureID::TERRAIN_TILE_SNOW_0_1101 },
                { "3-0-1110", TextureID::TERRAIN_TILE_SNOW_0_1110 },
                { "3-0-1111", TextureID::TERRAIN_TILE_SNOW_0_1111 },
                
                { "3-1-0000", TextureID::TERRAIN_TILE_SNOW_1_0000 },
                { "3-1-0001", TextureID::TERRAIN_TILE_SNOW_1_0001 },
                { "3-1-0010", TextureID::TERRAIN_TILE_SNOW_1_0010 },
                { "3-1-0011", TextureID::TERRAIN_TILE_SNOW_1_0011 },
                { "3-1-0100", TextureID::TERRAIN_TILE_SNOW_1_0100 },
                { "3-1-0101", TextureID::TERRAIN_TILE_SNOW_1_0101 },
                { "3-1-0110", TextureID::TERRAIN_TILE_SNOW_1_0110 },
                { "3-1-0111", TextureID::TERRAIN_TILE_SNOW_1_0111 },
                { "3-1-1000", TextureID::TERRAIN_TILE_SNOW_1_1000 },
                { "3-1-1001", TextureID::TERRAIN_TILE_SNOW_1_1001 },
                { "3-1-1010", TextureID::TERRAIN_TILE_SNOW_1_1010 },
                { "3-1-1011", TextureID::TERRAIN_TILE_SNOW_1_1011 },
                { "3-1-1100", TextureID::TERRAIN_TILE_SNOW_1_1100 },
                { "3-1-1101", TextureID::TERRAIN_TILE_SNOW_1_1101 },
                { "3-1-1110", TextureID::TERRAIN_TILE_SNOW_1_1110 },
                { "3-1-1111", TextureID::TERRAIN_TILE_SNOW_1_1111 }
            };
            
            auto it = m_overlayMap.find( id );
            if ( it != m_overlayMap.end() )
            {
                return it->second;
            }
            
            //std::cout << id << " : INVALID!!!!\n";
            return TextureID::INVALID;
        }        
        
        Tile::Tile() //:
//          m_tileQuad{ sf::Quads, 4 },
//          m_overlayQuad{ sf::Quads, 4 }
        {
            // Create the tile vertex array
            m_tileQuad.setPrimitiveType( sf::Quads );
            m_tileQuad.append( sf::Vertex() );
            m_tileQuad.append( sf::Vertex() );
            m_tileQuad.append( sf::Vertex() );
            m_tileQuad.append( sf::Vertex() );
            
//             // Create the straight overlay vertex array
//             m_overlayQuad[0].setPrimitiveType( sf::Quads );
//             m_overlayQuad[0].append( sf::Vertex() );
//             m_overlayQuad[0].append( sf::Vertex() );
//             m_overlayQuad[0].append( sf::Vertex() );
//             m_overlayQuad[0].append( sf::Vertex() );
//             
//             // Create the diagonal overlay vertex array
//             m_overlayQuad[1].setPrimitiveType( sf::Quads );
//             m_overlayQuad[1].append( sf::Vertex() );
//             m_overlayQuad[1].append( sf::Vertex() );
//             m_overlayQuad[1].append( sf::Vertex() );
//             m_overlayQuad[1].append( sf::Vertex() );
            
            for ( int i = 0; i < TERRAIN_COUNT - 1; ++i )
                for ( int j = 0; j < 2; ++j )
                {
                    m_overlayQuad[i][j].setPrimitiveType( sf::Quads );
                    m_overlayQuad[i][j].append( sf::Vertex() );
                    m_overlayQuad[i][j].append( sf::Vertex() );
                    m_overlayQuad[i][j].append( sf::Vertex() );
                    m_overlayQuad[i][j].append( sf::Vertex() );
                }
            
            // Initialize the tile and overlays vertex arrays
            
            m_tileQuad[0].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, 0.f };
            m_tileQuad[1].texCoords = sf::Vector2f{ TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT * 0.5 };
            m_tileQuad[2].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, TERRAIN_TILE_HEIGHT };
            m_tileQuad[3].texCoords = sf::Vector2f{ 0.f, TERRAIN_TILE_HEIGHT * 0.5 };
            
//             m_overlayQuad[0][0].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, 0.f };
//             m_overlayQuad[0][1].texCoords = sf::Vector2f{ TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT * 0.5 };
//             m_overlayQuad[0][2].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, TERRAIN_TILE_HEIGHT };
//             m_overlayQuad[0][3].texCoords = sf::Vector2f{ 0.f, TERRAIN_TILE_HEIGHT * 0.5 };
//             
//             m_overlayQuad[1][0].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, 0.f };
//             m_overlayQuad[1][1].texCoords = sf::Vector2f{ TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT * 0.5 };
//             m_overlayQuad[1][2].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, TERRAIN_TILE_HEIGHT };
//             m_overlayQuad[1][3].texCoords = sf::Vector2f{ 0.f, TERRAIN_TILE_HEIGHT * 0.5 };
            
            for ( int i = 0; i < TERRAIN_COUNT - 1; ++i )
                for ( int j = 0; j < 2; ++j )
                {
                    m_overlayQuad[i][j][0].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, 0.f };
                    m_overlayQuad[i][j][1].texCoords = sf::Vector2f{ TERRAIN_TILE_WIDTH, TERRAIN_TILE_HEIGHT * 0.5 };
                    m_overlayQuad[i][j][2].texCoords = sf::Vector2f{ TERRAIN_TILE_HEIGHT, TERRAIN_TILE_HEIGHT };
                    m_overlayQuad[i][j][3].texCoords = sf::Vector2f{ 0.f, TERRAIN_TILE_HEIGHT * 0.5 };
                    
                    m_overlayTexPtr[i][j] = nullptr;
                }
            
//             m_overlayTexPtr[0] = nullptr;
//             m_overlayTexPtr[1] = nullptr;
            
            setPosition( sf::Vector2f{ 0.f, 0.f} );
            
            TextureID texture = TextureID::TERRAIN_TILE_WATER_01;
            
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
            
            m_type = getTerrainType( texture );
            
            //m_neighborsStraight.set(false);
            //m_neighborsDiagonal.set(false);
            for ( int i = 0; i < TERRAIN_COUNT - 1; ++i )
            {
                m_neighborsStraight[i] = 0x00;
                m_neighborsDiagonal[i] = 0x00;
            }
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
            
//             m_overlayQuad[0][0].position = position;
//             m_overlayQuad[0][1].position = sf::Vector2f{ m_overlayQuad[0][0].position.x + TERRAIN_TILE_HEIGHT, m_overlayQuad[0][0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
//             m_overlayQuad[0][2].position = sf::Vector2f{ m_overlayQuad[0][0].position.x, m_overlayQuad[0][0].position.y + TERRAIN_TILE_HEIGHT };
//             m_overlayQuad[0][3].position = sf::Vector2f{ m_overlayQuad[0][0].position.x - TERRAIN_TILE_HEIGHT, m_overlayQuad[0][0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
//             
//             m_overlayQuad[1][0].position = position;
//             m_overlayQuad[1][1].position = sf::Vector2f{ m_overlayQuad[1][0].position.x + TERRAIN_TILE_HEIGHT, m_overlayQuad[1][0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
//             m_overlayQuad[1][2].position = sf::Vector2f{ m_overlayQuad[1][0].position.x, m_overlayQuad[1][0].position.y + TERRAIN_TILE_HEIGHT };
//             m_overlayQuad[1][3].position = sf::Vector2f{ m_overlayQuad[1][0].position.x - TERRAIN_TILE_HEIGHT, m_overlayQuad[1][0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
            
            for ( int i = 0; i < TERRAIN_COUNT - 1; ++i )
                for ( int j = 0; j < 2; ++j )
                {
                    m_overlayQuad[i][j][0].position = position;
                    m_overlayQuad[i][j][1].position = sf::Vector2f{ m_overlayQuad[i][j][0].position.x + TERRAIN_TILE_HEIGHT, m_overlayQuad[i][j][0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
                    m_overlayQuad[i][j][2].position = sf::Vector2f{ m_overlayQuad[i][j][0].position.x, m_overlayQuad[i][j][0].position.y + TERRAIN_TILE_HEIGHT };
                    m_overlayQuad[i][j][3].position = sf::Vector2f{ m_overlayQuad[i][j][0].position.x - TERRAIN_TILE_HEIGHT, m_overlayQuad[i][j][0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
                }
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
            
//             m_overlayQuad[0][0].color = fillColor;
//             m_overlayQuad[0][1].color = fillColor;
//             m_overlayQuad[0][2].color = fillColor;
//             m_overlayQuad[0][3].color = fillColor;
//             
//             m_overlayQuad[1][0].color = fillColor;
//             m_overlayQuad[1][1].color = fillColor;
//             m_overlayQuad[1][2].color = fillColor;
//             m_overlayQuad[1][3].color = fillColor;
            
            for ( int i = 0; i < TERRAIN_COUNT - 1; ++i )
                for ( int j = 0; j < 2; ++j )
                {
                    m_overlayQuad[i][j][0].color = fillColor;
                    m_overlayQuad[i][j][1].color = fillColor;
                    m_overlayQuad[i][j][2].color = fillColor;
                    m_overlayQuad[i][j][3].color = fillColor;
                }
        }

        // https://stackoverflow.com/questions/27100729/find-which-tile-was-clicked-in-a-isometric-staggered-column-system
        bool Tile::contains( const sf::Vector2f mouse )
        {
            sf::Vector2f center{ m_tileQuad[3].position.x + TERRAIN_TILE_WIDTH * 0.5f, m_tileQuad[0].position.y + TERRAIN_TILE_HEIGHT * 0.5f };
            float dx = std::abs( mouse.x - center.x );
            float dy = std::abs( mouse.y - center.y );
            
            return dx / ( TERRAIN_TILE_WIDTH * 0.5f - 1.f) + dy / ( TERRAIN_TILE_HEIGHT * 0.5f - 1.f ) < 1;
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
        
        void Tile::setType( TerrainType terrainType )
        {
            m_type = terrainType;
        }
                
        TerrainType Tile::getType()
        {
            return m_type;
        }
        
        void Tile::setOverlayTexture( const int terrainPrec, const int overlay, TextureID texID )
        {
            //std::cout << "XX " << terrainPrec << ", " << overlay << ", " << textureIDToStr( texID ) << std::endl;
            if ( texID == TextureID::INVALID || texID == getOverlayTexture( "1-0-0000" ) || texID == getOverlayTexture( "1-1-0000" ) || texID == getOverlayTexture( "2-0-0000" ) || texID == getOverlayTexture( "2-1-0000" ) || texID == getOverlayTexture( "3-0-0000" ) || texID == getOverlayTexture( "3-1-0000" ) )
                m_overlayTexPtr[terrainPrec][overlay] = nullptr;
            else
                m_overlayTexPtr[terrainPrec][overlay] = ResourceManager::getTexture( texID ).get();
        }

        void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = m_tileTexPtr;
            target.draw( m_tileQuad, states);
            
//             if ( m_overlayTexPtr[0] != nullptr )
//             {
//                 states.texture = m_overlayTexPtr[0];
//                 target.draw( m_overlayQuad[0], states);
//             }
//             
//             if ( m_overlayTexPtr[1] != nullptr )
//             {
//                 states.texture = m_overlayTexPtr[1];
//                 target.draw( m_overlayQuad[1], states);
//             }
            
            for ( int i = 0; i < TERRAIN_COUNT - 1; ++i )
                for ( int j = 0; j < 2; ++j )
                {
                    if ( m_overlayTexPtr[i][j] != nullptr )
                    {
                        if ( m_precedences[m_type] - 1 < i )
                        {
                            states.texture = m_overlayTexPtr[i][j];
                            target.draw( m_overlayQuad[i][j], states);
                        }
                    }
                }
        }
        
        ///////////////////////////////////////////////////////////////////////////////////////////
        
        TileMap::TileMap( const int size, sf::RenderWindow& window ) :
         m_size( size ),
         m_selectedTile( TextureID::TERRAIN_TILE_WATER_01 ),
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
                    float cX = (TERRAIN_TILE_HEIGHT - 1.5) * x;
                    float cY = (TERRAIN_TILE_HEIGHT - 1.5) * y;
                    
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
                
                bool static once = true;                    
                
//                 for ( auto&& tileRow : m_tiles )
//                 {
//                     for ( auto&& tile : tileRow )
                for ( int y = 0; y < m_size; ++y )
                {
                    for ( int x = 0; x < m_size; ++x )
                    {
                        if ( m_tiles[y][x]->inWorldView( m_mapView ) )
                        {
                            if ( AnimationManager::AnimationManager::exists( "tile-anim-" + std::to_string( long( m_tiles[y][x]->getQuad() ) ) ) )
                                AnimationManager::AnimationManager::setVisibility( "tile-anim-" + std::to_string( long( m_tiles[y][x]->getQuad() ) ), true );
                            
                        auto tile = m_tiles[y][x];
                        
                        // Highlight mouseover tile
                        if ( tile->contains( mousePos ) )
                                tile->setFillColor( sf::Color( 200, 200, 200, 200 ) );
                            else
                                tile->setFillColor( sf::Color( 255, 255, 255, 255 ) );
                        
                        // Update tile texture
                        if ( mouseDown && tile->contains( mousePos ) )// && once )
                        {
                            once = false;
//                             if ( tile->tileAnimated() )
//                             {
//                                 AnimationManager::AnimationManager::destroyAnimation( "tile-anim-" + std::to_string( long(tile->getQuad()) ) );
//                                 tile->setAnimated(false);
//                             }
                            
                            // Change tile to the current selected tile
                            if ( isAnimatedTexture( m_selectedTile ) )
                            {
                                AnimationManager::AnimationManager::createAnimation( "tile-anim-" + std::to_string( long(tile->getQuad()) ), tile->getQuad(), sf::Vector2i{ 128, 64 }, 2, sf::seconds(1.f) );
                                tile->setAnimated(true);
                            }
                            
                            // Update the texture and type of the current, selected tile
                            
                            // 1. First update the base texture for the selected tile
                            tile->setTexture( m_selectedTile );
                            tile->setType( getTerrainType( m_selectedTile ) );
                            
                            // Reset overlay info for the selected tile
                            
                            // Precedence of the current tile
                            auto currentPrec = Tile::m_precedences[getTerrainType(m_selectedTile)];
                                                        
                            // The elemens represent the following:
                            // { x-offset, y-offset, adjacent side of neighbor, adjacent side of current }
                            static const int stNeighbors[4][4] =
                            {
                                {  0, -1,  3,  1 }, // N
                                {  1,  0,  4,  2 }, // E
                                {  0,  1,  1,  3 }, // S
                                { -1,  0,  2,  4 }  // W
                            };
                            
                            // The elemens represent the following:
                            // { x-offset, y-offset, adjacent side of neighbor, adjacent side of current }
                            static const int diaNeighbors[4][4] =
                            {
                                {  1, -1, 3, 1 }, // NE
                                {  1,  1, 4, 2 }, // SE
                                { -1,  1, 1, 3 }, // SW
                                { -1, -1, 2, 4 }  // NW
                            };
                            
                            for ( int prec = 0; prec < TERRAIN_COUNT; ++prec )
                            {
                                for ( int i = 0; i < 4; ++i )
                                {
                                    int nx = x + stNeighbors[i][0];
                                    int ny = y + stNeighbors[i][1];
                                    
                                    // If neighbor is within bounds, check and set overlay
                                    if ( nx >= 0 && nx < m_size &&
                                        ny >= 0 && ny < m_size )
                                    {
                                        int neighborPrec = Tile::m_precedences[ m_tiles[ny][nx]->getType() ];
                                        
                                        if ( prec == neighborPrec )
                                        {
                                            // If the precedence of the current tile is lesser than the neighbor,
                                            // it is overlaid with the transition for the neighbor.
                                            if ( currentPrec < neighborPrec )
                                            {
                                                m_tiles[ny][nx]->m_neighborsStraight[neighborPrec].set( stNeighbors[i][2] - 1, true );
                                                m_tiles[ny][nx]->setOverlayTexture( neighborPrec - 1, 0, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-0-" + m_tiles[ny][nx]->m_neighborsStraight[neighborPrec].to_string() ) );
                                                
                                                tile->m_neighborsStraight[neighborPrec - 0].set( stNeighbors[i][3] - 1, true );
                                                tile->setOverlayTexture( neighborPrec - 1, 0, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-0-" + tile->m_neighborsStraight[neighborPrec].to_string() ) );
                                            }
                                            
                                            // If the precedence of the current tile is equal to the neighbor,
                                            // then remove the overlay for that side from the neighbor and also
                                            // remove any overlay of the current tile from that side. 
                                            if ( currentPrec == neighborPrec )
                                            {
                                                tile->m_neighborsStraight[currentPrec - 0].set( stNeighbors[i][3] - 1, true );
                                                tile->setOverlayTexture( currentPrec - 1, 0, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-0-" + tile->m_neighborsStraight[currentPrec].to_string() ) );
                                                
                                                m_tiles[ny][nx]->m_neighborsStraight[currentPrec - 0].set( stNeighbors[i][2] - 1, true );
                                                m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 0, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-0-" + m_tiles[ny][nx]->m_neighborsStraight[currentPrec].to_string() ) );
                                            }
                                            
                                            // If the precedence of the current tile is higher than the neighbor,
                                            // then overlay the neighbor with the transition for the current tile
                                            // along with any other previous transitions.
                                            if ( currentPrec > neighborPrec )
                                            {
                                                m_tiles[ny][nx]->m_neighborsStraight[currentPrec - 0].set( stNeighbors[i][2] - 1, true );
                                                m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 0, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-0-" + m_tiles[ny][nx]->m_neighborsStraight[currentPrec].to_string() ) );
                                            }
                                            
                                            for ( auto p1 = 1; p1 < currentPrec; ++p1 )
                                            {
                                                m_tiles[ny][nx]->m_neighborsStraight[p1 - 0].set( stNeighbors[i][2] - 1, false );
                                                m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 0, Tile::getOverlayTexture( std::to_string( p1 ) + "-0-" + m_tiles[ny][nx]->m_neighborsStraight[p1].to_string() ) );
                                            }
                                            
                                            for ( auto p1 = currentPrec + 1; p1 < Tile::m_precedences.size(); ++p1 )
                                            {
                                                m_tiles[ny][nx]->m_neighborsStraight[p1 - 0].set( stNeighbors[i][2] - 1, false );
                                                m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 0, Tile::getOverlayTexture( std::to_string( p1 ) + "-0-" + m_tiles[ny][nx]->m_neighborsStraight[p1].to_string() ) );
                                            }
                                        }
                                    }
                                    
                                    nx = x + diaNeighbors[i][0];
                                    ny = y + diaNeighbors[i][1];
                                    
                                    // If neighbor is within bounds, check and set overlay
                                    if ( nx >= 0 && nx < m_size &&
                                        ny >= 0 && ny < m_size )
                                    {
                                        int neighborPrec = Tile::m_precedences[ m_tiles[ny][nx]->getType() ];
                                        
                                        if ( prec == neighborPrec )
                                        {
                                            if ( currentPrec < neighborPrec )
                                            {
                                                m_tiles[ny][nx]->m_neighborsDiagonal[neighborPrec].set( diaNeighbors[i][2] - 1, true );
                                                m_tiles[ny][nx]->setOverlayTexture( neighborPrec - 1, 1, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[neighborPrec].to_string() ) );
                                                
                                                tile->m_neighborsDiagonal[neighborPrec - 0].set( diaNeighbors[i][3] - 1, true );
                                                tile->setOverlayTexture( neighborPrec - 1, 1, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-1-" + tile->m_neighborsDiagonal[neighborPrec].to_string() ) );
                                            }
                                            
                                            if ( currentPrec == neighborPrec && currentPrec > 0)
                                            {
                                                tile->m_neighborsDiagonal[currentPrec - 0].set( diaNeighbors[i][3] - 1, true );
                                                tile->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + tile->m_neighborsDiagonal[currentPrec].to_string() ) );
                                                
                                                m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec - 0].set( diaNeighbors[i][2] - 1, true );
                                                m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec].to_string() ) );
                                            }
                                            
                                            if ( currentPrec > neighborPrec )
                                            {
                                                m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec].set( diaNeighbors[i][2] - 1, true );
                                                m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[ currentPrec ].to_string() ) );
                                            }
                                            
                                            for ( auto p1 = 1; p1 < currentPrec; ++p1 )
                                            {
                                                m_tiles[ny][nx]->m_neighborsDiagonal[p1 - 0].set( diaNeighbors[i][2] - 1, false );
                                                m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 1, Tile::getOverlayTexture( std::to_string( p1 ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[p1].to_string() ) );
                                            }
                                            
                                            for ( auto p1 = currentPrec + 1; p1 < Tile::m_precedences.size(); ++p1 )
                                            {
                                                m_tiles[ny][nx]->m_neighborsDiagonal[p1 - 0].set( diaNeighbors[i][2] - 1, false );
                                                m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 1, Tile::getOverlayTexture( std::to_string( p1 ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[p1].to_string() ) );
                                            }
                                        }
                                    }
                                }
                                
//                                 for ( int i = 0; i < 4; ++i )
//                                 {
//                                     int nx = x + diaNeighbors[i][0];
//                                     int ny = y + diaNeighbors[i][1];
//                                     
//                                     // If neighbor is within bounds, check and set overlay
//                                     if ( nx >= 0 && nx < m_size &&
//                                         ny >= 0 && ny < m_size )
//                                     {
//                                         int neighborPrec = Tile::m_precedences[ m_tiles[ny][nx]->getType() ];
//                                         
//                                         if ( prec == neighborPrec )
//                                         {
//                                             if ( currentPrec < neighborPrec )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[neighborPrec].set( diaNeighbors[i][2] - 1, true );
//                                                 m_tiles[ny][nx]->setOverlayTexture( neighborPrec - 1, 1, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[neighborPrec].to_string() ) );
//                                                 
//                                                 tile->m_neighborsDiagonal[neighborPrec - 0].set( diaNeighbors[i][3] - 1, true );
//                                                 tile->setOverlayTexture( neighborPrec - 1, 1, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-1-" + tile->m_neighborsDiagonal[neighborPrec].to_string() ) );
//                                             }
//                                             
//                                             if ( currentPrec == neighborPrec && currentPrec > 0)
//                                             {
//                                                 tile->m_neighborsDiagonal[currentPrec - 0].set( diaNeighbors[i][3] - 1, true );
//                                                 tile->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + tile->m_neighborsDiagonal[currentPrec].to_string() ) );
//                                                 
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec - 0].set( diaNeighbors[i][2] - 1, true );
//                                                 m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec].to_string() ) );
//                                             }
//                                             
//                                             if ( currentPrec > neighborPrec )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec].set( diaNeighbors[i][2] - 1, true );
//                                                 m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[ currentPrec ].to_string() ) );
//                                             }
//                                             
//                                             for ( auto p1 = 1; p1 < currentPrec; ++p1 )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[p1 - 0].set( diaNeighbors[i][2] - 1, false );
//                                                 m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 1, Tile::getOverlayTexture( std::to_string( p1 ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[p1].to_string() ) );
//                                             }
//                                             
//                                             for ( auto p1 = currentPrec + 1; p1 < Tile::m_precedences.size(); ++p1 )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[p1 - 0].set( diaNeighbors[i][2] - 1, false );
//                                                 m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 1, Tile::getOverlayTexture( std::to_string( p1 ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[p1].to_string() ) );
//                                             }
//                                         }
//                                     }
//                                 }
                            }
                            
//                             for ( int prec = 0; prec < TERRAIN_COUNT; ++prec )
//                             {
//                                 for ( int i = 0; i < 4; ++i )
//                                 {
//                                     int nx = x + diaNeighbors[i][0];
//                                     int ny = y + diaNeighbors[i][1];
//                                     
//                                     // If neighbor is within bounds, check and set overlay
//                                     if ( nx >= 0 && nx < m_size &&
//                                         ny >= 0 && ny < m_size )
//                                     {
//                                         int neighborPrec = Tile::m_precedences[ m_tiles[ny][nx]->getType() ];
//                                         
//                                         if ( prec == neighborPrec )
//                                         {
//                                             if ( currentPrec < neighborPrec )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[neighborPrec].set( diaNeighbors[i][2] - 1, true );
//                                                 m_tiles[ny][nx]->setOverlayTexture( neighborPrec - 1, 1, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[neighborPrec].to_string() ) );
//                                                 
//                                                 tile->m_neighborsDiagonal[neighborPrec - 0].set( diaNeighbors[i][3] - 1, true );
//                                                 tile->setOverlayTexture( neighborPrec - 1, 1, Tile::getOverlayTexture( std::to_string( neighborPrec ) + "-1-" + tile->m_neighborsDiagonal[neighborPrec].to_string() ) );
//                                             }
//                                             
//                                             if ( currentPrec == neighborPrec && currentPrec > 0)
//                                             {
//                                                 tile->m_neighborsDiagonal[currentPrec - 0].set( diaNeighbors[i][3] - 1, true );
//                                                 tile->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + tile->m_neighborsDiagonal[currentPrec].to_string() ) );
//                                                 
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec - 0].set( diaNeighbors[i][2] - 1, true );
//                                                 m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec].to_string() ) );
//                                             }
//                                             
//                                             if ( currentPrec > neighborPrec )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[currentPrec].set( diaNeighbors[i][2] - 1, true );
//                                                 m_tiles[ny][nx]->setOverlayTexture( currentPrec - 1, 1, Tile::getOverlayTexture( std::to_string( currentPrec ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[ currentPrec ].to_string() ) );
//                                             }
//                                             
//                                             for ( auto p1 = 1; p1 < currentPrec; ++p1 )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[p1 - 0].set( diaNeighbors[i][2] - 1, false );
//                                                 m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 1, Tile::getOverlayTexture( std::to_string( p1 ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[p1].to_string() ) );
//                                             }
//                                             
//                                             for ( auto p1 = currentPrec + 1; p1 < Tile::m_precedences.size(); ++p1 )
//                                             {
//                                                 m_tiles[ny][nx]->m_neighborsDiagonal[p1 - 0].set( diaNeighbors[i][2] - 1, false );
//                                                 m_tiles[ny][nx]->setOverlayTexture( p1 - 1, 1, Tile::getOverlayTexture( std::to_string( p1 ) + "-1-" + m_tiles[ny][nx]->m_neighborsDiagonal[p1].to_string() ) );
//                                             }
//                                         }
//                                     }
//                                 }
//                             }
                        }
                        
                        if ( !mouseDown )
                            once = true;
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
            
        }
        
        void TileMap::setSelectedTile( const TextureID texID )
        {
            m_selectedTile = texID;
        }
        
        void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            // TODO: After testing, make the rendering follow depth order
//             for ( auto&& tileRow : m_tiles )
//                 for ( auto&& tile : tileRow )
//                     target.draw( tile, states);
            for ( int y = 0; y < m_size ; ++y )
            {
                for ( int x = 0; x < m_size ; ++x )
                {
                    if ( m_tiles[y][x]->inWorldView( m_mapView ) )
                    {
                        states.transform *= getTransform();
                        target.draw( *m_tiles[y][x], states);
                    }
                }
            }
        }
    }
}
