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
        
        TERRAIN_TILE_WATER_01,
        TERRAIN_TILE_GRASS_0_0000,
                
        TERRAIN_TILE_GRASS_0_0001           ,
        TERRAIN_TILE_GRASS_0_0010           ,
        TERRAIN_TILE_GRASS_0_0011           ,
        TERRAIN_TILE_GRASS_0_0100           ,
        TERRAIN_TILE_GRASS_0_0101           ,
        TERRAIN_TILE_GRASS_0_0110           ,
        TERRAIN_TILE_GRASS_0_0111           ,
        TERRAIN_TILE_GRASS_0_1000           ,
        TERRAIN_TILE_GRASS_0_1001           ,
        TERRAIN_TILE_GRASS_0_1010           ,
        TERRAIN_TILE_GRASS_0_1011           ,
        TERRAIN_TILE_GRASS_0_1100           ,
        TERRAIN_TILE_GRASS_0_1101           ,
        TERRAIN_TILE_GRASS_0_1110           ,
        TERRAIN_TILE_GRASS_0_1111           ,
        
        TERRAIN_TILE_GRASS_1_0000           ,
        TERRAIN_TILE_GRASS_1_0001           ,
        TERRAIN_TILE_GRASS_1_0010           ,
        TERRAIN_TILE_GRASS_1_0011           ,
        TERRAIN_TILE_GRASS_1_0100           ,
        TERRAIN_TILE_GRASS_1_0101           ,
        TERRAIN_TILE_GRASS_1_0110           ,
        TERRAIN_TILE_GRASS_1_0111           ,
        TERRAIN_TILE_GRASS_1_1000           ,
        TERRAIN_TILE_GRASS_1_1001           ,
        TERRAIN_TILE_GRASS_1_1010           ,
        TERRAIN_TILE_GRASS_1_1011           ,
        TERRAIN_TILE_GRASS_1_1100           ,
        TERRAIN_TILE_GRASS_1_1101           ,
        TERRAIN_TILE_GRASS_1_1110           ,
        TERRAIN_TILE_GRASS_1_1111           ,
        
        TERRAIN_TILE_DESERT_0_0000           ,
        TERRAIN_TILE_DESERT_0_0001           ,
        TERRAIN_TILE_DESERT_0_0010           ,
        TERRAIN_TILE_DESERT_0_0011           ,
        TERRAIN_TILE_DESERT_0_0100           ,
        TERRAIN_TILE_DESERT_0_0101           ,
        TERRAIN_TILE_DESERT_0_0110           ,
        TERRAIN_TILE_DESERT_0_0111           ,
        TERRAIN_TILE_DESERT_0_1000           ,
        TERRAIN_TILE_DESERT_0_1001           ,
        TERRAIN_TILE_DESERT_0_1010           ,
        TERRAIN_TILE_DESERT_0_1011           ,
        TERRAIN_TILE_DESERT_0_1100           ,
        TERRAIN_TILE_DESERT_0_1101           ,
        TERRAIN_TILE_DESERT_0_1110           ,
        TERRAIN_TILE_DESERT_0_1111           ,
        
        TERRAIN_TILE_DESERT_1_0000           ,
        TERRAIN_TILE_DESERT_1_0001           ,
        TERRAIN_TILE_DESERT_1_0010           ,
        TERRAIN_TILE_DESERT_1_0011           ,
        TERRAIN_TILE_DESERT_1_0100           ,
        TERRAIN_TILE_DESERT_1_0101           ,
        TERRAIN_TILE_DESERT_1_0110           ,
        TERRAIN_TILE_DESERT_1_0111           ,
        TERRAIN_TILE_DESERT_1_1000           ,
        TERRAIN_TILE_DESERT_1_1001           ,
        TERRAIN_TILE_DESERT_1_1010           ,
        TERRAIN_TILE_DESERT_1_1011           ,
        TERRAIN_TILE_DESERT_1_1100           ,
        TERRAIN_TILE_DESERT_1_1101           ,
        TERRAIN_TILE_DESERT_1_1110           ,
        TERRAIN_TILE_DESERT_1_1111           ,
        
        
//         TERRAIN_TILE_DESERT_01,
//         
//         TERRAIN_TILE_WATER_01,
//         
//         TERRAIN_TILE_GRASS_01,
//         TERRAIN_TILE_GRASS_DESERT_01,
//         TERRAIN_TILE_GRASS_DESERT_02,
//         TERRAIN_TILE_GRASS_DESERT_012,
//         TERRAIN_TILE_GRASS_DESERT_013,
//         TERRAIN_TILE_GRASS_DESERT_112,
//         TERRAIN_TILE_GRASS_DESERT_113,
//         TERRAIN_TILE_GRASS_DESERT_114,
//         TERRAIN_TILE_GRASS_DESERT_01432,
//         TERRAIN_TILE_GRASS_DESERT_11432,
//         TERRAIN_TILE_GRASS_DESERT_132,
//         TERRAIN_TILE_GRASS_DESERT_134,
//         TERRAIN_TILE_GRASS_DESERT_03,
//         TERRAIN_TILE_GRASS_DESERT_04,
//         
//         TERRAIN_TILE_BEACH_01,
//         TERRAIN_TILE_BEACH_014,
//         TERRAIN_TILE_BEACH_02,
//         TERRAIN_TILE_BEACH_023,
//         TERRAIN_TILE_BEACH_03,
//         TERRAIN_TILE_BEACH_032,
//         TERRAIN_TILE_BEACH_04,
//         
//         TERRAIN_TILE_BEACH_013,
//         TERRAIN_TILE_BEACH_113,
//         TERRAIN_TILE_BEACH_123,
//         TERRAIN_TILE_BEACH_0013,
//         TERRAIN_TILE_BEACH_1113,
        
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
    
    enum class TerrainType
    {
        WATER,
        GRASS,
        DESERT,
        NON_TERRAIN_TEXTURE
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
            
            "TERRAIN_TILE_WATER_01"               ,
            
            "TERRAIN_TILE_GRASS_0_0000"           ,
            "TERRAIN_TILE_GRASS_0_0001"           ,
            "TERRAIN_TILE_GRASS_0_0010"           ,
            "TERRAIN_TILE_GRASS_0_0011"           ,
            "TERRAIN_TILE_GRASS_0_0100"           ,
            "TERRAIN_TILE_GRASS_0_0101"           ,
            "TERRAIN_TILE_GRASS_0_0110"           ,
            "TERRAIN_TILE_GRASS_0_0111"           ,
            "TERRAIN_TILE_GRASS_0_1000"           ,
            "TERRAIN_TILE_GRASS_0_1001"           ,
            "TERRAIN_TILE_GRASS_0_1010"           ,
            "TERRAIN_TILE_GRASS_0_1011"           ,
            "TERRAIN_TILE_GRASS_0_1100"           ,
            "TERRAIN_TILE_GRASS_0_1101"           ,
            "TERRAIN_TILE_GRASS_0_1110"           ,
            "TERRAIN_TILE_GRASS_0_1111"           ,
            
            "TERRAIN_TILE_GRASS_1_0000"           ,
            "TERRAIN_TILE_GRASS_1_0001"           ,
            "TERRAIN_TILE_GRASS_1_0010"           ,
            "TERRAIN_TILE_GRASS_1_0011"           ,
            "TERRAIN_TILE_GRASS_1_0100"           ,
            "TERRAIN_TILE_GRASS_1_0101"           ,
            "TERRAIN_TILE_GRASS_1_0110"           ,
            "TERRAIN_TILE_GRASS_1_0111"           ,
            "TERRAIN_TILE_GRASS_1_1000"           ,
            "TERRAIN_TILE_GRASS_1_1001"           ,
            "TERRAIN_TILE_GRASS_1_1010"           ,
            "TERRAIN_TILE_GRASS_1_1011"           ,
            "TERRAIN_TILE_GRASS_1_1100"           ,
            "TERRAIN_TILE_GRASS_1_1101"           ,
            "TERRAIN_TILE_GRASS_1_1110"           ,
            "TERRAIN_TILE_GRASS_1_1111"           ,
            
            "TERRAIN_TILE_DESERT_0_0000"           ,
            "TERRAIN_TILE_DESERT_0_0001"           ,
            "TERRAIN_TILE_DESERT_0_0010"           ,
            "TERRAIN_TILE_DESERT_0_0011"           ,
            "TERRAIN_TILE_DESERT_0_0100"           ,
            "TERRAIN_TILE_DESERT_0_0101"           ,
            "TERRAIN_TILE_DESERT_0_0110"           ,
            "TERRAIN_TILE_DESERT_0_0111"           ,
            "TERRAIN_TILE_DESERT_0_1000"           ,
            "TERRAIN_TILE_DESERT_0_1001"           ,
            "TERRAIN_TILE_DESERT_0_1010"           ,
            "TERRAIN_TILE_DESERT_0_1011"           ,
            "TERRAIN_TILE_DESERT_0_1100"           ,
            "TERRAIN_TILE_DESERT_0_1101"           ,
            "TERRAIN_TILE_DESERT_0_1110"           ,
            "TERRAIN_TILE_DESERT_0_1111"           ,
            
            "TERRAIN_TILE_DESERT_1_0000"           ,
            "TERRAIN_TILE_DESERT_1_0001"           ,
            "TERRAIN_TILE_DESERT_1_0010"           ,
            "TERRAIN_TILE_DESERT_1_0011"           ,
            "TERRAIN_TILE_DESERT_1_0100"           ,
            "TERRAIN_TILE_DESERT_1_0101"           ,
            "TERRAIN_TILE_DESERT_1_0110"           ,
            "TERRAIN_TILE_DESERT_1_0111"           ,
            "TERRAIN_TILE_DESERT_1_1000"           ,
            "TERRAIN_TILE_DESERT_1_1001"           ,
            "TERRAIN_TILE_DESERT_1_1010"           ,
            "TERRAIN_TILE_DESERT_1_1011"           ,
            "TERRAIN_TILE_DESERT_1_1100"           ,
            "TERRAIN_TILE_DESERT_1_1101"           ,
            "TERRAIN_TILE_DESERT_1_1110"           ,
            "TERRAIN_TILE_DESERT_1_1111"           
            

//             "TERRAIN_TILE_DESERT_01"              ,
//             
//             "TERRAIN_TILE_WATER_01"               ,
//             
//             "TERRAIN_TILE_GRASS_01"               ,
//             "TERRAIN_TILE_GRASS_DESERT_01"        ,
//             "TERRAIN_TILE_GRASS_DESERT_02"        ,
//             "TERRAIN_TILE_GRASS_DESERT_012"       ,
//             "TERRAIN_TILE_GRASS_DESERT_013"       ,
//             "TERRAIN_TILE_GRASS_DESERT_112"       ,
//             "TERRAIN_TILE_GRASS_DESERT_113"       ,
//             "TERRAIN_TILE_GRASS_DESERT_114"       ,
//             "TERRAIN_TILE_GRASS_DESERT_01432"     ,
//             "TERRAIN_TILE_GRASS_DESERT_11432"     ,
//             "TERRAIN_TILE_GRASS_DESERT_132"       ,
//             "TERRAIN_TILE_GRASS_DESERT_134"       ,
//             "TERRAIN_TILE_GRASS_DESERT_03"        ,
//             "TERRAIN_TILE_GRASS_DESERT_04"        ,
//             
//             "TERRAIN_TILE_BEACH_01"               ,
//             "TERRAIN_TILE_BEACH_014"              ,
//             "TERRAIN_TILE_BEACH_02"               ,
//             "TERRAIN_TILE_BEACH_023"              ,
//             "TERRAIN_TILE_BEACH_03"               ,
//             "TERRAIN_TILE_BEACH_032"              ,
//             "TERRAIN_TILE_BEACH_04"               ,
//             
//             "TERRAIN_TILE_BEACH_013"              ,
//             "TERRAIN_TILE_BEACH_113"              ,
//             "TERRAIN_TILE_BEACH_123"              ,
//             "TERRAIN_TILE_BEACH_0013"             ,
//             "TERRAIN_TILE_BEACH_1113"             
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
    
    // Determine whether a texture is animated or not
    static inline bool isAnimatedTexture( TextureID texID )
    {
        static const std::map<TextureID, bool> animatedTextureMap =
        {
            { TextureID::TERRAIN_TILE_WATER_01, true}
        };
        
        return animatedTextureMap.find( texID ) != animatedTextureMap.end();
    }
    
    // Determine the type of a terrain texture
    static inline TerrainType getTerrainType( TextureID texID )
    {
        static const std::map<TextureID, TerrainType> terrainTypeMap =
        {
            { TextureID::TERRAIN_TILE_WATER_01, TerrainType::WATER } ,
            
            { TextureID::TERRAIN_TILE_GRASS_0_0000, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_0001, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_0010, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_0011, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_0100, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_0101, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_0110, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_0111, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1000, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1001, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1010, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1011, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1100, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1101, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1110, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_0_1111, TerrainType::GRASS },
            
            { TextureID::TERRAIN_TILE_GRASS_1_0000, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_0001, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_0010, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_0011, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_0100, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_0101, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_0110, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_0111, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1000, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1001, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1010, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1011, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1100, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1101, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1110, TerrainType::GRASS },
            { TextureID::TERRAIN_TILE_GRASS_1_1111, TerrainType::GRASS },
            
            { TextureID::TERRAIN_TILE_GRASS_0_0000, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_0001, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_0010, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_0011, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_0100, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_0101, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_0110, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_0111, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1000, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1001, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1010, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1011, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1100, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1101, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1110, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_GRASS_0_1111, TerrainType::DESERT },
            
            { TextureID::TERRAIN_TILE_DESERT_0_0000, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_0001, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_0010, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_0011, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_0100, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_0101, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_0110, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_0111, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1000, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1001, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1010, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1011, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1100, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1101, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1110, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_0_1111, TerrainType::DESERT },
            
            { TextureID::TERRAIN_TILE_DESERT_1_0000, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_0001, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_0010, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_0011, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_0100, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_0101, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_0110, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_0111, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1000, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1001, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1010, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1011, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1100, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1101, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1110, TerrainType::DESERT },
            { TextureID::TERRAIN_TILE_DESERT_1_1111, TerrainType::DESERT }
        };
        
        auto it = terrainTypeMap.find( texID );
        if ( it != terrainTypeMap.end() )
        {
            return it->second;
        }
        
        std::cout << "!!!\n";
        return TerrainType::NON_TERRAIN_TEXTURE;
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
