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
 *  This module contains a class that defines the isometric tile map.
 * 
 */

#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <memory>
#include <vector>
#include <bitset>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace rts
{
    namespace WorldEntities
    {
        // Number of terrains in the world
        constexpr int TERRAIN_COUNT = 3;
        
        // Abstracts the concept of a single 2:1  isometric tile
        class Tile : public sf::Drawable, sf::Transformable
        {
            public:
                
                typedef std::shared_ptr<Tile> Ptr;
                
                static std::map<TerrainType, int> m_precedences;
                
                static TextureID getOverlayTexture( const std::string& id );
                
                std::bitset<4> m_neighborsStraight[TERRAIN_COUNT];// - 1];
                
                std::bitset<4> m_neighborsDiagonal[TERRAIN_COUNT];// - 1];
                                
            public:
                
                Tile( );
                
                ~Tile();
                
                inline void setPosition( const sf::Vector2f position );
            
                // Get the position of a tile w.r.t. to one of the four vertices (0-3)
                inline const sf::Vector2f getPosition( int vertex );
                
                inline void setFillColor( const sf::Color fillColor );
                
                inline bool contains( const sf::Vector2f mouse );
                
                inline void setTexture( const TextureID texID );
                
                /* If skip is TRUE, then the tile is not rendered */
                inline void skipRender( bool skip );
                
                inline bool inWorldView( const sf::View worldView ) const;
                
                inline void setAnimated( bool animated = false );
                
                inline bool tileAnimated() const;
                
                sf::VertexArray* getQuad();
                
                inline void setType( TerrainType terrainType );
                
                inline TerrainType getType();
                
                inline void setOverlayTexture( const int terrainPrec, const int overlay, TextureID texID );
                
            private:
                
                virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            
            private:
                
                // A set of 4 vertices to represent a 2:1 isometric tile
                sf::VertexArray m_tileQuad;
                
                // One for the N/E/S/W overlays (henceforth referred to as `straight`)
                // One for the NE/SE/SW/NW overlays (henceforth referred to as `diagonal`)
                
                //sf::VertexArray m_overlayQuad[2];
                sf::VertexArray m_overlayQuad[TERRAIN_COUNT - 1][2];
                
                // Texture of the tile
                sf::Texture* m_tileTexPtr;
                
                //sf::Texture* m_overlayTexPtr[2];
                sf::Texture* m_overlayTexPtr[TERRAIN_COUNT - 1][2];
                
                bool m_inView;
                                
                bool m_animated;
                
                TerrainType m_type;
        };
        
        ///////////////////////////////////////////////////////////////////////////////////////////
        
        // Abstracts the implementation of a n isometric tile map using the above tile type
        class TileMap : public sf::Drawable, sf::Transformable
        {
            public:
                
                //TileMap();
                
                TileMap( const int size, sf::RenderWindow& window );
                
                ~TileMap();
                
                //bool generate( const int size, sf::RenderWindow& window );
                
                void handleInput();
                void update( const sf::Time dt );
                
                void setSelectedTile( const TextureID texID );
                
            private:
                
                virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
                
            private:
                
                int m_size;
                
                // The 2D array of tiles in the map
                // NOTE: I'm well aware of the fact that
                // this is the most naive technique for
                // storing a tile based map
                std::vector<std::vector<Tile::Ptr>> m_tiles;
                
                // The selected tile
                TextureID m_selectedTile;
                
                sf::RenderWindow* m_window;
                
                sf::View m_mapView;
        };
    }
}

#endif // TILE_MAP_HPP
