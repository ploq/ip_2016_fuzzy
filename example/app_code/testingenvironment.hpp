#ifndef TESTINGENVIRONMENT_HPP
#define TESTINGENVIRONMENT_HPP

#include <vector>
#include "randomgenerator.hpp"

class TestingEnvironment {
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

public:
    TestingEnvironment();
    static bool init(int argc, char **argv);
    static void quit();
    static int getCycles(void);
    static int getSeed(void);
    static char getRandType(void);
    
    static RandomGenerator& createRandomGenerator();
};

#endif
