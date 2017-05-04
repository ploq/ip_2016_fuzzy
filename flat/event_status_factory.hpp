namespace Foo {
    namespace Event {
	namespace Provider {
	    class I_Event_Provider{
	    public:
		I_Event() = default;
		virtual ~I_Event();
		virtual bool Is_Client_Connected(std::string client_name) const; //random
		virtual unsigned Get_Client_Id(std::string client_name) const; //always coherent!
		virtual const std::string Get_Client_Name(const unsigned client_id) const; //always coherent!
		virtual unsigned Get_Number_Of_Clients() const; //always coherent!
		virtual void Event_Event(const unsigned client_id, int event_id, const int curr_cycles) = 0; //clients are coherent!
		virtual unsigned Get_Event__Bandwidth(const unsigned int client_id) const;
		
	    private:
		std::map<std::string, unsigned> clients;
	    }

	}
    }
}
