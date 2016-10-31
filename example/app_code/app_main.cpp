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
/*Scheduler::Scheduler() 
{
	_V0_gen = 0;
	_V1_gen = 0;
	_V2_gen = 0;
}

AFL::AFL(std::string afl_data) {
    /*int d;
    syscall(SYS_getrandom, (void*)&d, sizeof(d), 0);//rand() % (afl_data.length() - sizeof(parameters) - 1);
    if (afl_data.length() < sizeof(parameters) - 1)
    {
        d = 0;
    }
    else
    {
        d = (d % (afl_data.length() - sizeof(parameters) - 1)) + 1;
    }
    params = *((parameters*) afl_data.c_str() );//+ d);
}

unsigned int AFL::getSeed() {
    return params.seed;
}

unsigned int AFL::getCycles() {
    return params.cycles;
}

char AFL::getRandType() {
    return params.randtype;
}

void Scheduler::updateIO() {
    Foo::Bar::FumT& fum = comp_y->Get_Port().Get_Fum();
    fum.V0 = rand() % INT32_MAX;

    Foo::Bar::FunT& fun = comp_z->Get_Port().Get_Foo();
    fun.V0 = rand() % INT32_MAX;
    fun.V1 = rand() % 10 + -1;
    fun.V2 = 5;
    fun.V3 = rand() % 50000;
    fun.V4.P0 = rand();
    fun.V4.P1 = rand() % 50000;
    //fun.V5 = 0;
    //fun.V6 = 10;

    return;
}*/

int main(int argc, char **argv)
{
    //parameters oldparams;

    //while(__AFL_LOOP(1000)) {
        
        std::string afl_data;
        std::ofstream output_file("output.txt", std::ios_base::app);
        Scheduler sched;
        std::cin >> afl_data;
        if (afl_data.size() < sizeof(parameters)) return 0;
        AFL afl(afl_data);

        /*if (afl.getSeed() == 0 || afl.getCycles() == 0)
        {
            continue;
        }*/

        srand(afl.getSeed());

        APP_Name_Initialize();
        sched.updateIO(1,2,3); //--> Should retrieve data from AFL

        for (int n = 0; n < 10000; n++) {
            APP_Name_Execute();
            sched.updateIO(1,2,3); //V1 as constant, maybe autogenerate parameters?????
        }
        APP_Name_Terminate();
        output_file << afl.getCycles() << " " << afl.getSeed() << std::endl;
        output_file.close();
    //}

	
    return 0;
}