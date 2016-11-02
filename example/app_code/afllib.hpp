#include <string>
#include <stdint.h>

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

    static void Regenerate(int64_t& value);
    static void Regenerate(int32_t& value);
    static void Regenerate(int16_t& value);
    static void Regenerate(int8_t& value);
    static void Regenerate(uint64_t& value);
    static void Regenerate(uint32_t& value);
    static void Regenerate(uint16_t& value);
    static void Regenerate(uint8_t& value);
    static void Regenerate(float& value);
    static void Regenerate(double& value);
};
