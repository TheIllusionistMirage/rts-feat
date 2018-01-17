/*
 * ---------------
 *  Module : Game
 * ---------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods & classes declared
 *  in Game module.
 */

#include <SFML/Window/Mouse.hpp>

#include "Utility/Constants.hpp"
#include "Utility/Log.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "GameStates/MainMenuState.hpp"
#include "GameStates/MapEditorState.hpp"
#include "Game.hpp"

namespace rts
{
    Game::Game()
    {
        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.stencilBits = 8;
        settings.antialiasingLevel = 1;
        settings.majorVersion = 3;
        settings.minorVersion = 0;
        
        // Create a new game window with the default dimensions
        // and title as set in the Utility::Constants module.
        m_window.create( sf::VideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP ),
                         WINDOW_TITLE,
                         sf::Style::Fullscreen,
                         settings );
        
        m_window.setMouseCursorVisible(false);
        
        LOG(Logger::Level::DEBUG) << "Creating Game object." << std::endl;
        
        // Limit the game frame rate as set in Utility::Constants module.
        m_window.setFramerateLimit( FRAMES_PER_SECOND );
        
        
                
        /* Import all game assets by invoking the apporiate methods of the resource manager module.
         * 
         * 1. First the textures are imported.
         * 2. Next the fonts are imported.
         */
        
        bool allResLoaded = true;
        
        if ( !ResourceManager::addTexture( TextureID::MOUSE_POINTER, PATH_TEXTURES + TEXTURE_MOUSE_POINTER ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add mouse pointer texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::DEFAULT_BACKGROUND, PATH_TEXTURES + TEXTURE_DEFAULT_BACKGROUND ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add background texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::MAIN_MENU_BACKGROUND, PATH_TEXTURES + TEXTURE_MAIN_MENU_BACKGROUND) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add main menu background texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::MAP_EDITOR_BACKGROUND, PATH_TEXTURES + TEXTURE_MAP_EDITOR_BACKGROUND) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add main menu background texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_BUTTON, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_BUTTON ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI button texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_MENU_BUTTON, PATH_UI_TEXTURES + TEXTURE_UI_MENU_BUTTON ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI menu button texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_PICTURE, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_PICTURE ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add default UI picture texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_RADIOBUTTON_NORMAL, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_RADIOBUTTON_NORMAL ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI radio button normal texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_LISTITEM, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_LISTITEM ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI list item texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_COMBOBOX_SELECTED, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_COMBOBOX_SELECTED ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI combo box texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_DEFAULT_COMBOBOX_ARROW, PATH_UI_TEXTURES + TEXTURE_UI_DEFAULT_COMBOBOX_ARROW ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add UI combo box arrow texture resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_TILEBOX, PATH_UI_TEXTURES + TEXTURE_UI_TILEBOX ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::UI_TILEBOX ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_SCROLL_AREA, PATH_UI_TEXTURES + TEXTURE_UI_SCROLL_AREA ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::UI_SCROLL_AREA) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_SCROLL_BAR, PATH_UI_TEXTURES + TEXTURE_UI_SCROLL_BAR ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::UI_SCROLL_BAR ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_SCROLL_ARROW_UP, PATH_UI_TEXTURES + TEXTURE_UI_SCROLL_ARROW_UP ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::UI_SCROLL_ARROW_UP) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::UI_SCROLL_ARROW_DOWN, PATH_UI_TEXTURES + TEXTURE_UI_SCROLL_ARROW_DOWN ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::UI_SCROLL_ARROW_DOWN ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_DEFAULT, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_DEFAULT ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_DEFAULT ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DEFAULT, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DEFAULT ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_DEFAULT ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_WATER_DEFAULT, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_WATER_DEFAULT ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_WATER_DEFAULT ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_EAST, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_EAST ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_EAST ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WEST, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_WEST ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WEST ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_NORTH, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_NORTH ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_NORTH ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_SOUTH, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_SOUTH ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_SOUTH ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_NORTH_EAST, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_NORTH_EAST ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_NORTH_EAST ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_NORTH_WEST, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_NORTH_WEST ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_NORTH_WEST ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_SOUTH_EAST, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_SOUTH_EAST ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_SOUTH_EAST ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_SOUTH_WEST, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_SOUTH_WEST ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_SOUTH_WEST ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_01 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_01 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_02, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_02 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_02 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_03, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_03 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_03 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_04, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_04 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_04 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_05, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_05 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_05 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_06, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_06 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_06 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_01 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_01 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_02, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_02 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_02 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_03, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_03 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_03 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_04, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_04 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_04 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_05, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_05 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_05 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_06, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_06 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_06 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_07, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_07 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_07 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_08, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_08 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_08 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_09, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_09 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_09 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_10, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_10 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_10 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_11, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_11 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_11 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_12, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_12 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_12 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_13, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_13 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_13 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_14, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_14 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_14 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_15, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_15 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_15 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_16, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_16 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_16 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_17, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_17 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_17 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_18, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_18 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_18 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_19, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_19 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_19 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_20, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_20 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_20 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_21, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_21 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_21 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_22, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_22 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_22 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_23, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_23 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_23 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_24, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_24 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_24 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_25, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_25 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_25 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_26, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_26 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_26 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_27, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_27 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_27 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_28, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_28 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_28 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_29, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_29 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_29 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_30, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_30 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_30 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_31, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_31 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_31 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_32, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_32 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_32 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_33, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_33 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_33 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_34, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_34 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_34 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_35, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_35 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_35 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_36, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_36 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_36 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_37, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_37 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_37 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_38, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_38 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_38 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_39, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_39 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_39 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_40, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_40 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_40 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_41, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_41 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_41 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_42, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_42 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_42 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_43, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_43 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_43 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_44, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_44 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_44 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_45, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_45 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_45 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_46, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_46 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_46 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_47, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_47 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_47 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_48, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_48 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_48 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_49, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_49 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_49 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_50, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_50 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_50 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_51, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_51 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_51 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_52, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_52 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_52 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_53, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_53 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_53 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_54, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_54 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_54 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_55, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_55 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_55 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_56, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_56 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_56 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_57, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_57 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_57 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_58, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_58 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_58 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_59, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_59 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_59 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_60, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_60 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_60 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_61, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_61 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_61 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_62, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_62 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_62 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_63, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_63 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_63 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_64, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_64 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_64 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_65, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_65 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_65 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_LAND_WATER_66, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_LAND_WATER_66 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_LAND_WATER_66 ) << std::endl;
            allResLoaded = false;
        }
                
        // Load all fonts
        
        if ( !ResourceManager::addFont( FontID::DEFAULT, PATH_FONTS + FONT_DEFAULT ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add default font resource." << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::BASKERVILLE_OLD_FACE_REGULAR, PATH_FONTS + FONT_BASKERVILLE_OLD_FACE_REGULAR ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::BASKERVILLE_OLD_FACE_REGULAR ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::BEYOND_WONDERLAND, PATH_FONTS + FONT_BEYOND_WONDERLAND ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::BEYOND_WONDERLAND ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::BOOK_ANTIQUA_BOLD, PATH_FONTS + FONT_BOOK_ANTIQUA_BOLD ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::BOOK_ANTIQUA_BOLD ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::CLOISTER_BLACK_LIGHT, PATH_FONTS + FONT_CLOISTER_BLACK_LIGHT ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::CLOISTER_BLACK_LIGHT ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::CONSTANTIA_REGULAR, PATH_FONTS + FONT_CONSTANTIA_REGULAR ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::CONSTANTIA_REGULAR ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::DEJAVU_SERIF_BOOK, PATH_FONTS + FONT_DEJAVU_SERIF_BOOK ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::DEJAVU_SERIF_BOOK ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::GARAMOND_BOLD, PATH_FONTS + FONT_GARAMOND_BOLD ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::GARAMOND_BOLD ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::MONACO, PATH_FONTS + FONT_MONACO ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::MONACO ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::OLD_SERIF_GUT_REGULAR, PATH_FONTS + FONT_OLD_SERIF_GUT_REGULAR ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::OLD_SERIF_GUT_REGULAR ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::RINGBEARER_MEDIUM, PATH_FONTS + FONT_RINGBEARER_MEDIUM ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::RINGBEARER_MEDIUM ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::ROBOTO_BOLD, PATH_FONTS + FONT_ROBOTO_BOLD ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::ROBOTO_BOLD ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addFont( FontID::SOURCE_HAN_SANS_CN_NORMAL, PATH_FONTS + FONT_SOURCE_HAN_SANS_CN_NORMAL ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add font resource: " << fontIDToStr( FontID::SOURCE_HAN_SANS_CN_NORMAL ) << std::endl;
            allResLoaded = false;
        }
        
        if ( allResLoaded )
        {
            m_mousePointer.setTexture( *ResourceManager::getTexture( TextureID::MOUSE_POINTER ) );
            
            m_backgroundSprite.setTexture( *ResourceManager::getTexture( TextureID::DEFAULT_BACKGROUND ) );
        
            m_fps.setFont( *ResourceManager::getFont( FontID::DEFAULT ) );
            m_fps.setString( "FPS:0" );
            m_fps.setCharacterSize( 10 );
            m_fps.setPosition( m_window.mapPixelToCoords( sf::Vector2i{ 5, 5 } ) );
            m_fps.setFillColor( sf::Color::White );
            
            LOG(Logger::Level::DEBUG) << "Game object created." << std::endl;
            
            m_running = true;
        }
        else
        {
            m_running = false;
            LOG(Logger::Level::ERROR) << "Unable to create Game object" << std::endl;
        }
    }
    
//     Game::~Game()
//     {
//         while ( peekState() )
//             popState();
//         
//         LOG(Logger::Level::DEBUG) << "Game object destroyed." << std::endl;
//     }
    
    void Game::run()
    {
        LOG(Logger::Level::INFO) << "Game is running..." << std::endl;
        
        sf::Clock clock;
        sf::Time accumulator = sf::Time::Zero;
        sf::Time updateTime = sf::Time::Zero;
        unsigned frames = 0;
        
        while ( m_window.isOpen() && m_running && !m_states.empty() )
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition( m_window );
            
            sf::Time elapsedTime = clock.restart();
            accumulator += elapsedTime;
            
            if ( !peekState() )
                continue;
            
            while ( accumulator > FRAME_TIME )
            {
                accumulator -= FRAME_TIME;
                
                if ( peekState() )
                {
                    peekState()->handleInput();
                    peekState()->update( FRAME_TIME );
                }
                
                // Update the components
                //CManager::UIComponent::updateUIComponents( eveent, FRAME_TIME );
            }
            
            updateTime += elapsedTime;
            frames++;
            
            if ( updateTime >= sf::seconds(1.f) )
            {
                m_fps.setString("FPS:" + std::to_string(frames));
                updateTime -= sf::seconds(1.f);
                frames = 0;
            }
            
            m_mousePointer.setPosition( m_window.mapPixelToCoords( mousePos ) );
            
            m_window.clear( sf::Color::Black );
            m_window.draw( m_backgroundSprite );
            
            if ( peekState() )
                peekState()->draw(FRAME_TIME);
            
            CManager::UIComponent::renderUIComponents( m_window );
            
            m_window.draw( m_fps );
            //if ( m_backgroundSprite.getGlobalBounds().contains( static_cast<sf::Vector2f>( mousePos ) ) )
//             if ( m_mousePointer.getGlobalBounds().left >= 0 && m_mousePointer.getGlobalBounds().left < m_window.getSize().x &&
//                   m_mousePointer.getGlobalBounds().top >= 0 && m_mousePointer.getGlobalBounds().top < m_window.getSize().y )
                m_window.draw( m_mousePointer );
            m_window.display();
        }
        
        LOG(Logger::Level::INFO) << "Game stopped..." << std::endl;
        close();
    }
    
    void Game::close()
    {
        m_running = false;
        LOG(Logger::Level::DEBUG) << "Game shutdown" << std::endl;
    }
    
    void rts::Game::pushState(const rts::Game::State state)
    {
        switch ( state )
        {
            case State::MAIN_MENU:
            {
                m_states.push( std::make_shared<MainMenuState>( this ) );
                m_backgroundSprite.setTexture( *ResourceManager::getTexture( TextureID::MAIN_MENU_BACKGROUND ) );
//                 auto tex = ResourceManager::getTexture( TextureID::MAIN_MENU_BACKGROUND );
//                 m_backgroundSprite.setTexture( *tex );
//                 m_backgroundSprite.setTextureRect( sf::IntRect{ 0, 0, tex->getSize().x, tex->getSize().y } );
            } break;
            
            case State::START_GAME:
            {
                
            } break;
            
            case State::PLAYING:
            {
                
            } break;
            
            case State::MAP_EDITOR:
            {
                m_states.push( std::make_shared<MapEditorState>( this ) );
                m_backgroundSprite.setTexture( *ResourceManager::getTexture( TextureID::DEFAULT_BACKGROUND ) );
                
//                 auto tex = ResourceManager::getTexture( TextureID::MAP_EDITOR_BACKGROUND );
//                 m_backgroundSprite.setTexture( *tex );
                //m_backgroundSprite.setTextureRect( sf::IntRect{ 0, 0, tex->getSize().x, tex->getSize().y } );
                //std::cout << "SIZE: " << tex->getSize().x << " " << tex->getSize().y << std::endl;
            } break;
            
            case State::PAUSED:
            {
                
            } break;
            
            default:
            {
                LOG(Logger::Level::ERROR) << "Invalid state" << std::endl;
            }
        }
    }
    
    void rts::Game::popState()
    {
        if ( m_states.empty() )
            return;
        
        m_states.pop();
        
        if ( !m_states.empty() )
            peekState()->freeze(false);
    }
    
    void rts::Game::changeState(const rts::Game::State state)
    {
        if ( m_states.empty() )
            return;
        
        popState();
        pushState( state );
    }
    
    std::shared_ptr<GameState> Game::peekState()
    {
        if ( m_states.empty() )
            return nullptr;        
        return m_states.top();
    }
}
