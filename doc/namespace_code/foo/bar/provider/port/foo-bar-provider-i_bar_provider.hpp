#include "some_interface_file_with_structs_enums_etc.hpp"

namespace Foo {

namespace Bar {

namespace Provider {

class I_Bar {
public:
    I_Bar();
    virtual ~I_Bar();

    virtual Foo::Bar::FunT& Get_Foo() = 0;
    virtual void Put_Fun(const Foo::Bar::IntT V0, const Foo::Bar::MyIntT V1, const Foo::Bar::MyIntT V2, const Foo::Bar::MyHeightT V3, const Foo::Bar::BundleT& V4, const Foo::Bar::SimpleT V5, const Foo::Bar::WithHolesT V6) = 0;

    virtual const Foo::Bar::Fum& Get_Fum() const = 0;
    virtual Foo::Bar::IntT Get_Fum_V0() const = 0;

private:
    I_Bar(const I_Bar&);
    const I_Bar& operator=(const I_Bar&);
};

} // NS: Provider

} // NS: Bar

} // NS: Foo
