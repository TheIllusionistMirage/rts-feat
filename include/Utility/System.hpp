/*
 * ---------------------
 *  Module    : Utility
 *  Submodule : System
 * ---------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains Various classes & methods for system related tasks, such
 *  as fetching time etc.
 */

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

namespace rts
{
    // API for dealing with system time, timestamps, dates
    class Time
    {
        public:
            
            /* Returns the current system time */
            static const Time now();
            
            /* Returns the system timestamp for logging purposes */
            static const std::string timestampStr( bool is24 = true );
            
        public:
            
            static const Time Invalid;
            
            /* Month string map */            
            static const std::string monthStrMap[12];
            
            /* Week day string map */            
            static const std::string weekdayStrMap[7];
                    
        public:
            
            /* Default constructor */
            Time();
            
            /* Equality operator, returns TRUE if both the Time objects
             * represent the same time instance */
            bool operator== ( const Time& t );
            
            /* Return the (absolute) difference between two timestamps */
            const Time operator- ( const Time& t);
            
            /* Return the sum of two timestamps */
            const Time operator+ ( const Time& t );
            
            /* Print the Time directly to an output stream */
            friend std::ostream& operator<< ( std::ostream& os, const Time& t );
                
        //private:
        public:
        
            int mday; // 1-31
            int mon;  // 1-12
            int year; // YYYY
            int wday; // 0-6
            int hour; // 0-23
            int min;  // 0-59
            int sec;  // 0-59
            std::string zone; // 
    };
    
    ////////////////////
    // String helpers //
    ////////////////////
    
    /* Check if a std::string object consists of only whitespace chars */
    inline bool isStrWS( const std::string& str )
    {
        for ( auto&& c : str )
            if ( !isspace(c) )
                return false;
        return true;
    }
}

#endif // SYSTEM_HPP
