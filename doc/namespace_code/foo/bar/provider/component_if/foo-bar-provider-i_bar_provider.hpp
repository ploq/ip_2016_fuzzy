#ifndef FOO-BAR-REQUIRER-I_BAR_REQUIRER_HPP
#define FOO-BAR-REQUIRER-I_BAR_REQUIRER_HPP

#include "foo-bar-requirer-i_bar.hpp"

namespace Foo {

namespace Bar {

namespace Provider {

class I_Bar_Provider {
public:
    I_Bar_Provider();
    virtual ~I_Bar_Provider() = 0;

    virtual void Init() = 0;
    virtual Foo::Bar::Provider::I_Bar& Get_Port() = 0;

private:
    I_Bar_Provider(const I_Bar_Provider&);
    const I_Bar_Provider& operator=(const I_Bar_Provider&);
};

} // NS: Provider

} // NS: Bar

} // NS: Foo

#endif // FOO-BAR-REQUIRER-I_BAR_REQUIRER_HPP
