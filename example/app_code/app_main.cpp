#include "foo-bar-requirer-i_bar_requirer_factory.hpp"
#include "foo-bar-provider-i_bar_provider_factory.hpp"

#include "scheduler.hpp"
#include "afllib.hpp"

#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <linux/random.h>
#include <sys/syscall.h>
#include <ctime>
#include "app_main.hpp"
#include "PortStorage.hpp"
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

void updateIO()
{
    PortStorage::Regenerate();
    //((Foo::Bar::Requirer::Bar_Impl*)(comp_x->Get_Port())).Regenerate();
    //((Foo::Bar::Requirer::Bar_Impl*)(comp_y->Get_Port())).Regenerate();
    //((Foo::Bar::Provider::Bar_Impl*)(comp_z->Get_Port())).Regenerate();
}


int main(int argc, char **argv)
{        
    std::string afl_data;
    std::ofstream output_file("output.txt", std::ios_base::app);
    Scheduler sched;
    std::cin >> afl_data;
    if (afl_data.size() < sizeof(parameters)) return 0;
    AFL afl(afl_data);


    srand(afl.getSeed());

    APP_Name_Initialize();
    PortStorage::Regenerate();//sched.updateIO(1,2,3); //--> Should retrieve data from AFL

    for (int n = 0; n < 10000; n++) {
	APP_Name_Execute();
	PortStorage::Regenerate();//sched.updateIO(1,2,3); //V1 as constant, maybe autogenerate parameters?????
    }
    APP_Name_Terminate();
    output_file << afl.getCycles() << " " << afl.getSeed() << std::endl;
    output_file.close();


	
    return 0;
}
