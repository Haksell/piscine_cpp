#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>
#include <string>
#include <utility>

#define DEBUG "debug"
#define INFO "Info."
#define WARNING "WARNING"
#define ERROR "!!! ERROR ERROR ERROR !!!"
#define UNKNOWN "Unknown log level."

class Harl {
  private:
    typedef void (Harl::*log_func_t)(void);
    typedef std::map<std::string, log_func_t> log_map_t;
    log_map_t logFunctions;

    void debug();
    void info();
    void warning();
    void error();

  public:
    Harl();
    void complain(std::string level);
};

#endif