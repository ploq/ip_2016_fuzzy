#include "ops_mode-ops_state-requirer-i_ops_state_factory.hpp"
#include "ops_mode-ops_state-provider-i_ops_state_factory.hpp"

#include "app_main_monitored.hpp"


namespace {

// For simplicities global variables are used.
// But normally they are encapsulated in a top component/class.
Ops_Mode::Ops_State::Requirer::I_Ops_State_Requirer* comp_x;
Ops_Mode::Ops_State::Provider::I_Ops_State_Provider* comp_y;

Ops_Mode::Ops_State::Requirer::I_Ops_State* port_x;
Ops_Mode::Ops_State::Provider::I_Ops_State* port_y;



} // NS:

void APP_Name_Initialize() {
    comp_x = &Ops_Mode::Ops_State::Requirer::Create_Instance("X");
    comp_y = &Ops_Mode::Ops_State::Provider::Create_Instance("Y");
    //comp_z->Init();
    port_x = &comp_x->Get_Port();
    port_y = &comp_y->Get_Port();
}

void APP_Name_Execute() {

    //port_z->Get_Fun().V1 = comp_x->Get_Port().Get_Fun_V1();
}

void APP_Name_Terminate() {
    delete comp_x;
    delete comp_y;

    // note that port_y is NOT deleted.
}
