#include "testingenvironment.hpp"
#include "portenvironment.hpp"

#include <iostream>
#include <fstream>
#include "app_main.hpp"
#include <iostream>

int main(int argc, char **argv)
{       
    
    while (__AFL_LOOP(1000)) { 
	if (!TestingEnvironment::init(argc, argv))
	{
	    continue;
	}

	if (!PortEnvironment::init())
	{
	    return 0;
	}
	
	APP_Name_Initialize();
	std::cout << TestingEnvironment::getCycles() << std::endl;
	std::cout << TestingEnvironment::getSeed() << std::endl;
	for (int n = 0; n < TestingEnvironment::getCycles(); n++) {
	    PortEnvironment::regenerate();
	    APP_Name_Execute();
	}

	APP_Name_Terminate();

	PortStorage::CleanUp();

	PortEnvironment::quit();
    }
    return 0;
}
