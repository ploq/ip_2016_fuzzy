#include "portenvironment.hpp"

#include "PortStorage.hpp"

PortEnvironment::PortEnvironment()
{
}

bool PortEnvironment::init()
{
    return true;
}

void PortEnvironment::quit()
{
}

void PortEnvironment::regenerate()
{
    PortStorage::Regenerate();
}

/*template <typename ReturnType, typename PortBaseType, typename PortType, typename KeyType>
ReturnType& PortEnvironment::createPort(KeyType key, std::string name)
{
    return *(new ReturnType((PortBaseType*)GetPort<PortType, KeyType>(key, name)));
}*/
