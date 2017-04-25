#include "mt1337.hpp"
#include <sstream>
#include <iostream>

MT1337::MT1337(const unsigned int seed) : RandomGenerator() {
	index = 624;
	mt[0] = seed;
	
	
	for (int n = 1; n < 624; n++) {
		mt[n] = 1812433253 * ( mt[n-1] ^ mt[n -1] >> 30) + n; 
	} 
};

long long MT1337::extractNumber() {
	long long y = 0;
	if (index >= 624) {
		twistIt();
		index = 0;
	}
	y = mt[index];
	y = y ^ y >> 11;
	y = y ^ (y << 7 & 2636928640);
	y = y ^ (y << 15 & 4022730752);
	y = y ^ y >> 18;

	index++;

	return y;
}

void MT1337::twistIt() {
	int y = 0;
	for (int n = 0; n < 624; n++) {
		y = (mt[n] & 0x80000000) + (mt[n+1 % 624] & 0x7fffffff);
		mt[n] = mt[(n + 397) % 624] ^ y >> 1;

		if (y % 2 != 0) {
			mt[n] = mt[n] ^ 0x9908b0df;
		}
	}

	index = 0;
}

long long MT1337::generate()
{
    long long value = extractNumber();
    return value;
}

long long MT1337::generate(long long min, long long max)
{
    return generateRangeValue(min, max);
}

long long MT1337::generate(const std::map<std::string, std::vector<int>> &vars, std::string name)
{
    long long value;
    if (vars.count(name) > 0) {
	int64_t min_cycles = vars.at(name)[0];
	int64_t max_cycles = vars.at(name)[1];
	int64_t curr_cycles = vars.at(name)[3];
	if (min_cycles <= curr_cycles && curr_cycles <= max_cycles) {
	    value = vars.at(name)[2];
	}
	else {
	    value = extractNumber();
	}
    }
    else {
	value = extractNumber();
    }
    return value;
}

long long MT1337::generate(const std::map<std::string, std::vector<int>> &vars, std::string name, long long min, long long max)
{
    long long value;
    if (vars.count(name) > 0) {
	int64_t min_cycles = vars.at(name)[0];
	int64_t max_cycles = vars.at(name)[1];
	int64_t curr_cycles = vars.at(name)[3];
	if (min_cycles <= curr_cycles && curr_cycles <= max_cycles) {
	    value = vars.at(name)[2];
	    /*std::cout << vars.at(name)[0] << " "
	      << vars.at(name)[1] << " "
	      << vars.at(name)[2] << " "
	      << vars.at(name)[3] << " " << std::endl;
	    */
	    std::cout << vars.at(name)[3] << std::endl;
	}
	else {
	    value = generateRangeValue(min, max);
	}
    }
    else {
	value = generateRangeValue(min, max);
    }
    return value;
}

long long MT1337::generateRangeValue(const long long &min, const long long &max) {
    long long value = extractNumber();
    uint64_t difference = max - min;
    if (value > max || value < min)
    {
	value = min + (value % (difference + 1));
    }   
    return value;
}

uint64_t MT1337::getSeed()
{
    return index;
}

void MT1337::nextSeed()
{
    twistIt();
}
