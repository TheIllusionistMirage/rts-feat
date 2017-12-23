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
    
    ///////////////////
    // GUI constants //
    ///////////////////
    
    const std::string WINDOW_TITLE = "rtsfeat";
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int WINDOW_BPP = 32;
    
    ////////////////
    // Frame rate //
    ////////////////
    
    const float FRAMES_PER_SECOND = 60.f;
    const sf::Time FRAME_TIME = sf::seconds(1.f / FRAMES_PER_SECOND);
}

#endif // CONSTANTS_HPP
