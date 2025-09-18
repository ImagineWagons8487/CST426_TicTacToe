#include "Log.h"

bool Log::initialized = false;
LogLevel Log::logLevel;

void Log::initialize()
{
    initialize(NONE);
}

void Log::initialize(LogLevel lvl)
{
    logLevel = lvl;
    createNewFile("log.txt");
    writeToFile("Logger initialized!");
    std::cout << "Logger Initialized!" << std::endl;
    initialized = true;
}

void Log::log(LogLevel lvl, std::string message)
{
    if(logLevel <= lvl && initialized)
    //if current logLevel is greater than or the same as lvl passed in, then allow logging
    {
        writeToFile(message);
        std::cout << message << std::endl;
    }
    else if(!initialized)
    {
        std::cout << "Logger Use Attempt Failed: Logger Uninitialized" << std::endl;
    }
}

void Log::log(LogLevel lvl, int num)
{
    std::string s = "";
    s += (num + '0');
    log(lvl, s);
}

void Log::setLevel(LogLevel lvl)
{
    logLevel = lvl;
}

void Log::createNewFile(std::string name)
{
    std::ofstream fout;

    fout.open("log.txt");

    fout.close();
}

void Log::writeToFile(std::string text)
{
    std::ofstream fout;
    fout.open("log.txt", std::ios::out | std::ios::app);

    fout << text << std::endl;

    fout.close();
}