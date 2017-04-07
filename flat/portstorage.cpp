 
#include "portstorage.hpp"
#include "logger.hpp"

#include <vector>

static std::vector<I_Regeneratable*> regeneratables;
static std::vector<std::string> names;

void PortStorage::AddRegeneratable(I_Regeneratable* regen, std::string name)
{
    regeneratables.push_back(regen);
    names.push_back(name);
}

void PortStorage::Regenerate()
{
    for (unsigned int i = 0; i < regeneratables.size(); ++i)
    {
	Logger::log(names[i] + ":");
	regeneratables[i]->Regenerate();
    }
}

void PortStorage::CleanUp()
{
    for (unsigned int i = 0; i < regeneratables.size(); ++i)
    {
	delete regeneratables[i];
    }
}
 
