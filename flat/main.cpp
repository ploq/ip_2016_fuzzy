#include "main.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main(int argc, char **argv)
{       
    std::map<std::string, std::map<std::string, std::vector<int>>> namespaces;
    std::map<std::string, std::vector<int>> vars;
    std::vector<int> vec;

    while (__AFL_LOOP(1000)) { 
	if (!TestingEnvironment::init())
	{
	    continue;
	}

	APP_Name_Initialize();
	
	for (int n = 0; n < TestingEnvironment::getCycles(); n++) {
	    vec = {120, 200, 3, n};
	    vars["fun.V0"] = vec;
	    namespaces["Foo::Bar::Requirer"] = vars; 

	    switch (TestingEnvironment::getRandType()) {
	    case RANDOM_GENERATOR:
		{
		    PortStorage::Regenerate(namespaces);
		    break;
		}
	    case STATIC_GENERATOR:
		{
		    PortStorage::Regenerate(namespaces);
		    break;
		}
	    }

	    APP_Name_Execute();
	}

	APP_Name_Terminate();

	PortStorage::CleanUp();
    }
    return 0;
}
