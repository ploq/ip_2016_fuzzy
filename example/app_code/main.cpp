#include "testingenvironment.hpp"
#include "portenvironment.hpp"

#include <iostream>
#include <fstream>
#include "app_main.hpp"
#include "logger.hpp"

int main(int argc, char **argv)
{       
    std::ofstream output_file("output.txt", std::ios_base::app);
    
    Logger::init();

    if (!TestingEnvironment::init(argc, argv))
    {
	return 0;
    }

    if (!PortEnvironment::init())
    {
	return 0;
    }

    srand(TestingEnvironment::getSeed());

    APP_Name_Initialize();
    for (int n = 0; n < 10; n++) {
	Logger::startlog();
	PortEnvironment::regenerate();
	APP_Name_Execute();
	Logger::endlog();
    }
    APP_Name_Terminate();
    output_file << TestingEnvironment::getCycles() << " " << TestingEnvironment::getSeed() << std::endl;
    output_file.close();

    PortStorage::CleanUp();

    PortEnvironment::quit();
    TestingEnvironment::quit();
    Logger::quit();
    return 0;
}
