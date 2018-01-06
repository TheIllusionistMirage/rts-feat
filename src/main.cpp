/*
 * ---------------
 *  Module : Main
 * ---------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  The entry point for the game.
 */

#include <iostream>

#include "Utility/Log.hpp"
#include "Utility/System.hpp"
#include "Game.hpp"

int main(int argc, char **argv)
{
    ///////////////////////////
    // Initialize the logger //
    ///////////////////////////
    
    try
    {
    // Output log file
    std::ofstream logFile( "rtsfeat.log", std::ios::out );
    
    // Output tee streams (log to both STDOUT and log file)
    rts::TeeStream teeStream( std::cout, logFile );
    
    // If the log file was created and can be written to,
    // log directly into the tee stream. Else log only to STDOUT        
    if ( logFile.is_open() && logFile.good() )
        rts::Logger::get().setLogStream( teeStream );
    else
        rts::Logger::get().setLogStream( std::cout );
    
    // Set the logging level
    rts::Logger::get().setLevel( rts::Logger::Level::DEBUG );
    
    LOG(rts::Logger::Level::INFO) << "Program Started..." << std::endl;
    
    // Create a game, set the initial state as main menu & start it
    rts::Game game;
    game.pushState(rts::Game::State::MAIN_MENU);
    //game.pushState(rts::Game::State::MAP_EDITOR);
    game.run();
    
    LOG(rts::Logger::Level::INFO) << "Program Ended" << std::endl;
    }
    catch( std::exception& e )
    {
        std::cout << "Exceptions Ocurred:-" << std::endl;
        std::cout << e.what() << std::endl;
    }
    
    return EXIT_SUCCESS;
}
