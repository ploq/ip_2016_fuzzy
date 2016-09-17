#ifndef FOO-BAR-REQUIRER-I_BAR_REQUIRER_HPP
#define FOO-BAR-REQUIRER-I_BAR_REQUIRER_HPP

#include "foo-bar-requirer-i_bar.hpp"

namespace Foo {

namespace Bar {

namespace Requirer {

class I_Bar_Requirer {
public:
    I_Bar_Requirer();
    virtual ~I_Bar_Requirer() = 0;

    virtual void Init() = 0;
    virtual Foo::Bar::Requirer::I_Bar& Get_Port() = 0;

private:
    I_Bar_Requirer(const I_Bar_Requirer&);
    const I_Bar_Requirer& operator=(const I_Bar_Requirer&);
};

} // NS: Requirer

} // NS: Bar

} // NS: Foo

#endif // FOO-BAR-REQUIRER-I_BAR_REQUIRER_HPP
