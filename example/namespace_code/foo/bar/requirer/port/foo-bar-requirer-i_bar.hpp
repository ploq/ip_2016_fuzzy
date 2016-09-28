#ifndef FOO_BAR_REQUIRER_I_BAR_HPP
#define FOO_BAR_REQUIRER_I_BAR_HPP

#include "foo-bar-types.hpp"

namespace Foo {

namespace Bar {

namespace Requirer {

class I_Bar {
public:
    I_Bar();
    virtual ~I_Bar();

    virtual const Foo::Bar::FunT& Get_Foo() const = 0;
    virtual int64_t Get_Foo_V0() const = 0;
    virtual Foo::Bar::MyIntT Get_Foo_V1() const = 0;
    virtual Foo::Bar::MyIntT Get_Foo_V2() const = 0;
    virtual Foo::MyHeightT Get_Foo_V3() const = 0;
    virtual const Foo::BundleT& Get_Foo_V4() const = 0;
    virtual Foo::SimpleT::Enum Get_Foo_V5() const = 0;
    virtual Foo::WithHolesT::Enum Get_Foo_V6() const = 0;

    virtual Foo::Bar::FumT& Get_Fum() = 0;
    virtual void Put_Fum(const int64_t V0) = 0;

private:
    I_Bar(const I_Bar&);
    const I_Bar& operator=(const I_Bar&);
};

} // NS: Requirer

} // NS: Bar

} // NS: Foo

#endif // FOO_BAR_REQUIRER_I_BAR_REQUIRER_HPP
