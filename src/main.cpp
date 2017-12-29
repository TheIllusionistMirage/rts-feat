#include <iostream>

#include "Utility/Log.hpp"
#include "Utility/System.hpp"
#include "Game.hpp"

int main(int argc, char **argv)
{
    ///////////////////////////
    // Initialize the logger //
    ///////////////////////////
    
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
    
    rts::Game game;
    game.pushState(rts::Game::State::MAIN_MENU);
    game.run();
    
    LOG(rts::Logger::Level::INFO) << "Program Ended" << std::endl;
    
    return EXIT_SUCCESS;
}
