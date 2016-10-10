struct parameters {
  int cycles;
  int seed;
  char randtype;
};

class AFL {
private:
    struct parameters params;

public:
    AFL(char* afl_data);
    int getCycles(void);
    int getSeed(void);
    char getRandType(void);
};