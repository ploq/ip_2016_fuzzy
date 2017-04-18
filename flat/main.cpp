#include "testingenvironment.hpp"
#include "portenvironment.hpp"

#include <iostream>
#include <fstream>
#include "app_main.hpp"
#include <iostream>

int main(int argc, char **argv)
{       
    
    while (__AFL_LOOP(10)) { 
	if (!TestingEnvironment::init())
	{
	    continue;
	    //return 0;
	}

	
	APP_Name_Initialize();
	for (int n = 0; n < TestingEnvironment::getCycles(); n++) {
	    PortStorage::Regenerate();
	    APP_Name_Execute();
	}

	APP_Name_Terminate();

	PortStorage::CleanUp();
    }
    return 0;
}
