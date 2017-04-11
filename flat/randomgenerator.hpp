#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <stdint.h>
#include <string>

class RandomGenerator
{
public:
    /*
      Constructor taking a name. The name is used for logging.
     */
    RandomGenerator() = default;

    /*
      Virtual destructor, nothing special.
     */
    virtual ~RandomGenerator() {};

    /*
      Generates a new random value. The note is a message written to the log. It is expected that the function logs the generated value alongside the note.
     */
    virtual int64_t generate() = 0;

    /*
      Same as above, but generates values within a range between min and max (inclusive).
     */
    virtual int64_t generate(int64_t min, int64_t max) = 0;

    /*
      Gets the current seed value.
     */
    virtual uint64_t getSeed() = 0;

    /*
      Moves the random generator to the next state, updating the seed.
     */
    virtual void nextSeed() = 0;

protected:
    std::string name;
};

#endif
