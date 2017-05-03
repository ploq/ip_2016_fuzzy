#include "main.hpp"

int main(int argc, char **argv)
{       
    TestingEnvironment::readConfig();

    while (__AFL_LOOP(1000)) { 
	if (!TestingEnvironment::init())
	{
	    continue;
	}

	APP_Name_Initialize();
	
	for (int n = 0; n < TestingEnvironment::getCycles(); n++) {
	    //NOTE: use static generator only for demonstration
	    switch (TestingEnvironment::getRandType()) {
	    case RANDOM_GENERATOR:
		{ 
		    //PortStorage::Regenerate();
		    PortStorage::Regenerate(TestingEnvironment::getConfig(), n);
		    break;
		}
	    case STATIC_GENERATOR:
		{
		    PortStorage::Regenerate(TestingEnvironment::getConfig(), n);
		    break;
		}
	    default:
		{
		    PortStorage::Regenerate();
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
