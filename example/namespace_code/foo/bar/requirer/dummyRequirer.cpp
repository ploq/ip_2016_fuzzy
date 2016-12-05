#include "foo-bar-requirer-i_bar_requirer_factory.hpp"
#include "foo-bar-requirer-i_bar_requirer.hpp"
#include "foo-bar-requirer-i_bar.hpp"
#include "foo-bar-types.hpp"
#include "testingenvironment.hpp"
#include "portenvironment.hpp"

//Allting genereras i dextool

namespace Foo {

    namespace Bar {

	namespace Requirer {
	    I_Bar::I_Bar() {}
	    I_Bar::~I_Bar() {}
	    I_Bar_Requirer::I_Bar_Requirer() {}
	    I_Bar_Requirer::~I_Bar_Requirer() {}
	    class Bar_Impl : public I_Bar {
	    public:
		Bar_Impl() 
		    {
			randomGenerator = &TestingEnvironment::createRandomGenerator("Requirer");
		    }
		~Bar_Impl() {}
		const Foo::Bar::FunT& Get_Foo() const {return foo;}
		int64_t Get_Foo_V0() const {return foo.V0;}
		Foo::Bar::MyIntT Get_Foo_V1() const {return foo.V1;}
		Foo::Bar::MyIntT Get_Foo_V2() const {return foo.V2;}
		Foo::MyHeightT Get_Foo_V3() const {return foo.V3;}
		const Foo::BundleT& Get_Foo_V4() const {return foo.V4;}
		Foo::SimpleT::Enum Get_Foo_V5() const {return foo.V5;}
		Foo::WithHolesT::Enum Get_Foo_V6() const {return foo.V6;}

		Foo::Bar::FumT& Get_Fum () {return fum;}
		void Put_Fum(const int64_t V0) {}

		void Regenerate()
		    { 
			fum.V0 = randomGenerator->generate("Requirer fum V0");
			foo.V0 = randomGenerator->generate("Requirer foo V0");
			foo.V1 = randomGenerator->generate("Requirer foo V1", 0, 100000); //TODO: REMOVE
			foo.V2 = randomGenerator->generate("Requirer foo V2", 0, 100000); //TODO: REMOVE
			foo.V3 = randomGenerator->generate("Requirer foo V3");
			foo.V4.P0 = randomGenerator->generate("Requirer foo V4 P0");
			foo.V4.P1 = randomGenerator->generate("Requirer foo V4 P1");
			foo.V5 = static_cast<Foo::SimpleT::Enum>(randomGenerator->generate("Requirer foo V5") % 3);
			foo.V6 = static_cast<Foo::WithHolesT::Enum>((randomGenerator->generate("Requirer foo V6") % 10) + 1);
		    }
	    private:
		Foo::Bar::FumT fum;
		Foo::Bar::FunT foo;
		
		RandomGenerator* randomGenerator;
	    };

	    class Bar_Requirer_Impl : public I_Bar_Requirer {
	    public:
		~Bar_Requirer_Impl() {}
		Bar_Requirer_Impl() {}
		Bar_Requirer_Impl(I_Bar* p) {port=p;}
		void Init() {}
		Foo::Bar::Requirer::I_Bar& Get_Port() {return *port;}
	    private:
		I_Bar *port;
	    };

	    I_Bar_Requirer& Create_Instance(const std::string& name) {
		return PortEnvironment::createPort<Bar_Requirer_Impl, I_Bar, Bar_Impl, std::string>(name, name);
	    }
	}
    }
}
