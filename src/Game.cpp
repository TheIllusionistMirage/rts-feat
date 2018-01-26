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
        
        m_active = true;
        
                
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
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_WATER_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_WATER_01 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_WATER_01 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0000 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0000 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0001 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0010 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0011 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0100 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0101 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0110 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_0111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_0111 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_0111 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1000 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1000 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1001 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1010 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1011 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1100 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1101 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1110 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_0_1111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_0_1111 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_0_1111 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0000 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0000 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0001 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0010 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0011 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0100 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0101 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0110 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_0111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_0111 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_0111 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1000 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1000 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1001 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1010 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1011 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1100 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1101 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1110 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_1_1111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_1_1111 ) )
        {
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_1_1111 ) << std::endl;
            allResLoaded = false;
        }
        
        // Desert tile textures
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0000 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0000 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0001 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0010 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0011 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0100 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0101 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0110 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_0111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_0111 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_0111 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1000 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1000 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1001 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1010 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1011 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1100 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1101 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1110 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_0_1111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_0_1111 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_0_1111 ) << std::endl;
            allResLoaded = false;
        }
        
        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0000 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0000 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0001 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0010 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0011 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0100 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0101 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0110 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_0111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_0111 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_0111 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1000, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1000 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1000 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1001, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1001 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1001 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1010, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1010 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1010 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1011, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1011 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1011 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1100, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1100 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1100 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1101, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1101 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1101 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1110, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1110 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1110 ) << std::endl;
            allResLoaded = false;
        }

        if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_1_1111, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_1_1111 ) )
        { 
            LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_1_1111 ) << std::endl;
            allResLoaded = false;
        }

        
        
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_DESERT_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_DESERT_01) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_DESERT_01 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_WATER_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_WATER_01 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_WATER_01 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_01 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_01 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_01 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_01 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_02, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_02 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_02 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_012, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_012 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_012 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_013, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_013 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_013 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_112, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_112 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_112 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_113, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_113 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_113 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_114, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_114 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_114 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_01432, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_01432 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_01432 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_11432, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_11432 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_11432 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_132, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_132 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_132 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_134, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_134 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_134 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_03, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_03 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_03 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_GRASS_DESERT_04, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_GRASS_DESERT_04 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_GRASS_DESERT_04 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_01, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_01 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_01 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_014, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_014 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_014 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_02, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_02 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_02 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_023, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_023 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_023 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_03, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_03 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_03 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_032, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_032 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_032 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_04, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_04 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_04 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_013, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_013 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_013 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_113, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_113 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_113 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_123, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_123 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_123 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_0013, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_0013 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_0013 ) << std::endl;
//             allResLoaded = false;
//         }
//         
//         if ( !ResourceManager::addTexture( TextureID::TERRAIN_TILE_BEACH_1113, PATH_TERRAIN_TEXTURES + TEXTURE_TILE_TERRAIN_BEACH_1113 ) )
//         {
//             LOG(Logger::Level::DEBUG) << "Unable to add texture resource: " << textureIDToStr( TextureID::TERRAIN_TILE_BEACH_1113 ) << std::endl;
//             allResLoaded = false;
//         }
        
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
                    
                    if (m_active)
                        peekState()->update( FRAME_TIME );
                }
            }
                        
            if (m_active)
            {
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
                m_window.draw( m_mousePointer );
                m_window.display();
            }
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
