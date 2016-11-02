#include "PortStorage.hpp"

#include <vector>

static std::vector<I_Regeneratable*> regeneratables;

void PortStorage::AddRegeneratable(I_Regeneratable* regen)
{
    regeneratables.push_back(regen);
}

void PortStorage::Regenerate()
{
    for (unsigned int i = 0; i < regeneratables.size(); ++i)
    {
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
