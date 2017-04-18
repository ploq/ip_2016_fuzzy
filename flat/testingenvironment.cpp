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
    std::stringstream ss;
    std::string _afl_data;
    std::cin >> _afl_data;
    
    
    std::vector<unsigned char> afl_data(_afl_data.begin(), _afl_data.end());

    //First byte tells us the length of afl_data, check if it's correct
    std::cout << afl_data.size()-1 << " : " << (int)afl_data[0] << std::endl;
    std::cout << (afl_data.size()-1 != afl_data[0]) << std::endl;
    if ( afl_data.size() < sizeof(unsigned char) + sizeof(unsigned int)*2
	 ||  afl_data.size()-1 != afl_data[0])
    {
	//std::cout << afl_data.size()-1 << " : " << afl_data[0] << std::endl;
	return false;
    }
    
    //randtype should always be second byte of afl_data
    TestingEnvironment::params.randtype = (unsigned char)afl_data[1];
    

    /* Cycles should contain a amount of bytes read from afl_data.
       The amount is specified by the first byte of the cycles range.
       The first byte of cycles range is found in afl_data[2].
     */
    unsigned char CYCLES_MAX_BYTES = afl_data[2];
    unsigned int cycles;

    int offset = 3;
    for (int i = 0; i < CYCLES_MAX_BYTES ; i++) {
        cycles += afl_data[offset + i];
    }

    TestingEnvironment::params.cycles = cycles;
    std::cout << TestingEnvironment::params.cycles 
      << " : " << cycles << std::endl;
    
    /* Seed should contain a amount of bytes read from afl_data.
       The amount is specified by the first byte of the seed range.
       The first byte of seed range is found in afl_data[3 + CYCLES_MAX_BYTES].
     */
    unsigned char SEED_MAX_BYTES = afl_data[3+CYCLES_MAX_BYTES];
    unsigned int seed;

    offset = 3 + CYCLES_MAX_BYTES + 1;
    for (int i = 0; i < SEED_MAX_BYTES ; i++) {
        seed += afl_data[offset + i];
    }

    TestingEnvironment::params.seed = seed;
    std::cout << TestingEnvironment::params.seed 
     << " : " << seed << std::endl;

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
