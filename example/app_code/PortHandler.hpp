#include <map>

template<typename Value, typename Key>
class PortHandler
{
public:
   PortHandler() {}
   ~PortHandler() {}

   void* getPort(Key key)
   {
      if (m_ports.find(key) != m_ports.end())
      {
	 return m_ports[key];
      } else
      {
	 m_ports[key] = Value();
	 return m_ports[key];
      }
   }
private:
   std::map<Key, Value> m_ports;
};

template<typename Value, typename Key>
Value& GetPort(Key key)
{
   static PortHandler<Value, Key> portHandler;
   return *((Key*)portHandler.getPort(key));
}
