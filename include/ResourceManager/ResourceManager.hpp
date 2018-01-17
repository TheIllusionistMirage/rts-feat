/*
 * --------------------------
 *  Module : ResourceManager
 * --------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module manages the assets like textures, fonts, etc. needed
 *  by the game.
 * 
 */

#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <cctype>
#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace rts
{

    // Texture IDs    
    enum class TextureID
    {
        INVALID = -1                        ,
        
        // UI
        MOUSE_POINTER                       ,
        DEFAULT_BACKGROUND                  ,
        MAIN_MENU_BACKGROUND                ,
        MAP_EDITOR_BACKGROUND               ,
        UI_DEFAULT_BUTTON                   ,
        UI_MENU_BUTTON                      ,
        UI_DEFAULT_PICTURE                  ,
        UI_DEFAULT_RADIOBUTTON_NORMAL       ,
        UI_DEFAULT_RADIOBUTTON_SELECTED     ,
        UI_DEFAULT_LISTITEM                 ,
        UI_DEFAULT_COMBOBOX_SELECTED        ,
        UI_DEFAULT_COMBOBOX_ARROW           ,
        UI_TILEBOX                          ,
        UI_SCROLL_AREA                      ,
        UI_SCROLL_BAR                       ,
        UI_SCROLL_ARROW_UP                  ,
        UI_SCROLL_ARROW_DOWN                ,
        
        // TERRAIN
        TERRAIN_TILE_LAND_DEFAULT,
        TERRAIN_TILE_GRASS_DEFAULT,
        TERRAIN_TILE_WATER_DEFAULT,
        TERRAIN_ANIMATED_TILE_WATER_DEFAULT,
        TERRAIN_TILE_LAND_NORTH,
        TERRAIN_TILE_LAND_EAST,
        TERRAIN_TILE_LAND_SOUTH,
        TERRAIN_TILE_LAND_WEST,
        TERRAIN_TILE_LAND_NORTH_EAST,
        TERRAIN_TILE_LAND_SOUTH_EAST,
        TERRAIN_TILE_LAND_SOUTH_WEST,
        TERRAIN_TILE_LAND_NORTH_WEST,
        TERRAIN_TILE_LAND_01,
        TERRAIN_TILE_LAND_02,
        TERRAIN_TILE_LAND_03,
        TERRAIN_TILE_LAND_04,
        TERRAIN_TILE_LAND_05,
        TERRAIN_TILE_LAND_06,
        TERRAIN_TILE_LAND_WATER_01,
        TERRAIN_TILE_LAND_WATER_02,
        TERRAIN_TILE_LAND_WATER_03,
        TERRAIN_TILE_LAND_WATER_04,
        TERRAIN_TILE_LAND_WATER_05,
        TERRAIN_TILE_LAND_WATER_06,
        TERRAIN_TILE_LAND_WATER_07,
        TERRAIN_TILE_LAND_WATER_08,
        TERRAIN_TILE_LAND_WATER_09,
        TERRAIN_TILE_LAND_WATER_10,
        TERRAIN_TILE_LAND_WATER_11,
        TERRAIN_TILE_LAND_WATER_12,
        TERRAIN_TILE_LAND_WATER_13,
        TERRAIN_TILE_LAND_WATER_14,
        TERRAIN_TILE_LAND_WATER_15,
        TERRAIN_TILE_LAND_WATER_16,
        TERRAIN_TILE_LAND_WATER_17,
        TERRAIN_TILE_LAND_WATER_18,
        TERRAIN_TILE_LAND_WATER_19,
        TERRAIN_TILE_LAND_WATER_20,
        TERRAIN_TILE_LAND_WATER_21,
        TERRAIN_TILE_LAND_WATER_22,
        TERRAIN_TILE_LAND_WATER_23,
        TERRAIN_TILE_LAND_WATER_24,
        TERRAIN_TILE_LAND_WATER_25,
        TERRAIN_TILE_LAND_WATER_26,
        TERRAIN_TILE_LAND_WATER_27,
        TERRAIN_TILE_LAND_WATER_28,
        TERRAIN_TILE_LAND_WATER_29,
        TERRAIN_TILE_LAND_WATER_30,
        TERRAIN_TILE_LAND_WATER_31,
        TERRAIN_TILE_LAND_WATER_32,
        TERRAIN_TILE_LAND_WATER_33,
        TERRAIN_TILE_LAND_WATER_34,
        TERRAIN_TILE_LAND_WATER_35,
        TERRAIN_TILE_LAND_WATER_36,
        TERRAIN_TILE_LAND_WATER_37,
        TERRAIN_TILE_LAND_WATER_38,
        TERRAIN_TILE_LAND_WATER_39,
        TERRAIN_TILE_LAND_WATER_40,
        TERRAIN_TILE_LAND_WATER_41,
        TERRAIN_TILE_LAND_WATER_42,
        TERRAIN_TILE_LAND_WATER_43,
        TERRAIN_TILE_LAND_WATER_44,
        TERRAIN_TILE_LAND_WATER_45,
        TERRAIN_TILE_LAND_WATER_46,
        TERRAIN_TILE_LAND_WATER_47,
        TERRAIN_TILE_LAND_WATER_48,
        TERRAIN_TILE_LAND_WATER_49,
        TERRAIN_TILE_LAND_WATER_50,
        TERRAIN_TILE_LAND_WATER_51,
        TERRAIN_TILE_LAND_WATER_52,
        TERRAIN_TILE_LAND_WATER_53,
        TERRAIN_TILE_LAND_WATER_54,
        TERRAIN_TILE_LAND_WATER_55,
        TERRAIN_TILE_LAND_WATER_56,
        TERRAIN_TILE_LAND_WATER_57,
        TERRAIN_TILE_LAND_WATER_58,
        TERRAIN_TILE_LAND_WATER_59,
        TERRAIN_TILE_LAND_WATER_60,
        TERRAIN_TILE_LAND_WATER_61,
        TERRAIN_TILE_LAND_WATER_62,
        TERRAIN_TILE_LAND_WATER_63,
        TERRAIN_TILE_LAND_WATER_64,
        TERRAIN_TILE_LAND_WATER_65,
        TERRAIN_TILE_LAND_WATER_66,
        
        MAX_TEXTURES
    };

    
    // Font IDs    
    enum class FontID
    {
        INVALID = -1                    ,
        DEFAULT                         ,
        BASKERVILLE_OLD_FACE_REGULAR    ,
        BEYOND_WONDERLAND               ,
        BOOK_ANTIQUA_BOLD               ,
        CLOISTER_BLACK_LIGHT            ,
        CONSTANTIA_REGULAR              ,
        DEJAVU_SERIF_BOOK               ,
        GARAMOND_BOLD                   ,
        MONACO                          ,
        OLD_SERIF_GUT_REGULAR           ,
        RINGBEARER_MEDIUM               ,
        ROBOTO_BOLD                     ,
        SOURCE_HAN_SANS_CN_NORMAL       ,
        MAX_FONTS
    };

    
    // Convert a texture ID to a string
    
    static inline const std::string textureIDToStr( TextureID texID )
    {
        static const std::string idMap[] =
        {
            //"INVALID"                             ,
            "MOUSE_POINTER"                       ,
            "DEFAULT_BACKGROUND"                  ,
            "MAIN_MENU_BACKGROUND"                ,
            "MAP_EDITOR_BACKGROUND"               ,
            "UI_DEFAULT_BUTTON"                   ,
            "UI_MENU_BUTTON"                      ,
            "UI_DEFAULT_PICTURE"                  ,
            "UI_DEFAULT_RADIOBUTTON_NORMAL"       ,
            "UI_DEFAULT_RADIOBUTTON_SELECTED"     ,
            "UI_DEFAULT_LISTITEM"                 ,
            "UI_DEFAULT_COMBOBOX_SELECTED"        ,
            "UI_DEFAULT_COMBOBOX_ARROW"           ,
            "UI_TILEBOX"                          ,
            "UI_SCROLL_AREA"                      ,
            "UI_SCROLL_BAR"                       ,
            "UI_SCROLL_ARROW_UP"                  ,
            "UI_SCROLL_ARROW_DOWN"                ,
            "TERRAIN_TILE_LAND_DEFAULT"           ,
            "TERRAIN_TILE_GRASS_DEFAULT"          ,
            "TERRAIN_TILE_WATER_DEFAULT"          ,
            "TERRAIN_ANIMATED_TILE_WATER_DEFAULT" ,
            "TERRAIN_TILE_LAND_NORTH"             ,
            "TERRAIN_TILE_LAND_EAST"              ,
            "TERRAIN_TILE_LAND_SOUTH"             ,
            "TERRAIN_TILE_LAND_WEST"              ,
            "TERRAIN_TILE_LAND_NORTH_EAST"        ,
            "TERRAIN_TILE_LAND_SOUTH_EAST"        ,
            "TERRAIN_TILE_LAND_SOUTH_WEST"        ,
            "TERRAIN_TILE_LAND_NORTH_WEST"        ,
            "TERRAIN_TILE_LAND_01",
            "TERRAIN_TILE_LAND_02",
            "TERRAIN_TILE_LAND_03",
            "TERRAIN_TILE_LAND_04",
            "TERRAIN_TILE_LAND_05",
            "TERRAIN_TILE_LAND_06",
            "TERRAIN_TILE_LAND_WATER_01",
            "TERRAIN_TILE_LAND_WATER_02",
            "TERRAIN_TILE_LAND_WATER_03",
            "TERRAIN_TILE_LAND_WATER_04",
            "TERRAIN_TILE_LAND_WATER_05",
            "TERRAIN_TILE_LAND_WATER_06",
            "TERRAIN_TILE_LAND_WATER_07",
            "TERRAIN_TILE_LAND_WATER_08",
            "TERRAIN_TILE_LAND_WATER_09",
            "TERRAIN_TILE_LAND_WATER_10",
            "TERRAIN_TILE_LAND_WATER_11",
            "TERRAIN_TILE_LAND_WATER_12",
            "TERRAIN_TILE_LAND_WATER_13",
            "TERRAIN_TILE_LAND_WATER_14",
            "TERRAIN_TILE_LAND_WATER_15",
            "TERRAIN_TILE_LAND_WATER_16",
            "TERRAIN_TILE_LAND_WATER_17",
            "TERRAIN_TILE_LAND_WATER_18",
            "TERRAIN_TILE_LAND_WATER_19",
            "TERRAIN_TILE_LAND_WATER_20",
            "TERRAIN_TILE_LAND_WATER_21",
            "TERRAIN_TILE_LAND_WATER_22",
            "TERRAIN_TILE_LAND_WATER_23",
            "TERRAIN_TILE_LAND_WATER_24",
            "TERRAIN_TILE_LAND_WATER_25",
            "TERRAIN_TILE_LAND_WATER_26",
            "TERRAIN_TILE_LAND_WATER_27",
            "TERRAIN_TILE_LAND_WATER_28",
            "TERRAIN_TILE_LAND_WATER_29",
            "TERRAIN_TILE_LAND_WATER_30",
            "TERRAIN_TILE_LAND_WATER_31",
            "TERRAIN_TILE_LAND_WATER_32",
            "TERRAIN_TILE_LAND_WATER_33",
            "TERRAIN_TILE_LAND_WATER_34",
            "TERRAIN_TILE_LAND_WATER_35",
            "TERRAIN_TILE_LAND_WATER_36",
            "TERRAIN_TILE_LAND_WATER_37",
            "TERRAIN_TILE_LAND_WATER_38",
            "TERRAIN_TILE_LAND_WATER_39",
            "TERRAIN_TILE_LAND_WATER_40",
            "TERRAIN_TILE_LAND_WATER_41",
            "TERRAIN_TILE_LAND_WATER_42",
            "TERRAIN_TILE_LAND_WATER_43",
            "TERRAIN_TILE_LAND_WATER_44",
            "TERRAIN_TILE_LAND_WATER_45",
            "TERRAIN_TILE_LAND_WATER_46",
            "TERRAIN_TILE_LAND_WATER_47",
            "TERRAIN_TILE_LAND_WATER_48",
            "TERRAIN_TILE_LAND_WATER_49",
            "TERRAIN_TILE_LAND_WATER_50",
            "TERRAIN_TILE_LAND_WATER_51",
            "TERRAIN_TILE_LAND_WATER_52",
            "TERRAIN_TILE_LAND_WATER_53",
            "TERRAIN_TILE_LAND_WATER_54",
            "TERRAIN_TILE_LAND_WATER_55",
            "TERRAIN_TILE_LAND_WATER_56",
            "TERRAIN_TILE_LAND_WATER_57",
            "TERRAIN_TILE_LAND_WATER_58",
            "TERRAIN_TILE_LAND_WATER_59",
            "TERRAIN_TILE_LAND_WATER_60",
            "TERRAIN_TILE_LAND_WATER_61",
            "TERRAIN_TILE_LAND_WATER_62",
            "TERRAIN_TILE_LAND_WATER_63",
            "TERRAIN_TILE_LAND_WATER_64",
            "TERRAIN_TILE_LAND_WATER_65",
            "TERRAIN_TILE_LAND_WATER_66",
        };

        if ( texID >= TextureID::INVALID && texID < TextureID::MAX_TEXTURES )
            return idMap[static_cast<int>( texID )];

        return idMap[0]; // i.e., INVALID_TEXTURE
    }
    
    
    // Convert a font ID to a string

    static inline const std::string fontIDToStr( FontID fontID )
    {
        static const std::string idMap[] =
        {
            //"INVALID"                    ,
            "DEFAULT"                         ,
            "BASKERVILLE_OLD_FACE_REGULAR"    ,
            "BEYOND_WONDERLAND"               ,
            "BOOK_ANTIQUA_BOLD"               ,
            "CLOISTER_BLACK_LIGHT"            ,
            "CONSTANTIA_REGULAR"              ,
            "DEJAVU_SERIF_BOOK"               ,
            "GARAMOND_BOLD"                   ,
            "MONACO"                          ,
            "OLD_SERIF_GUT_REGULAR"           ,
            "RINGBEARER_MEDIUM"               ,
            "ROBOTO_BOLD"                     ,
            "SOURCE_HAN_SANS_CN_NORMAL"       ,
            "MAX_FONTS"
        };

        if ( fontID >= FontID::INVALID && fontID < FontID::MAX_FONTS )
            return idMap[static_cast<int>( fontID )];

        return idMap[0]; // i.e., INVALID
    }

    
    // This is a static class, i.e., it has some static resource maps
    // for storing various types of resources and static methods to
    // manipulate them without object creation.
    
    class ResourceManager
    {

        public:
            
            // Insert a new texture to the texture handle map
            static bool addTexture(const TextureID texID, const std::string& texFile);

            // Get a pointer to an existin texture in the texture map
            static std::shared_ptr<sf::Texture> getTexture(const TextureID texID);

            // Insert a new font to the texture handle map
            static bool addFont(const FontID fontID, const std::string& fontFile);

            // Get a pointer to an existing font in the texture map
            static std::shared_ptr<sf::Font> getFont(const FontID fontID);

        private:
            
            // Disallow creation/destruction of ResourceManager objects
            
            ResourceManager();

            ~ResourceManager();
            
        private:

            // The texture map
            static std::map<TextureID, std::shared_ptr<sf::Texture>> m_texturesHandleMap;

            // The font map
            static std::map<FontID, std::shared_ptr<sf::Font>> m_fontsHandleMap;
    };

}

#endif // RESOURCE_MANAGER_HPP
