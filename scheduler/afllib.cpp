#include "afllib.hpp"

AFL::AFL(char *afl_data) {
    params = *((parameters*) afl_data);
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