#ifndef FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_PROVIDER_HPP
#define FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_PROVIDER_HPP

#include "foo-event_status-provider-i_event_status.hpp"

namespace Foo {

namespace Event_Status {

namespace Provider {

class I_Event_Status_Provider {
public:
    I_Event_Status_Provider();
    virtual ~I_Event_Status_Provider() =0;
    virtual Foo::Event_Status::Provider::I_Event_Status& Get_Port() = 0;
    virtual void Connect_Port(Foo::Event_Status::Provider::I_Event_Status& Other_End) = 0;

private:
    I_Event_Status_Provider(const I_Event_Status_Provider&);
    const I_Event_Status_Provider& operator=(const I_Event_Status_Provider&);
};

} // NS: Provider

} // NS: Event_Status

} // NS: Foo

#endif // FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_PROVIDER_HPP
