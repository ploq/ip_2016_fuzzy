#ifndef TESTINGENVIRONMENT_HPP
#define TESTINGENVIRONMENT_HPP

#include <vector>
#include <string>
#include "randomgenerator.hpp"

class TestingEnvironment
{
public:
    /*
      Constructor doing nothing...
     */
    TestingEnvironment();

    /*
      Initializes the testing environment. Right now, it reads a file from standard input, and does not use argc and argv at all.

      Returns true if successful, false if not.
     */
    static bool init();

    /*
      Deinitializes the testing environment.
     */
    static void quit();

    /*
      Returns the number of times which the SUT should run.
     */
    static unsigned int getCycles(void);

    /*
      Unused. To be moved to randomgenerator.
     */
    static unsigned int getSeed(void);

    /*
      Unused. To be moved to randomgenerator.
     */
    static char getRandType(void);
    
    /*
      Creates and returns a new random number generator. The name is given to the generator for logging purposes. 
     */
    static RandomGenerator& createRandomGenerator();

private:    
    struct parameters
    {
	unsigned char randtype;
	unsigned int cycles;
	unsigned int seed;
    };

    static parameters params;
    static int progress;
    static std::vector<RandomGenerator*> generators;
};

#endif
