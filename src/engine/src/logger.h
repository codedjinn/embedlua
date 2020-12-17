#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

enum class LogType
{
    Info,
    Debug,
    Error
};

// optimize later
void Log(LogType type, std::string str);

void LogInfo(std::string str);
void LogDebug(std::string str);
void LogError(std::string str);
void LogPerCount(std::string str, int mod);

#endif