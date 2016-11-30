#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <mutex>

class Logger
{
public:
    static bool init();
    static void log(std::string str);
    static void startlog();
    static void endlog();
    static void quit();

private:
    static std::ofstream logfile;
    static std::fstream crashdata;
    static unsigned int logcount;
    static std::mutex mtx;

    static void updateCrashLog();
};

#endif
