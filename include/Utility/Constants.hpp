#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

#include <SFML/System/Time.hpp>

namespace rts
{
    /////////////////////////
    // Paths & directories //
    /////////////////////////
    
    const std::string ASSETS_LOCATION = "assets/";
    const std::string TEXTURES_LOCATION = ASSETS_LOCATION + "textures/";
    const std::string FONTS_LOCATION = ASSETS_LOCATION + "fonts/";
    
    const std::string BACKGROUND_TEXTURE = "background.png";
    const std::string DEFAULT_FONT = "Default.ttf";
    const std::string DEJAVU_SERIF_FONT = "DejaVu-Serif.ttf";
    const std::string MONOSPACE_FONT = "Monospace.ttf";
    const std::string MONOSPACE_BOLD_FONT = "MonospaceBold.ttf";
    const std::string MONOSPACE_OBLIQUE_FONT = "MonospaceOblique.ttf";
    const std::string ROBOTO_BOLD_FONT = "Roboto-Bold.ttf";
    const std::string MONACO_FONT = "Monaco.ttf";
    
    ///////////////////
    // GUI constants //
    ///////////////////
    
    const std::string WINDOW_TITLE = "rtsfeat";
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int WINDOW_BPP = 32;
    
    const std::string UI_INVALID_WIDGET_ID = "UI_INVALID_WIDGET_ID";
    const std::string UI_INVALID_COMPONENT_ID = "UI_INVALID_COMPONENT_ID";
    
    const std::string UI_DEFAULT_CAPTION_COMPONENT_TEXT = "Caption";
    const int UI_DEFAULT_CAPTION_CHAR_SIZE = 10;
    
    ////////////////
    // Frame rate //
    ////////////////
    
    const float FRAMES_PER_SECOND = 60.f;
    const sf::Time FRAME_TIME = sf::seconds(1.f / FRAMES_PER_SECOND);
}

#endif // CONSTANTS_HPP
