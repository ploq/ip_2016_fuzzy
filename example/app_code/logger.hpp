#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <mutex>

class Logger
{
public:
    /* Initializes the logging system.

       Returns true if successful, false if not.
     */
    static bool init();

    /*
      Writes a message to the log. Must be called after startlog() and before endlog().
     */
    static void log(std::string str);

    /*
      Creates a log file to write to.
     */
    static void startlog();

    /*
      Deletes the log file. If the SUT crashes, this will never be called, thus leaving the log file undeleted. This is to make sure that only crashes will be logged.
     */
    static void endlog();

    /*
      Stops the logging system.
     */
    static void quit();

private:
    static std::ofstream logfile;
    static std::fstream crashdata;
    static unsigned int logcount;
    static std::mutex mtx;

    static void updateCrashLog();
};

#endif
