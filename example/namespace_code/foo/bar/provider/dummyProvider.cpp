#include "foo-bar-provider-i_bar_provider_factory.hpp"
#include "foo-bar-provider-i_bar_provider.hpp"
#include "foo-bar-provder-i_bar.hpp"
#include "foo-bar-types.hpp"

namespace Foo {

  namespace Bar {

    namespace Provider {
      class I_Bar_Impl : public I_Bar {
      public:
	Foo::Bar::FunT& Get_Foo() {return foo;}
	void Put_Fun(const int64_t V0, const Foo::Bar::MyIntT V1, const Foo::Bar::MyIntT V2, const Foo::MyHeightT V3, const Foo::BundleT& V4, const Foo::SimpleT::Enum V5, const Foo::WithHolesT::Enum V6) {
	  foo.V0 = V0;
	  foo.V1 = V1;
	  foo.V2 = V2;
	  foo.V3 = V3;
	  foo.V4 = V4;
	  foo.V5 = V5;
	  foo.V6 = V6;
	}
	const Foo::Bar::FumT& Get_Fum () {return fum;}
	int64_t Gem_Fum_V0() {return fum.V0;}
      private:
	Foo::Bar::FumT fum;
	Foo::Bar::FunT foo;
      };

      class I_Bar_Provider_Impl : public I_Bar_Provider {
      public:
	~I_Bar_Provider() {}
	I_Bar_Provider() {port=0;}
	void Init() {port = 0;}
	Foo::Bar::Provider::I_Bar& Get_Port() {return port;}
      private:
	I_Bar port;
      };

      I_Bar_Provider& Create_Instance(const std::string& name) {
	return new I_Bar_Provider;
      };
    }
  }
}
