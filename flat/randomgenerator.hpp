#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <stdint.h>
#include <string>
#include <map>
#include <vector>

class RandomGenerator
{
public:
    /*
      Constructor
     */
    RandomGenerator() = default;

    /*
      Virtual destructor
     */
    virtual ~RandomGenerator() {};

    /*
      Generates random value
     */
    virtual long long generate() = 0;

    /*
      Generates random value within min and max range
     */
    virtual long long generate(long long min, long long max) = 0;
    
    /*
      Generates static value
     */
    virtual long long generate(const std::map<std::string, std::vector<std::vector<int>>> &vars, std::string name) = 0;

    /*
      Generates static value for variables using ranges
     */
    virtual long long generate(const std::map<std::string, std::vector<std::vector<int>>> &vars, std::string name, long long min, long long max) = 0;

    /*
      Gets the current seed value.
     */
    virtual uint64_t getSeed() = 0;

    /*
      Moves the random generator to the next state, updating the seed.
     */
    virtual void nextSeed() = 0;

protected:
    std::string name;
};

#endif
