#include "foo-bar-requirer-i_bar_requirer_factory.hpp"
#include "foo-bar-provider-i_bar_provider_factory.hpp"

#include "app_main.hpp"

#include <random>


namespace {

// For simplicities global variables are used.
// But normally they are encapsulated in a top component/class.
Foo::Bar::Requirer::I_Bar_Requirer* comp_x;
Foo::Bar::Requirer::I_Bar_Requirer* comp_y;
Foo::Bar::Provider::I_Bar_Provider* comp_z;

Foo::Bar::Provider::I_Bar* port_z;

    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0,8000); // guaranteed unbiased



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

    if (comp_y->Get_Port().Get_Fun().V0 == 1337) {
	if (comp_x->Get_Port().Get_Fun().V0 == 1337) {
	    comp_y->Get_Port().Put_Fum(uni(rng));
	}
    }
    
    //ERRORS
    /*if (comp_x->Get_Port().Get_Fun_V0() / comp_y->Get_Port().Get_Fum().V0 > 2) {
        comp_y->Get_Port().Get_Fum().V0 = 42;
    }
    */
    //------

    port_z->Get_Fun().V1 = comp_x->Get_Port().Get_Fun_V1();
}

void APP_Name_Terminate() {
    delete comp_x;
    delete comp_y;
    delete comp_z;

    // note that port_z is NOT deleted.
}
