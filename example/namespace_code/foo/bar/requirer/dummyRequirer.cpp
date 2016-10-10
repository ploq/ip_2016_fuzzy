#include "foo-bar-requirer-i_bar_requirer_factory.hpp"
#include "foo-bar-requirer-i_bar_requirer.hpp"
#include "foo-bar-requirer-i_bar.hpp"
#include "foo-bar-types.hpp"

namespace Foo {

  namespace Bar {

    namespace Requirer {
      I_Bar::I_Bar() {}
      I_Bar::~I_Bar() {}
      I_Bar_Requirer::I_Bar_Requirer() {}
      I_Bar_Requirer::~I_Bar_Requirer() {}
      class I_Bar_Impl : public I_Bar {
      public:
	I_Bar_Impl() {}
	~I_Bar_Impl() {}
	const Foo::Bar::FunT& Get_Foo() const {return foo;}
	int64_t Get_Foo_V0() const {return foo.V0;}
	Foo::Bar::MyIntT Get_Foo_V1() const {return foo.V1;}
	Foo::Bar::MyIntT Get_Foo_V2() const {return foo.V2;}
        Foo::MyHeightT Get_Foo_V3() const {return foo.V3;}
	const Foo::BundleT& Get_Foo_V4() const {return foo.V4;}
	Foo::SimpleT::Enum Get_Foo_V5() const {return foo.V5;}
	Foo::WithHolesT::Enum Get_Foo_V6() const {return foo.V6;}

	Foo::Bar::FumT& Get_Fum () {return fum;}
	void Put_Fum(const int64_t V0) {foo.V0=V0;}
      private:
	Foo::Bar::FumT fum;
	Foo::Bar::FunT foo;
      };

      class I_Bar_Requirer_Impl : public I_Bar_Requirer {
      public:
	~I_Bar_Requirer_Impl() {}
	I_Bar_Requirer_Impl() {port=0;}
	void Init() {port = new I_Bar_Impl();}
	Foo::Bar::Requirer::I_Bar& Get_Port() {return *port;}
      private:
	I_Bar *port;
      };

      I_Bar_Requirer& Create_Instance(const std::string& name) {
	return *(new I_Bar_Requirer_Impl);
      }
    }
  }
}
