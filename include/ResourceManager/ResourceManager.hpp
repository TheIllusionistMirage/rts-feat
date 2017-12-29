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
        INVALID          ,
        UI_BUTTON        ,
        UI_SCROLLBAR     ,
        UI_LISTBOX       ,
        UI_PICTURE_FRAME ,
        UI_RADIO_BUTTON_NORMAL  ,
        UI_RADIO_BUTTON_SELECTED  ,
        BACKGROUND
    };

    
    // Font IDs
    
    enum class FontID
    {
        INVALID      ,
        ROBOTO_BOLD  ,
        DEJAVU_SERIF ,
        MONOSPACE    ,
        MONACO       ,
        DEFAULT
    };

    
    // Convert a texture ID to a string
    
    static inline const std::string textureIDToStr(TextureID texID)
    {
        std::string idMap[] = { "INVALID", "UI_BUTTON", "UI_SCROLLBAR", "UI_LISTBOX", "UI_PICTURE_FRAME", "UI_RADIO_BUTTON_NORMAL", "UI_RADIO_BUTTON_SELECTED", "BACKGROUND" };

        if (texID <= TextureID::BACKGROUND)
            return idMap[static_cast<int>(texID)];

        return idMap[0]; // i.e., INVALID_TEXTURE
    }
    
    
    // Convert a font ID to a string

    static inline const std::string fontIDToStr(FontID fontID)
    {
        std::string idMap[] = { "INVALID", "ROBOTO_BOLD", "DEJAVU_SERIF", "MONOSPACE", "MONACO", "DEFAULT" };

        if (fontID <= FontID::DEFAULT)
            return idMap[static_cast<int>(fontID)];

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

        // Ge a pointer to an existin texture in the texture map
        static std::shared_ptr<sf::Texture> getTexture(const TextureID texID);

        // Insert a new font to the texture handle map
        static bool addFont(const FontID fontID, const std::string& fontFile);

        // Ge a pointer to an existing font in the texture map
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
