//
// Created by El Jawad Alaa on 08/10/2019.
//

#ifndef SUBWAYSIMULATOR_LOGGER_H
#define SUBWAYSIMULATOR_LOGGER_H


#include <string>
#include <iostream>

class Logger {
private:
    static Logger* instance;
    Logger();
    enum LogLevel {
        DEBUG, INFO, WARN, ERROR
    };

public:
    static Logger* getInstance();

private:
    void log(LogLevel pLevel, std::string pMessage);
public:
    void debug(std::string pLog);
    void info(std::string pLog);
    void warn(std::string pLog);
    void error(std::string pLog);
};


#endif //SUBWAYSIMULATOR_LOGGER_H
