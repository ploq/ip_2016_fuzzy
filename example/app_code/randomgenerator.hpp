#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <stdint.h>
#include <string>

class RandomGenerator
{
public:
    RandomGenerator(std::string n) : name(n) {};
    virtual ~RandomGenerator() {};
    virtual int64_t generate(std::string note) = 0;
    virtual int64_t generate(std::string note, int64_t min, int64_t max) = 0;
    virtual uint64_t getSeed() = 0;
    virtual void nextSeed() = 0;

protected:
    std::string name;
};

#endif
