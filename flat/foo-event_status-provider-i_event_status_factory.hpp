#ifndef FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_FACTORY_HPP 
#define FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_FACTORY_HPP 

#include "foo-event_status-provider-i_event_status_provider.hpp"
#include <string>

namespace Foo {

namespace Event_Status {

namespace Provider {

I_Event_Status_Provider& Create_Instance(const std::string& name);

} // NS: Provider

} // NS: Event_Status

} // NS: Foo

#endif // FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_FACTORY_HPP
