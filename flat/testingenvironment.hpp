#ifndef TESTINGENVIRONMENT_HPP
#define TESTINGENVIRONMENT_HPP

#include <vector>
#include <map>
#include <string>
#include "randomgenerator.hpp"

class TestingEnvironment
{
public:
    /*
      Constructor
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
      Returns which type of randomgenerator SUT has
     */
    static char getRandType(void);

    /*
      Reads config file into SUT. Path is hardcoded to ./config.txt
     */
    //static void readConfig(int curr_cycles);

    /*
      Returns config map
     */
    //static const std::map<std::string, std::map<std::string, std::vector<std::vector<int>>>> & getConfig();
    
    /*
      Creates and returns a new random number generator.
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
    // static std::map<std::string, std::map<std::string, std::vector<std::vector<int>>>> namespaces;
};

#endif
