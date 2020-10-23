#pragma once

#include <string>
#include <ctime>
#include <thread>
#include <mutex>
#include <iostream>

namespace Engine
{

enum class LogType
{
    Info,
    Debug,
    Error
};

// rework later
bool _logToConsole = true;
std::mutex mtx;

// optimize later
void Log(LogType type, std::string str)
{
    // very lazy thread-safety
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

}