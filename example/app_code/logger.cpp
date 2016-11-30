#include "logger.hpp"

std::ofstream Logger::logfile;
std::fstream Logger::crashdata;
unsigned int Logger::logcount;
std::mutex Logger::mtx;

bool Logger::init()
{
    mtx.lock();
    crashdata.open("crashdata.txt");
    crashdata >> logcount;
    logfile.open("log" + std::to_string(logcount) + ".txt");
    mtx.unlock();
    return true;
}

void Logger::log(std::string str)
{
    mtx.lock();
    logfile << str << std::endl;
    mtx.unlock();
}

void Logger::startlog()
{
    mtx.lock();
    logcount++;
    updateCrashLog();
    mtx.unlock();
}

void Logger::endlog()
{
    mtx.lock();
    logfile.seekp(0);
    logcount--;
    updateCrashLog();
    mtx.unlock();
}

void Logger::quit()
{
    mtx.lock();
    logfile.close();
    crashdata.close();
    mtx.unlock();
}

void Logger::updateCrashLog()
{
    crashdata.seekp(0);
    crashdata << logcount << std::endl;
}
