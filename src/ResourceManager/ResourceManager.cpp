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
 *  Contains implementation of the methods & classes declared
 *  in ResourceManager module.
 */

#include "Utility/Log.hpp"
#include "Utility/Constants.hpp"
#include "ResourceManager/ResourceManager.hpp"

namespace rts
{
    // Initialize the texture and font maps
    
    std::map<TextureID, std::shared_ptr<sf::Texture>> ResourceManager::m_texturesHandleMap = {};
    
    std::map<FontID, std::shared_ptr<sf::Font>> ResourceManager::m_fontsHandleMap = {};
    
    
    ResourceManager::ResourceManager()
    {}

    ResourceManager::~ResourceManager()
    {}

    bool ResourceManager::addTexture(const TextureID texID, const std::string& texFile)
    {
        if (textureIDToStr(texID) == "")
        {
            LOG(Logger::Level::ERROR) << "[ FATAL ] No texture ID called: " << textureIDToStr(texID) << " exists." << std::endl;
            return false;
        }

        sf::Texture* texture = new sf::Texture();

        if (texture->loadFromFile(texFile))
            LOG(Logger::Level::DEBUG) << "Successfully loaded texture: " << textureIDToStr(texID) << std::endl;
        else
        {
            LOG(Logger::Level::ERROR) << "[ FATAL ] Unable to load texture: " << textureIDToStr(texID) << std::endl;
            return false;
        }

        m_texturesHandleMap.insert(std::make_pair(texID, std::shared_ptr<sf::Texture>(std::move(texture))));

        return true;
    }

    std::shared_ptr<sf::Texture> ResourceManager::getTexture(const TextureID texID)
    {
        if (textureIDToStr(texID) == "")
        {
            LOG(Logger::Level::ERROR) << "[ FATAL ] No texture ID called: " << textureIDToStr(texID) << " exists." << std::endl;
            return nullptr;
        }

        return m_texturesHandleMap.at(texID);
    }

    bool ResourceManager::addFont(const FontID fontID, const std::string& fontFile)
    {
        if (fontIDToStr(fontID) == "")
        {
            LOG(Logger::Level::ERROR) << "[ FATAL ] No font ID called: " << fontIDToStr(fontID) << " exists." << std::endl;
            return false;
        }

        sf::Font* font = new sf::Font();

        if (font->loadFromFile(fontFile))
            LOG(Logger::Level::DEBUG) << "Successfully loaded font: " << fontIDToStr(fontID) << std::endl;
        else
        {
            LOG(Logger::Level::ERROR) << "[ FATAL ] Unable to load font: " << fontIDToStr(fontID) << std::endl;
            return false;
        }

        m_fontsHandleMap.insert(std::make_pair(fontID, std::shared_ptr<sf::Font>(std::move(font))));

        return true;
    }

    std::shared_ptr<sf::Font> ResourceManager::getFont(const FontID fontID)
    {
        if (fontIDToStr(fontID) == "")
        {
            LOG(Logger::Level::ERROR) << "[ FATAL ] No font ID called: " << fontIDToStr(fontID) << " exists." << std::endl;
            return nullptr;
        }

        return m_fontsHandleMap.at(fontID);
    }

}
