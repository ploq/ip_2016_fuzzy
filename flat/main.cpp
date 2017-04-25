#include "main.hpp"

int main(int argc, char **argv)
{       
    while (__AFL_LOOP(1000)) { 
	if (!TestingEnvironment::init())
	{
	    continue;
	}

	APP_Name_Initialize();
	
	for (int n = 0; n < TestingEnvironment::getCycles(); n++) {
	    switch (TestingEnvironment::getRandType()) {
	    case RANDOM_GENERATOR:
		{
		    PortStorage::Regenerate();
		    break;
		}
	    case STATIC_GENERATOR:
		{
		    TestingEnvironment::readConfig(n);
		    PortStorage::Regenerate(TestingEnvironment::getConfig());
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
