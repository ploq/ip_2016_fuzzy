#include "testingenvironment.hpp"

#include <iostream>
#include "sha256.hpp"
#include "mt1337.hpp"

TestingEnvironment::parameters TestingEnvironment::params = {};
int TestingEnvironment::progress = 0;
std::vector<RandomGenerator*> TestingEnvironment::generators;

TestingEnvironment::TestingEnvironment() {}

bool TestingEnvironment::init(int argc, char **argv) {
    std::string afl_data;
    std::cin >> afl_data;
    
    //if (afl_data.size() < sizeof(parameters)) return false; //8k exec/s cost

    std::string output1 = sha256(afl_data); //1k exec/s cost
    params = *((parameters*) output1.c_str()); //no cost

    return true;
}

void TestingEnvironment::quit()
{
    for (unsigned int i = 0; i < generators.size(); ++i)
    {
	delete generators[i];
    }
    generators.clear();
}

int TestingEnvironment::getSeed() {
    return params.seed;
}

int TestingEnvironment::getCycles() {
    return params.cycles;
}

char TestingEnvironment::getRandType() {
    return params.randtype;
}

RandomGenerator& TestingEnvironment::createRandomGenerator() {
    RandomGenerator* rng = new MT1337 (params.seed);
    progress++;
    for (int i = 0; i < progress; ++i)
    {
	rng->nextSeed();
    }
    generators.push_back(rng);
    return *rng;
}
