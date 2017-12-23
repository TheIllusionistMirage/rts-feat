/*
 * Logging module
 * 
 * Provides basic logging capabilites to the system.
 * Three logging levels are supported - Debug, Info
 * and Error.
 */

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <cstring>

/**
* Fetch the filename which invokes the logger
*/
// Courtesy: StackOverflow, of course
// (http://stackoverflow.com/a/8488201)
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/**
 * Macro to log error/info/debug messages
 */
#define LOG(level) \
    if (level > rts::Logger::get().getLevel()) ;        \
else rts::Logger::get().getStream() << rts::Logger::levelStr(level) \
                                     << "[ rts:"         \
                                     << __FILENAME__     \
                                     << ":" << std::dec  \
                                     << __LINE__ << " ] "

namespace rts
{
    /**
     * @brief Logger class that 
     */
    class Logger
    {
        public:
            
            /**
            * Log levels enum
            */
            enum Level
            {
                ERROR , /** <b>ERROR</b> - Log error messages only */
                INFO  , /** <b>INFO</b> - Log error and info messages only */
                DEBUG   /** <b>DEBUG</b> - Log error, info and debug messages */
            };
            
            /**
            * Convert the enum value of a level to a human readable
            * string.
            */
            static inline const std::string levelStr(Level lvl)
            {
                std::string levelMap[] = { "[ ERROR ]", "[ INFO  ]", "[ DEBUG ]" };

                auto index = static_cast<int>(lvl);

                if (index <= Level::DEBUG)
                    return levelMap[index];

                return "";
            }
            
        public:
            
            ~Logger();
            void setLogStream(std::ostream& stream);
            Logger& setLevel(Level level);
            Level getLevel();

            std::ostream& getStream();

            static Logger& get();
            
        private:
            
            Level m_logLevel;
            std::ostream* m_logStream;
            static std::unique_ptr<Logger> m_instance;
    };
    
    // Source: http://wordaligned.org/articles/cpp-streambufs#toctee-streams
    class TeeBuf : public std::streambuf
    {
        public:
            // Construct a streambuf which tees output to both input
            // streambufs.
            TeeBuf(std::streambuf* sb1, std::streambuf* sb2);
        private:
            // This tee buffer has no buffer. So every character "overflows"
            // and can be put directly into the teed buffers.
            virtual int overflow(int c);
            // Sync both teed buffers.
            virtual int sync();
        private:
            std::streambuf* m_sb1;
            std::streambuf* m_sb2;
    };

    class TeeStream : public std::ostream
    {
        public:
            // Construct an ostream which tees output to the supplied
            // ostreams.
            TeeStream(std::ostream& o1, std::ostream& o2);
        private:
            TeeBuf m_tbuf;
    };
}

#endif // LOG_HPP
