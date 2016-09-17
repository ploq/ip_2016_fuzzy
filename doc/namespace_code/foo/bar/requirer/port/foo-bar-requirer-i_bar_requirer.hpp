#include "some_interface_file_with_structs_enums_etc.hpp"

namespace Foo {

namespace Bar {

namespace Requirer {

class I_Bar {
public:
    I_Bar();
    virtual ~I_Bar();

    virtual const Foo::Bar::FunT& Get_Foo() const = 0;
    virtual Foo::Bar::IntT Get_Foo_V0() const = 0;
    virtual Foo::Bar::MyIntT Get_Foo_V1() const = 0;
    virtual Foo::Bar::MyIntT Get_Foo_V2() const = 0;
    virtual Foo::Bar::MyHeightT Get_Foo_V3() const = 0;
    virtual const Foo::Bar::BundleT& Get_Foo_V4() const = 0;
    virtual Foo::Bar::SimpleT Get_Foo_V5() const = 0;
    virtual Foo::Bar::WithHolesT Get_Foo_V6() const = 0;

    virtual Foo::Bar::Fum& Get_Fum() = 0;
    virtual void Put_Fum(const Foo::Bar::IntT& V0) = 0;

private:
    I_Bar(const I_Bar&);
    const I_Bar& operator=(const I_Bar&);
};

} // NS: Requirer

} // NS: Bar

} // NS: Foo
