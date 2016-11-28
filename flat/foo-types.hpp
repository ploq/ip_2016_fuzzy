#ifndef FOO_TYPES_HPP
#define FOO_TYPES_HPP

#include "stdint.hpp"
#include "reals.hpp"

namespace Foo {

typedef RealT MyHeightT;

struct BundleT {
    RealT P0;
    MyHeightT P1;
};

namespace SimpleT {
enum Enum {
    None = 0,
    S0 = 1,
    S1 = 2
};
}

namespace WithHolesT {
enum Enum {
    S0 = 1,
    S2 = 10
};
}

} // NS: Foo

#endif // FOO_TYPES_HPP
