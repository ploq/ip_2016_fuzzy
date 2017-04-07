#ifndef MT1337_H
#define MT1337_H

#include "randomgenerator.hpp"

class MT1337 : public RandomGenerator {
    int mt[624];
    int index;
    
    int extractNumber();
    void twistIt();
public:
    MT1337(std::string name, int seed);
    int64_t generate(std::string note);
    int64_t generate(std::string note, int64_t min, int64_t max);
    uint64_t getSeed();
    void nextSeed();
};

#endif
