#ifndef MT1337_H
#define MT1337_H

class MT1337 {
    int mt[624];
    int index;
public:
    MT1337() = default;
    MT1337(int seed);
    int extractNumber();
    void twistIt();
};

#endif
