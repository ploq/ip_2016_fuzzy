#include <map>
#include "PortStorage.hpp"

template<typename Value, typename Key>
class PortHandler
{
public:
    PortHandler() {}
    ~PortHandler() 
	{
	    for (typename std::map<Key, Value*>::iterator it = m_ports.begin(); it != m_ports.end(); ++it)
	    {
		delete it->second;
	    }
	}

    void* getPort(Key key)
	{
	    typename std::map<Key, Value*>::iterator it = m_ports.find(key);
	    if (it != m_ports.end())
	    {
		return (void*)m_ports[key];
	    }
	    else
	    {
		Value* val = new Value();
		m_ports[key] = val;
		PortStorage::AddRegeneratable(new Regeneratable_Impl<Value*>(val));
		return (void*)m_ports[key];
	    }
	}

    void RegeneratePorts()
	{
	    for (typename std::map<Key, Value*>::iterator it = m_ports.begin(); it != m_ports.end(); ++it)
	    {
		it->second->Regenerate();
	    }
	}
private:
    std::map<Key, Value*> m_ports;
};

template<typename Value, typename Key>
Value* GetPort(Key key)
{
    static PortHandler<Value, Key> portHandler;
    return ((Value*)portHandler.getPort(key));
}
