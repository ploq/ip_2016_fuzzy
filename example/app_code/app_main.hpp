#ifndef APP_MAIN_HPP
#define APP_MAIN_HPP
#include <iostream>
// Required
void APP_Name_Initialize();
void APP_Name_Execute();

// Optional
void APP_Name_Terminate();

class Scheduler {
    int _V0_gen, _V1_gen, _V2_gen;
public:
    int _V0, _V1, _V2;
    Scheduler();
    void updateIO();
};

struct parameters {
  int cycles;
  int seed;
  char randtype;
};

class AFL {
private:
    struct parameters params;

public:
    AFL(std::string afl_data);
    int getCycles(void);
    int getSeed(void);
    char getRandType(void);
};

#endif // APP_MAIN_HPP
