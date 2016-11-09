#include <string>
#include <stdint.h>

#include "mt1337.hpp"

struct parameters {
  int cycles;
  int seed;
  char randtype;
};

class AFL {
private:
    static parameters params;

public:
    AFL();
    static void init(std::string afl_data);
    static int getCycles(void);
    static int getSeed(void);
    static char getRandType(void);
    
    static MT1337 getRandomGenerator();

    /*static void Regenerate(int64_t& value);
    static void Regenerate(int32_t& value);
    static void Regenerate(int16_t& value);
    static void Regenerate(int8_t& value);
    static void Regenerate(uint64_t& value);
    static void Regenerate(uint32_t& value);
    static void Regenerate(uint16_t& value);
    static void Regenerate(uint8_t& value);
    static void Regenerate(float& value);
    static void Regenerate(double& value);

    static void Regenerate(int64_t& value, int64_t min, int64_t max);
    static void Regenerate(int32_t& value, int32_t min, int32_t max);
    static void Regenerate(int16_t& value, int16_t min, int16_t max);
    static void Regenerate(int8_t& value, int8_t min, int8_t max);
    static void Regenerate(uint64_t& value, uint64_t min, uint64_t max);
    static void Regenerate(uint32_t& value, uint32_t min, uint32_t max);
    static void Regenerate(uint16_t& value, uint16_t min, uint16_t max);
    static void Regenerate(uint8_t& value, uint8_t min, uint8_t max);
    static void Regenerate(float& value, float min, float max);
    static void Regenerate(double& value, double min, double max);*/
};
