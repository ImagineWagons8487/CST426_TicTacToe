#ifndef IMGUI_LOG_H
#define IMGUI_LOG_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

enum LogLevel
{
    NONE,
    INFO,
    WARNING,
    ERROR,

    LASTENUM
};

// static class
// logging to file, optional?
class Log
{
    //bro idfk
    private:
        //any private data structures needed?
        static bool initialized;
        //log level?
        static LogLevel logLevel;
        
        static void createNewFile(std::string name);
        static void writeToFile(std::string text);


    public:
        //static public functions
        static void initialize();
        static void initialize(LogLevel lvl);
        static void log(LogLevel lvl, std::string message);
        static void log(LogLevel lvl, int num); //for outputting numbers
        static void setLevel(LogLevel lvl);
};

#endif