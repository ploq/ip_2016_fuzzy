#ifndef FOO_BAR_TYPES_HPP
#define FOO_BAR_TYPES_HPP

#include "foo-types.hpp"

namespace Foo {

namespace Bar {

typedef int64_t MyIntT;

struct FunT {
    int64_t V0;
    MyIntT V1;
    MyIntT V2;
    ::Foo::MyHeightT V3;
    ::Foo::BundleT V4;
    ::Foo::SimpleT::Enum V5;
    ::Foo::WithHolesT::Enum V6;
};

struct FumT {
    int64_t V0;
};

} // NS: Bar

} // NS: Foo

#endif // FOO_BAR_TYPES_HPP
