#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "GameState.hpp"

namespace rts
{
    class MainMenuState : public GameState
    {
        
    public:
        
        typedef std::shared_ptr<MainMenuState> Ptr;
        
    public:
        MainMenuState(Game::Ptr game);
        
        ~MainMenuState();
    
    public:
        void draw(const sf::Time dt) override;

        // Update the main menu screen elements
        void update(const sf::Time dt) override;

        // React to user input
        void handleInput() override;
    };
}

#endif // MAIN_MENU_STATE_HPP
