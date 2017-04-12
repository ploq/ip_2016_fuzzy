#include "testingenvironment.hpp"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mt1337.hpp"

TestingEnvironment::parameters TestingEnvironment::params = {};
int TestingEnvironment::progress = 0;
std::vector<RandomGenerator*> TestingEnvironment::generators;

TestingEnvironment::TestingEnvironment() {}

bool TestingEnvironment::init(int argc, char **argv) {
    std::string afl_data;
    std::cin >> afl_data;
    char afl_data2[afl_data.length()+1];
    strcpy (afl_data2, afl_data.c_str());
    std::cout << afl_data2 << std::endl;

    //afl_data = afl_data.c_str();
    for (auto a : afl_data)
	std::cout << (unsigned int)a << std::endl;
	     //std::cout << (int)afl_data[0] << std::endl;
    for (int b = 0 ; b < afl_data.length() ;b++)
	std::cout << (unsigned int)afl_data2[b] << std::endl;
    
    parameters params;

    //randtype should always be first byte of afl_data
    params.randtype = (unsigned char)afl_data[0];
    std::cout << "afl_data[0] size: " << sizeof(afl_data[0]) << std::endl; //1 byte
    std::cout << "afl_data[0] value: " << (unsigned int)afl_data[0] << std::endl; // 0

    /* Cycles should contain a amount of bytes read from afl_data.
       The amount is specified by the first byte of the cycles range.
       The first byte is found in afl_data[1].
     */
    unsigned int CYCLES_MAX_BYTES = (unsigned int)afl_data2[1];
    unsigned int cycles;
    for (int i = 2; i <= CYCLES_MAX_BYTES+1 ; i++) {
        cycles += (unsigned int)*(afl_data2+i);
	std::cout << afl_data2[i] << std::endl;
    }
    std::cout << cycles << std::endl;

    /*unsigned int* cycles_bytes;
    memcpy(cycles_bytes, cycles.data(), cycles.length());
    params.cycles = *cycles_bytes;*/
    params.cycles = cycles;
    
    //std::cout << "cycle_bytes size: " << cycles.length() << std::endl;
    //std::cout << "cycle_bytes value: " << (unsigned int)(*cycles_bytes) << std::endl;

    /* Seed should contain a amount of bytes read from afl_data.
       The amount is specified by the first byte of the seed range.
       The first byte for seed is found in afl_data[CYCLES_MAX_BYTES+1].
     */
    unsigned int SEED_MAX_BYTES = (unsigned int)afl_data[CYCLES_MAX_BYTES+1];
     std::cout << "SEED_MAX_BYTES size: " << SEED_MAX_BYTES << std::endl;
    std::string seed;
    for (int i = CYCLES_MAX_BYTES+2; i <= SEED_MAX_BYTES ; i++) {
        seed += afl_data[i];
    }

    unsigned int* seed_bytes;
    memcpy(seed_bytes, seed.data(), seed.length());
    params.seed = *seed_bytes;
    std::cout << "seed_bytes size: " << seed.length() << std::endl;
    std::cout << "seed_bytes value: " << (unsigned int)(*seed_bytes) << std::endl;

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
