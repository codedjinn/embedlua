
#include "logger.h"

#include <ctime>
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>

// rework later
bool _logToConsole = true;
std::mutex mtx;
int acc = 0;

// optimize later
void Log(LogType type, std::string str)
{
    // very lazy thread-safety, don't use for actual
    // game implementation, can cause frame locks
    mtx.lock();

    std::string log;

    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    log.append(buffer);
    log.append(" ");

    switch (type)
    {
        case LogType::Info:
            log.append("[INFO] ");
            break;
        case LogType::Debug:
            log.append("[DEBUG] ");
            break;
        case LogType::Error:
            log.append("[ERROR] ");
            break;
    }
    
    log.append(str);
    log.append("\n");

    // change to std::io::app later
    std::ofstream file("engine.log", std::ios::app);
    file << log;
    file.close();
    
    if (_logToConsole)
    {
        printf("%s", log.c_str());
    }

    mtx.unlock();
}

void LogInfo(std::string str)
{
    Log(LogType::Info, str);
}

void LogDebug(std::string str)
{
    Log(LogType::Debug, str);
}

void LogError(std::string str)
{
    Log(LogType::Error, str);
}

void LogPerCount(std::string str, int mod)
{
    acc++;
    if (acc % mod == 0)
    {
        Log(LogType::Info, str);
    }

    if (acc == 2147483646)
    {
        acc = 0;
    }
}