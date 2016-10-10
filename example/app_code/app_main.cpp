#include "foo-bar-requirer-i_bar_requirer_factory.hpp"
#include "foo-bar-provider-i_bar_provider_factory.hpp"

#include <iostream>
#include <cstdlib>
#include "app_main.hpp"
namespace {

// For simplicities global variables are used.
// But normally they are encapsulated in a top component/class.
Foo::Bar::Requirer::I_Bar_Requirer* comp_x;
Foo::Bar::Requirer::I_Bar_Requirer* comp_y;
Foo::Bar::Provider::I_Bar_Provider* comp_z;

Foo::Bar::Provider::I_Bar* port_z;

} // NS:

void APP_Name_Initialize() {
    comp_x = &Foo::Bar::Requirer::Create_Instance("X");
    comp_x->Init();

    comp_y = &Foo::Bar::Requirer::Create_Instance("Y");
    comp_y->Init();

    comp_z = &Foo::Bar::Provider::Create_Instance("Z");
    comp_z->Init();
    port_z = &comp_z->Get_Port();
}

void APP_Name_Execute() {
    if (comp_x->Get_Port().Get_Foo().V0 > 2) {
        comp_y->Get_Port().Get_Fum().V0 = 42;
    }

    port_z->Get_Foo().V1 = comp_x->Get_Port().Get_Foo_V1();
}

void APP_Name_Terminate() {
    delete comp_x;
    delete comp_y;
    delete comp_z;

    // note that port_z is NOT deleted.
}
Scheduler::Scheduler() 
{
	_V0_gen = 0;
	_V1_gen = 0;
	_V2_gen = 0;
}

AFL::AFL(std::string afl_data) {
    params = *((parameters*) afl_data.c_str());
}

int AFL::getSeed() {
    return params.seed;
}

int AFL::getCycles() {
    return params.cycles;
}

char AFL::getRandType() {
    return params.randtype;
}

void Scheduler::updateIO() {
    return;
}

int main(int argc, char **argv)
{
    while(__AFL_LOOP(1000)) {
        std::string afl_data;

        Scheduler sched;
        std::cin >> afl_data;
        AFL afl(afl_data);

        srand(afl.getSeed());

        APP_Name_Initialize();
        sched.updateIO(); //--> Should retrieve data from AFL

        for (int n = 0; n < afl.getCycles() % 100; n++) {
            APP_Name_Execute();
            sched.updateIO(); //V1 as constant, maybe autogenerate parameters?????
        }
        APP_Name_Terminate();
    }

	
    return 0;
}