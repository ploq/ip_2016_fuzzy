#include "testingenvironment.hpp"
#include "portenvironment.hpp"

#include <iostream>
#include <fstream>
#include "app_main.hpp"

int main(int argc, char **argv)
{       
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
    for (int n = 0; n < 10000; n++) {
	 PortEnvironment::regenerate();
	    APP_Name_Execute();
    }

    APP_Name_Terminate();

    PortStorage::CleanUp();

    PortEnvironment::quit();
    TestingEnvironment::quit();
    return 0;
}
