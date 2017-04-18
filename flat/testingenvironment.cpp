#include "testingenvironment.hpp"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip> 
#include "mt1337.hpp"

TestingEnvironment::parameters TestingEnvironment::params = {};
int TestingEnvironment::progress = 0;
std::vector<RandomGenerator*> TestingEnvironment::generators;

TestingEnvironment::TestingEnvironment() {}

bool TestingEnvironment::init(int argc, char **argv) {
    std::string _afl_data;
    std::cin >> _afl_data;
    
    std::vector<unsigned char> afl_data(_afl_data.begin(), _afl_data.end());


    //afl_data = afl_data.c_str();    
    parameters params;

    //randtype should always be first byte of afl_data
    params.randtype = (unsigned char)afl_data[0];
    std::cout << "afl_data[0] size: " << sizeof(afl_data[0]) << std::endl; //1 byte
    std::cout << "afl_data[0] value: " << (int) params.randtype << std::endl; // 0

    /* Cycles should contain a amount of bytes read from afl_data.
       The amount is specified by the first byte of the cycles range.
       The first byte is found in afl_data[1].
     */
    unsigned char CYCLES_MAX_BYTES = afl_data[1];
    std::cout << "Cycles field length: " << (int) CYCLES_MAX_BYTES << std::endl;
    unsigned int cycles;
    for (int i = 2; i < 2+CYCLES_MAX_BYTES ; i++) {
        std::cout << "Cycle: " << i << " Value: " << (unsigned int) afl_data[i] << std::endl;
        cycles += afl_data[i];
    }
    std::cout << "Num cycles: " << (int)cycles << std::endl;

    params.cycles = cycles;
    
    /* Seed should contain a amount of bytes read from afl_data.
       The amount is specified by the first byte of the seed range.
       The first byte for seed is found in afl_data[CYCLES_MAX_BYTES+1].
     */
    unsigned char SEED_MAX_BYTES = afl_data[2+CYCLES_MAX_BYTES];
     std::cout << "SEED_MAX_BYTES size: " << (int) SEED_MAX_BYTES << std::endl;
    unsigned int seed;
    for (int i = 2+CYCLES_MAX_BYTES+1; i < 2+CYCLES_MAX_BYTES+SEED_MAX_BYTES+1 ; i++) {
        std::cout << (unsigned int) afl_data[i] << std::endl;
        seed += afl_data[i];
    }

    params.seed = seed;
    std::cout << "seed_bytes value: " << params.seed << std::endl;

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

unsigned int TestingEnvironment::getSeed() {
    return params.seed;
}

unsigned int TestingEnvironment::getCycles() {
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
