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
            "UI_DEFAULT_COMBOBOX_ARROW"
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
