#include "afllib.hpp"
#include "sha256.hpp"

AFL::AFL(std::string afl_data) {
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

//3098 total, 2846 unika
