#ifndef FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_HPP 
#define FOO_EVENT_STATUS_PROVIDER_I_EVENT_STATUS_HPP 

#include <string>

namespace Foo {
    namespace Event_Status {
	namespace Provider {
	    class I_Event_Status {
	    public:
		I_Event_Status();
		virtual ~I_Event_Status();
		virtual bool Is_Client_Connected(std::string client_name) const; //random
		virtual unsigned Get_Client_Id(std::string client_name) const; //always coherent!
		virtual const std::string Get_Client_Name(const unsigned client_id) const; //always coherent!
		virtual unsigned Get_Number_Of_Clients() const; //always coherent!
		//virtual void Event_Event(const unsigned client_id, int event_id, const int curr_cycles) = 0; //clients are coherent!
		virtual unsigned Get_Event__Bandwidth(const unsigned int client_id) const;
	    private:
		I_Event_Status(const I_Event_Status&);
		const I_Event_Status& operator=(const I_Event_Status&);
	    };
	} //NS:Provider
    } //NS:Event_Status
} //NS:Foo
#endif 

