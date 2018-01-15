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

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace rts
{
    namespace WorldEntities
    {
        
        // Abstracts the concept of a single 2:1  isometric tile
        class Tile : public sf::Drawable, sf::Transformable
        {
            public:
                
                Tile( );
                
                void setPosition( const sf::Vector2f position );
            
                // Get the position of a tile w.r.t. to one of the four vertices (0-3)
                const sf::Vector2f getPosition( int vertex );
                
                void setFillColor( const sf::Color fillColor );
                
                bool contains( const sf::Vector2f mouse );
                
                //bool inView( const sf::RenderWindow& window );
                
                void setTexture( const TextureID texID );
                
            private:
                
                virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            
            private:
                
                // A set of 4 vertices to represent a 2:1 isometric tile
                sf::VertexArray m_tileQuad;
                
                // Texture of the tile
                sf::Texture* m_tileTexPtr;
        };
        
        ///////////////////////////////////////////////////////////////////////////////////////////
        
        // Abstracts the implementation of a n isometric tile map using the above tile type
        class TileMap : public sf::Drawable, sf::Transformable
        {
            public:
                
                TileMap( const int size, sf::RenderWindow& window );
                
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
                std::vector<std::vector<Tile>> m_tiles;
                
                // The selected tile
                TextureID m_selectedTile;
                
                sf::RenderWindow* m_window;
                
                sf::View m_mapView;
        };
    }
}

#endif // TILE_MAP_HPP