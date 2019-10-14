//
// Created by El Jawad Alaa on 08/10/2019.
//

#include "utilities/Logger.h"

Logger *Logger::instance = 0;

Logger::Logger() {

}

Logger *Logger::getInstance() {
  if (instance == 0)
    instance = new Logger();
  return instance;
}

void Logger::log(LogLevel pLevel, std::string pMessage) {
//  std::cout << "\x1B[31mTexting\033[0m" << std::endl;
  std::string normal_color = "\033[0m";
  std::string esc = "\x1B";
  std::string log_color, log_title;
  switch (pLevel) {
    case DEBUG:
      log_color = "[37m";
      log_title = "DEBUG";
      break;
    case INFO:
      log_color = "[33m";
      log_title = "INFO";
      break;
    case WARN:
      log_color = "[32m";
      log_title = "WARN";
      break;
    case ERROR:
      log_color = "[31m";
      log_title = "ERROR";
      break;
  }
  std::cout << esc << log_color << "[" << log_title << "]: " << pMessage << normal_color << std::endl;
}

void Logger::debug(std::string pLog) {
  log(DEBUG, pLog);
}

void Logger::info(std::string pLog) {
  log(INFO, pLog);
}

void Logger::warn(std::string pLog) {
  log(WARN, pLog);
}

void Logger::error(std::string pLog) {
  log(ERROR, pLog);
}
