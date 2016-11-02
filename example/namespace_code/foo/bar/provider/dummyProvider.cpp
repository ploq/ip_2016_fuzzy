#include "foo-bar-provider-i_bar_provider_factory.hpp"
#include "foo-bar-provider-i_bar_provider.hpp"
#include "foo-bar-provider-i_bar.hpp"
#include "foo-bar-types.hpp"
#include "PortHandler.hpp"

namespace Foo {

  namespace Bar {

    namespace Provider {
      I_Bar::I_Bar() {}
      I_Bar::~I_Bar() {}
      I_Bar_Provider::I_Bar_Provider() {}
      I_Bar_Provider::~I_Bar_Provider() {}
      class Bar_Impl : public I_Bar {
      public:
	Bar_Impl() {}
	~Bar_Impl() {}
	Foo::Bar::FunT& Get_Foo() {return foo;}
	void Put_Fun(const int64_t V0, const Foo::Bar::MyIntT V1, const Foo::Bar::MyIntT V2, const Foo::MyHeightT V3, const Foo::BundleT& V4, const Foo::SimpleT::Enum V5, const Foo::WithHolesT::Enum V6) {}
	const Foo::Bar::FumT& Get_Fum () const {return fum;}
	int64_t Get_Fum_V0() const {return fum.V0;}

	  void Regenerate()
	      {
	      }
      private:
	Foo::Bar::FumT fum;
	Foo::Bar::FunT foo;
      };

      class Bar_Provider_Impl : public I_Bar_Provider {
      public:
	~Bar_Provider_Impl() {}
	Bar_Provider_Impl() {}
	Bar_Provider_Impl(I_Bar* p) {port=p;}
	void Init() {}
	Foo::Bar::Provider::I_Bar& Get_Port() {return *port;}
      private:
	I_Bar *port;
      };

      I_Bar_Provider& Create_Instance(const std::string& name) {
        return *(new Bar_Provider_Impl((I_Bar*)GetPort<Bar_Impl, std::string>(name)));
      }
    }
  }
}
