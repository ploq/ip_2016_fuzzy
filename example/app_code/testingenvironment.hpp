#ifndef TESTINGENVIRONMENT_HPP
#define TESTINGENVIRONMENT_HPP

#include <vector>
#include <string>
#include "randomgenerator.hpp"

class TestingEnvironment
{
public:
    TestingEnvironment();
    static bool init(int argc, char **argv);
    static void quit();
    static int getCycles(void);
    static int getSeed(void);
    static char getRandType(void);
    
    static RandomGenerator& createRandomGenerator(std::string name);

private:    
    struct parameters
    {
	int cycles;
	int seed;
	char randtype;
    };

    static parameters params;
    static int progress;
    static std::vector<RandomGenerator*> generators;
};

#endif
