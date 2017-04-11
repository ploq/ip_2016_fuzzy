#include "testingenvironment.hpp"

#include <iostream>
#include "picosha256.hpp"
#include "mt1337.hpp"

TestingEnvironment::parameters TestingEnvironment::params = {};
int TestingEnvironment::progress = 0;
std::vector<RandomGenerator*> TestingEnvironment::generators;

TestingEnvironment::TestingEnvironment() {}

bool TestingEnvironment::init(int argc, char **argv) {
    std::string afl_data;
    std::cin >> afl_data;
    if (afl_data.size() < sizeof(parameters)) return false;

    std::string output1;
    picosha2::hash256_hex_string(afl_data, output1);

    params = *((parameters*) output1.c_str());
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

RandomGenerator& TestingEnvironment::createRandomGenerator(std::string name) {
    RandomGenerator* rng = new MT1337 (name, params.seed);
    progress++;
    for (int i = 0; i < progress; ++i)
    {
	rng->nextSeed();
    }
    generators.push_back(rng);
    return *rng;
}
