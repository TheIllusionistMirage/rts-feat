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
    const std::string TEXTURE_MAIN_MENU_BACKGROUND  = "main-menu-background.jpg";
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
    
    const std::string TEXTURE_TILE_TERRAIN_WATER_01  = "water-01.png";
    
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0000  = "grassland-tile-0-0000.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0001  = "grassland-tile-0-0001.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0010  = "grassland-tile-0-0010.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0011  = "grassland-tile-0-0011.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0100  = "grassland-tile-0-0100.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0101  = "grassland-tile-0-0101.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0110  = "grassland-tile-0-0110.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_0111  = "grassland-tile-0-0111.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1000  = "grassland-tile-0-1000.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1001  = "grassland-tile-0-1001.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1010  = "grassland-tile-0-1010.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1011  = "grassland-tile-0-1011.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1100  = "grassland-tile-0-1100.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1101  = "grassland-tile-0-1101.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1110  = "grassland-tile-0-1110.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_0_1111  = "grassland-tile-0-1111.png";
    
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0000  = "grassland-tile-1-0000.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0001  = "grassland-tile-1-0001.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0010  = "grassland-tile-1-0010.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0011  = "grassland-tile-1-0011.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0100  = "grassland-tile-1-0100.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0101  = "grassland-tile-1-0101.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0110  = "grassland-tile-1-0110.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_0111  = "grassland-tile-1-0111.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1000  = "grassland-tile-1-1000.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1001  = "grassland-tile-1-1001.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1010  = "grassland-tile-1-1010.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1011  = "grassland-tile-1-1011.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1100  = "grassland-tile-1-1100.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1101  = "grassland-tile-1-1101.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1110  = "grassland-tile-1-1110.png";
    const std::string TEXTURE_TILE_TERRAIN_GRASS_1_1111  = "grassland-tile-1-1111.png";
    
//     const std::string TEXTURE_TILE_TERRAIN_DESERT_01 = "desert-01.png";
//     
//     const std::string TEXTURE_TILE_TERRAIN_WATER_01  = "water-01.png";
//     
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_01  = "grass-01.png";    
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_01  = "grass-desert-01.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_02  = "grass-desert-02.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_012  = "grass-desert-012.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_013  = "grass-desert-013.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_112  = "grass-desert-112.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_113  = "grass-desert-113.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_114  = "grass-desert-114.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_01432  = "grass-desert-01432.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_11432  = "grass-desert-11432.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_132  = "grass-desert-132.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_134  = "grass-desert-134.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_03  = "grass-desert-03.png";
//     const std::string TEXTURE_TILE_TERRAIN_GRASS_DESERT_04  = "grass-desert-04.png";
//     
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_01  = "beach-01.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_014 = "beach-014.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_02  = "beach-02.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_023  = "beach-023.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_03  = "beach-03.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_032  = "beach-032.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_04  = "beach-04.png";
//     
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_013  = "beach-013.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_113  = "beach-113.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_123  = "beach-123.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_0013  = "beach-0013.png";
//     const std::string TEXTURE_TILE_TERRAIN_BEACH_1113  = "beach-1113.png";
    
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
    const int WINDOW_WIDTH         = 1366;
    const int WINDOW_HEIGHT        = 768;
    const int WINDOW_BPP           = 32;
    
    // Frame rate constants
    const float    FRAMES_PER_SECOND = 60.f;
    const sf::Time FRAME_TIME        = sf::seconds( 1.f / FRAMES_PER_SECOND );
}

#endif // CONSTANTS_HPP
