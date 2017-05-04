#ifndef FOO_BAR_PROVIDER_I_BAR_HPP
#define FOO_BAR_PROVIDER_I_BAR_HPP

#include "foo-bar-types.hpp"

namespace Foo {

namespace Bar {

namespace Provider {

class I_Bar {
public:
    I_Bar();
    virtual ~I_Bar();

    virtual Foo::Bar::FunT& Get_Fun() = 0;
    virtual void Put_Fun(const int64_t V0, const Foo::Bar::MyIntT V1, const Foo::Bar::MyIntT V2, const Foo::MyHeightT V3, const Foo::BundleT& V4, const Foo::SimpleT::Enum V5, const Foo::WithHolesT::Enum V6) = 0;

    virtual const Foo::Bar::FumT& Get_Fum() const = 0;
    virtual int64_t Get_Fum_V0() const = 0;

private:
    I_Bar(const I_Bar&);
    const I_Bar& operator=(const I_Bar&);
};

} // NS: Provider

} // NS: Bar

} // NS: Foo

#endif // FOO_BAR_PROVIDER_I_BAR_PROVIDER_HPP
