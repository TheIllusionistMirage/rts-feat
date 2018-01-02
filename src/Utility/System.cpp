/*
 * --------------------
 *  Module : Utility
 *  Submodule : System
 * --------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  Contains implementation of the methods & classes declared
 *  in System submodule.
 */

#include <ctime>

#include "Utility/Log.hpp"
#include "Utility/System.hpp"

namespace rts
{
    const Time Time::now()
    {
        Time time;
        time_t now = std::time(0);
        struct tm tmstruct = *localtime(&now);
        
        time.mday = tmstruct.tm_mday;
        time.mon = tmstruct.tm_mon;
        time.year = tmstruct.tm_year + 1900;
        time.wday = tmstruct.tm_wday;
        time.hour = tmstruct.tm_hour;
        time.min = tmstruct.tm_min;
        time.sec = tmstruct.tm_sec;
        time.zone = tmstruct.tm_zone;
        
        return time;
    }
    
    const std::string Time::timestampStr( bool is24 )
    {
        Time time = now();
        //time.hour = 12;
        
        std::string timestamp = "[ " + std::to_string( time.mday ) +
                                "-" + std::to_string( time.mon ) +
                                "-" + std::to_string( time.year ) +
                                " / " + ( is24 ? std::to_string( time.hour ) : std::to_string( ( time.hour == 12 ? 1 : time.hour % 12 ) ) ) +
                                ":" + std::to_string( time.min ) +
                                ":" + std::to_string( time.sec ) +
                                ( is24 ? " HRS, " : ( time.hour < 12 ? " AM, " : " PM, " ) ) + time.zone +
                                " ]";
        return timestamp;
    }
    
    const Time Time::Invalid = Time();
    
    const std::string Time::monthStrMap[12] =
    {
        "Jan" ,
        "Feb" ,
        "Mar" ,
        "Apr" ,
        "May" ,
        "Jun" ,
        "Jul" ,
        "Aug" ,
        "Sep" ,
        "Oct" ,
        "Nov" ,
        "Dec"
    };
    
    const std::string Time::weekdayStrMap[7] =
    {
        "Sun" ,
        "Mon" ,
        "Tue" ,
        "Wed" ,
        "Thu" ,
        "Fri" ,
        "Sat"
    };
    
    Time::Time() :
     mday(0),
     mon(0),
     year(0),
     wday(0),
     hour(0),
     min(0),
     sec(0),
     zone("")
    {}
    
    bool Time::operator== ( const Time& t )
    {
        return mday == t.mday && mon == t.mon &&
                year == t.year && wday == t.wday &&
                 hour == t.hour && min == t.min &&
                  sec == t.sec && zone == t.zone;
    }
    
    const Time Time::operator- ( const Time& t)
    {
        Time time;
        return time;
    }
            
    const Time Time::operator+ ( const Time& t )
    {
        Time time;
        
        int v1 = sec + t.sec;
        time.sec = v1 % 60;
        int v2 = min + t.min;
        time.min = ( v1 / 60 + v2 ) % 60;
        int v3 = hour + t.hour;
        time.hour = ( ( v1 / 60 + v2 ) / 60 + v3 ) % 24;
        int v4 = mday + t.mday;
        time.mday = ( ( ( v1 / 60 + v2 ) / 60 + v3 ) / 24 + v4 ) % 31;
        int v5 = mon + t.mon;
        time.mon = ( ( ( ( v1 / 60 + v2 ) / 60 + v3 ) / 24 + v4 ) / 31 + v5 ) % 12;
        int v6 = year + t.year;
        time.year = ( ( ( ( v1 / 60 + v2 ) / 60 + v3 ) / 24 + v4 ) / 31 + v5 ) / 12 + v6;
        
        return time;
    }
    
    std::ostream& operator<< ( std::ostream& os, const Time& t )
    {
        os << Time::weekdayStrMap[t.wday] << " " << t.mday << " " << Time::monthStrMap[t.mon] << " " << t.year << ", " << t.hour << ":" << t.min << ":" << t.sec << " HRS, " << t.zone;
        return os;
    }
}
