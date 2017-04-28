 
#include "portstorage.hpp"

#include <vector>
#include <map>
#include <iostream>

static std::vector<I_Regeneratable*> regeneratables;
static std::vector<std::string> names;

void PortStorage::AddRegeneratable(I_Regeneratable* regen, std::string name)
{
    regeneratables.push_back(regen);
    
    //Comp names, can be good for logging purposes? Remove?
    names.push_back(name);
}

//Non-static
void PortStorage::Regenerate()
{
    for (unsigned int i = 0; i < regeneratables.size(); ++i)
    {
	regeneratables[i]->Regenerate();
    }
}

//Static values
void PortStorage::Regenerate(const std::map<std::string, std::map<std::string, std::vector<std::vector<int>>>> &namespaces)
{
    for (unsigned int i = 0; i < regeneratables.size(); ++i)
    {
	if (namespaces.count(regeneratables[i]->getNamespace()) > 0) {
	    regeneratables[i]->Regenerate(namespaces.at(regeneratables[i]->getNamespace()));
	}
	else {
	    /*
	      Start using non-static function chain if 
	      there is no static values to be set.
	    */
	    regeneratables[i]->Regenerate();
	}
    }
}

void PortStorage::CleanUp()
{
    for (unsigned int i = 0; i < regeneratables.size(); ++i)
    {
	delete regeneratables[i];
    }
    regeneratables.clear();
    names.clear();
}
 
