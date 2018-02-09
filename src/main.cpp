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

//#include "TileMap/TileMap.hpp"
//#include "WorldEntities/EntityComponents/Animation.hpp"
//#include "ResourceManager/ResourceManager.hpp"

#include <gperftools/heap-profiler.h>

#define PROFILE_PREFIX "heap_profile"

int main(int argc, char **argv)
{
    ///////////////////////////
    // Initialize the logger //
    ///////////////////////////
    
//     HeapProfilerStart( PROFILE_PREFIX );
// 
//     if ( IsHeapProfilerRunning() )
//     {
//         std::cout << "Started Heap profiler" << std::endl;
//     }
//     else
//     {
//         std::cout << "Unable to start Heap profiler" << std::endl;
//     }
    
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
    
//     int* someArr = new int[1024*1024 * 100];
//     
//     static constexpr unsigned long long C_SIZE = 1024 * 1024 * 100; //1024*1024*100;
//     //std::vector<char> cLargeArr( C_SIZE );
//     std::vector<int> oLargeArr( C_SIZE );
//     
//     delete[] someArr;
    
//     static constexpr unsigned long long C_SIZE = 1024 * 1024; //1024*1024*100;
//     char cLargeArr[C_SIZE];
//     std::cin >> cLargeArr[0];
//     cLargeArr[0] = 0xff;
//     std::cout << cLargeArr[0] << std::endl;
    
    
    //printf("asdasd\n");
    //std::cin >> cLargeArr[0];
    //cLargeArr[0] = 0xff;
    //std::cout << cLargeArr[0] << std::endl;
    
    // Create a game, set the initial state as main menu & start it
    
    //char ch;
    //std::cin >> ch;
    //char* foo = new char[1024*1024*10];
    
    //sf::RenderWindow window;
    
    //std::cout << sizeof(sf::Vertex) << std::endl;
    //std::cout << sizeof(std::shared_ptr<sf::VertexArray>) << std::endl;
    
    //{
//         std::vector<std::vector<std::shared_ptr<sf::VertexArray>>> v2;
//         
//         int size= 1000;
//         v2.resize( size, std::vector<std::shared_ptr<sf::VertexArray>>( size, std::shared_ptr<sf::VertexArray>( std::make_shared<sf::VertexArray>(sf::Quads, 4) ) ) );
//         
//         v2[345][998]->getPrimitiveType();
//         
//         HeapProfilerDump( PROFILE_PREFIX );
//         std::cin >> ch;
    //}
    
//     std::vector<std::vector<std::shared_ptr<sf::VertexArray>>> v;//(sf::Quads, 4);
//     /*for ( int i = 0; i < 1000; ++i )
//     {
//         v.push_back(std::vector<std::shared_ptr<sf::VertexArray>>());
//         for (int j =0; j <1000; ++j)
//             v[i].push_back(std::make_shared<sf::VertexArray>(sf::Quads, 4));
//     }*/
//     
//     //int size= 1000;
//     v.resize( size, std::vector<std::shared_ptr<sf::VertexArray>>( size, std::shared_ptr<sf::VertexArray>( std::make_shared<sf::VertexArray>(sf::Quads, 4) ) ) );
//     //v.resize( size, std::vector<std::shared_ptr<sf::VertexArray>>( size, std::shared_ptr<sf::VertexArray>( ) ) );
//     
//     (*v[345][998])[4].position = {0,0};
    //v[999][999]->getPrimitiveType();
    //v[0][0]->getPrimitiveType();
    
    //std::cout << sizeof(std::vector<std::shared_ptr<sf::VertexArray>>) << std::endl;
    //std::cout << sizeof(std::vector<std::vector<std::shared_ptr<sf::VertexArray>>>) << std::endl;
    
    /*std::cout << sizeof(rts::WorldEntities::Tile) << std::endl;
    std::cout << sizeof(rts::WorldEntities::TileMap) << std::endl;
    std::cout << sizeof(rts::WorldEntities::EntityComponents::AnimationComponent) << std::endl;*/
    
    //rts::Game game;
//     HeapProfilerDump( PROFILE_PREFIX );
//     std::cin >> ch;
    //char ch;
    //std::cin >> ch;
    //game.pushState(rts::Game::State::MAIN_MENU);
    //game.pushState(rts::Game::State::MAP_EDITOR);
    //game.run();
    //HeapProfilerDump( PROFILE_PREFIX );
    
    //char ch;
    //std::cin >> ch;
    
    rts::Game game;
    game.pushState(rts::Game::State::MAIN_MENU);
    game.run();
    
    LOG(rts::Logger::Level::INFO) << "Program Ended" << std::endl;
    //free(foo);
    }
    catch( std::exception& e )
    {
        std::cout << "Exceptions Ocurred:-" << std::endl;
        std::cout << e.what() << std::endl;
    }
    
    /*{
    std::vector<std::vector<std::shared_ptr<sf::VertexArray>>> v2;
        
    int size= 1000;
    v2.resize( size, std::vector<std::shared_ptr<sf::VertexArray>>( size, std::shared_ptr<sf::VertexArray>( std::make_shared<sf::VertexArray>(sf::Quads, 4) ) ) );
    
    v2[345][998]->getPrimitiveType();
    
    HeapProfilerDump( PROFILE_PREFIX );
    char ch;
    std::cin >> ch;
    }
        
    HeapProfilerDump( PROFILE_PREFIX );
    
    HeapProfilerStop();*/

    //std::cin >> ch;
//     
    return EXIT_SUCCESS;
}
