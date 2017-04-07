#include "afllib.hpp"
#include "sha256.hpp"

parameters AFL::params = {};
int AFL::progress = 0;

AFL::AFL() {}

void AFL::init(std::string afl_data) {
    std::string output1 = sha256(afl_data);
    params = *((parameters*) output1.c_str());
}

int AFL::getSeed() {
    return params.seed;
}

int AFL::getCycles() {
    return params.cycles;
}

char AFL::getRandType() {
    return params.randtype;
}

MT1337 AFL::getRandomGenerator() {
    MT1337 mt ("", params.seed);
    progress++;
    for (int i = 0; i < progress; ++i)
    {
//	mt.twistIt();
    }
    return mt;
}

//3098 total, 2846 unika
