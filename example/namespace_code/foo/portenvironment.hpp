#ifndef PORTENVIRONMENT_HPP
#define PORTENVIRONMENT_HPP

#include <string>
#include "PortHandler.hpp"

class PortEnvironment
{
public:
    PortEnvironment();
    static bool init();
    static void quit();
    static void regenerate();
    template <typename ReturnType, typename PortBaseType, typename PortType, typename KeyType>
    static ReturnType& createPort(KeyType key, std::string name)
    {
	return *(new ReturnType((PortBaseType*)GetPort<PortType, KeyType>(key, name)));
    }

private:
};

#endif
