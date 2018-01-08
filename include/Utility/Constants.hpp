/*
 * -----------------------
 *  Module    : Utility
 *  Submodule : Constants
 * -----------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains various constants hardcoded to the program. This is a
 *  temporary measure until I set things up properly by using XML
 *  files to house these info.
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

#include <SFML/System/Time.hpp>

namespace rts
{
    /////////////////////////
    // Paths & directories //
    /////////////////////////
    
    const std::string PATH_ASSETS       = "assets/";
    const std::string PATH_TEXTURES     = PATH_ASSETS   + "textures/";
    const std::string PATH_UI_TEXTURES  = PATH_TEXTURES + "ui/";
    const std::string PATH_FONTS        = PATH_ASSETS   + "fonts/";
    const std::string PATH_TERRAIN_TEXTURES  = PATH_TEXTURES + "world/terrain/";
    
    ////////////////////
    // Resource files //
    ////////////////////
    
    /* ----------
     *  Textures
     * ----------
     * 
     * All texture resources are PNG files. Exception being large images
     * such as for menu backgrounds. They're JPEG if their PNG versions
     * are way too large.
     */
    
    // Mouse pointer texture
    const std::string TEXTURE_MOUSE_POINTER = "mouse-pointer.png";
    
    // Background textures
    const std::string TEXTURE_DEFAULT_BACKGROUND    = "default-background.png";
    const std::string TEXTURE_MAIN_MENU_BACKGROUND  = "default-background.png";// "main-menu-background.jpg";
    const std::string TEXTURE_MAP_EDITOR_BACKGROUND = "map-editor-background.png";
    
    // UI Button textures
    const std::string TEXTURE_UI_DEFAULT_BUTTON   = "ui-button.png";
    const std::string TEXTURE_UI_MENU_BUTTON = "ui-button-menu.png";
    
    // UI Picture textures
    const std::string TEXTURE_UI_DEFAULT_PICTURE = "ui-picture-frame.png";
    
    // UI Radio/Check Button textures
    const std::string TEXTURE_UI_DEFAULT_RADIOBUTTON_NORMAL   = "ui-radiobutton-normal.png";
    const std::string TEXTURE_UI_DEFAULT_RADIOBUTTON_SELECTED = "ui-radiobutton-selected.png";
    
    // UI List item textures
    const std::string TEXTURE_UI_DEFAULT_LISTITEM = "ui-listitem.png";
    
    // UI Combobox textures
    const std::string TEXTURE_UI_DEFAULT_COMBOBOX_SELECTED = "ui-combobox-selected.png";
    const std::string TEXTURE_UI_DEFAULT_COMBOBOX_ARROW    = "ui-combobox-selected-arrow.png";
    
    // UI Tilebox texture
    const std::string TEXTURE_UI_TILEBOX = "ui-tilebox.png";
    
    // UI Scroll area/bar/arrow textures
    const std::string TEXTURE_UI_SCROLL_AREA       = "ui-scroll-area.png";
    const std::string TEXTURE_UI_SCROLL_BAR        = "ui-scroll-bar.png";
    const std::string TEXTURE_UI_SCROLL_ARROW_UP   = "ui-scroll-arrow-up.png";
    const std::string TEXTURE_UI_SCROLL_ARROW_DOWN = "ui-scroll-arrow-down.png";
    
    ///////////
    // Tiles //
    ///////////
    
    const std::string TEXTURE_TILE_TERRAIN_LAND_DEFAULT  = "terrain-land-default.png";
    const std::string TEXTURE_TILE_TERRAIN_WATER_DEFAULT = "terrain-water-default.png";
    
    const std::string TEXTURE_TILE_TERRAIN_GRASS_DEFAULT    = "terrain-grass-default.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_EAST       = "terrain-grass-E.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_NORTH      = "terrain-grass-N.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_NORTH_EAST = "terrain-grass-NE.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_NORTH_WEST = "terrain-grass-NW.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_SOUTH      = "terrain-grass-S.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_SOUTH_EAST = "terrain-grass-SE.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_SOUTH_WEST = "terrain-grass-SW.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_WEST       = "terrain-grass-W.png";
    
    /* ----------
     *  Fonts
     * ----------
     * 
     * All fonts used are freely available TrueType fonts.
     */
    
    // Font files
    const std::string FONT_BASKERVILLE_OLD_FACE_REGULAR  = "Baskerville-Old-Face-Regular.ttf";
    const std::string FONT_BEYOND_WONDERLAND             = "Beyond-Wonderland.ttf";
    const std::string FONT_BOOK_ANTIQUA_BOLD             = "Book-Antiqua-Bold.ttf";
    const std::string FONT_CLOISTER_BLACK_LIGHT          = "Cloister-Black-Light.ttf";
    const std::string FONT_CONSTANTIA_REGULAR            = "Constantia-Regular.ttf";
    const std::string FONT_DEFAULT                       = "Default.ttf";
    const std::string FONT_DEJAVU_SERIF_BOOK             = "Dejavu-Serif-Book.ttf";
    const std::string FONT_GARAMOND_BOLD                 = "Garamond-Bold.ttf";
    const std::string FONT_MONACO                        = "Monaco.ttf";
    const std::string FONT_OLD_SERIF_GUT_REGULAR         = "Old-Serif-Gut-Regular.ttf";
    const std::string FONT_RINGBEARER_MEDIUM             = "Ringbearer-Medium.ttf";
    const std::string FONT_ROBOTO_BOLD                   = "Roboto-Bold.ttf";
    const std::string FONT_SOURCE_HAN_SANS_CN_NORMAL     = "Source-Han-Sans-CN-Normal.otf";
    
    
    ///////////////////
    // GUI constants //
    ///////////////////
    
    // Identifiers for invalid UI entities
    const std::string UI_INVALID_WIDGET_ID = "UI_INVALID_WIDGET_ID";
    const std::string UI_INVALID_COMPONENT_ID = "UI_INVALID_COMPONENT_ID";
    const std::string UI_INVALID_STRING = "UI_INVALID_STRING";
    
    // Default character size of a Caption component
    const int UI_DEFAULT_CAPTION_CHAR_SIZE = 10;
    
    // Default texture size for a default UI button
    const int UI_DEFAULT_BUTTON_TEXTURE_WIDTH  = 30;
    const int UI_DEFAULT_BUTTON_TEXTURE_HEIGHT = 30;
    
    // Default texture size for a main menu UI button
    const int UI_MENU_BUTTON_TEXTURE_WIDTH  = 287;
    const int UI_MENU_BUTTON_TEXTURE_HEIGHT = 61;
    
    // Default texture size for a default UI picture widget
    const int UI_DEFAULT_PICTURE_TEXTURE_WIDTH  = 128;
    const int UI_DEFAULT_PICTURE_TEXTURE_HEIGHT = 64;
    
    // Default texture size for a default UI radio button
    const int UI_DEFAULT_RADIOBUTTON_TEXTURE_WIDTH  = 16;
    const int UI_DEFAULT_RADIOBUTTON_TEXTURE_HEIGHT = 16;
    
    // Default texture size for a default UI list item
    const int UI_DEFAULT_LISTITEM_TEXTURE_WIDTH  = 32;
    const int UI_DEFAULT_LISTITEM_TEXTURE_HEIGHT = 32;
    
    // Default texture size for a default UI combo box
    const int UI_COMBOBOX_SELECTED_TEXTURE_WIDTH  = 32;
    const int UI_COMBOBOX_SELECTED_TEXTURE_HEIGHT = 32;
    
    // Default texture size for a default UI combo box arrow
    const int UI_COMBOBOX_ARROW_TEXTURE_WIDTH = 15;
    const int UI_COMBOBOX_ARROW_TEXTURE_HEIGHT = 16;
    
    // Default texture size for a default UI Tilebox
    const int UI_TILEBOX_TEXTURE_WIDTH  = 30;
    const int UI_TILEBOX_TEXTURE_HEIGHT = 30;
    
    // Texture size for a default UI scroll bar/area/arrow
    const int UI_SCROLL_TEXTURE_WIDTH  = 30;
    const int UI_SCROLL_TEXTURE_HEIGHT = 30;
    
    // Default tile width & height
    const int TERRAIN_TILE_WIDTH  = 128;
    const int TERRAIN_TILE_HEIGHT = 64;

    
    ////////////////////////////
    // Default game constants //
    ////////////////////////////
    
    // Window constants
    const std::string WINDOW_TITLE = "rtsfeat";
    const int WINDOW_WIDTH         = 800;
    const int WINDOW_HEIGHT        = 600;
    const int WINDOW_BPP           = 32;
    
    // Frame rate constants
    const float    FRAMES_PER_SECOND = 60.f;
    const sf::Time FRAME_TIME        = sf::seconds( 1.f / FRAMES_PER_SECOND );
}

#endif // CONSTANTS_HPP
