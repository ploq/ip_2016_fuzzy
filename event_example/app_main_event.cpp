#include "foo-event_status-provider-i_event_status_factory.hpp"

#include "app_main_event.hpp"

#include <random>


namespace {

// For simplicities global variables are used.
// But normally they are encapsulated in a top component/class.
    Foo::Event_Status::Provider::I_Event_Status_Provider* comp_x;
    Foo::Event_Status::Provider::I_Event_Status_Provider* comp_y;

    Foo::Event_Status::Provider::I_Event_Status* port_x;
    Foo::Event_Status::Provider::I_Event_Status* port_y;



} // NS:

void APP_Name_Initialize() {
    comp_x = &Foo::Event_Status::Provider::Create_Instance("X");
    comp_y = &Foo::Event_Status::Provider::Create_Instance("Y");
    //comp_z->Init();
    port_x = &comp_x->Get_Port();
    port_y = &comp_y->Get_Port();
}

void APP_Name_Execute() {

    comp_x->Connect_Port(*port_y);
}

void APP_Name_Terminate() {
    delete comp_x;
    delete comp_y;

    // note that port_y/x is NOT deleted.
}
