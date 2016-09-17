#ifndef FOO-BAR-REQUIRER-I_BAR_REQUIRER_FACTORY_HPP
#define FOO-BAR-REQUIRER-I_BAR_REQUIRER_FACTORY_HPP

#include "foo-bar-requirer-i_bar_requirer.hpp"
#include <string>

namespace Foo {

namespace Bar {

namespace Provider {

I_Bar_Provider& Create_Instance(const std::string& name);

} // NS: Provider

} // NS: Bar

} // NS: Foo

#endif // FOO-BAR-REQUIRER-I_BAR_REQUIRER_FACTORY_HPP
