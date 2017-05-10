#include "foo-event_status-provider-i_event_status_factory.hpp"

#include "app_main_event.hpp"

#include <random>


namespace {

// For simplicities global variables are used.
// But normally they are encapsulated in a top component/class.
Foo::Event_Status::Provider::I_Event_Status_Provider* comp_z;

Foo::Event_Status::Provider::I_Event_Status* port_z;



} // NS:

void APP_Name_Initialize() {
    comp_z = &Foo::Event_Status::Provider::Create_Instance("Z");
    //comp_z->Init();
    port_z = &comp_z->Get_Port();
}

void APP_Name_Execute() {

    //port_z->Get_Fun().V1 = comp_x->Get_Port().Get_Fun_V1();
}

void APP_Name_Terminate() {
    delete comp_z;

    // note that port_z is NOT deleted.
}
