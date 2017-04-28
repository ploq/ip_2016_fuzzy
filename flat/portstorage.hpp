#ifndef PORTSTORAGE_HPP
#define PORTSTORAGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <map>

class I_Regeneratable
{
public:
    virtual ~I_Regeneratable() {}
    virtual void Regenerate() = 0;
    virtual void Regenerate(const std::map<std::string, std::vector<std::vector<int>>> &vars) = 0;
    virtual std::string getNamespace() = 0;
};

template<class P>
class Regeneratable_Impl : public I_Regeneratable
{
public:
    Regeneratable_Impl(P pp)
    {
	p = pp;
    }

    ~Regeneratable_Impl()
    {
	   
    }
    
    //Non-static
    void Regenerate()
    {
	p->Regenerate();
    }

    //Static
    void Regenerate(const std::map<std::string, std::vector<std::vector<int>>> &vars)
    {
	p->Regenerate(vars);
    }

    std::string getNamespace() 
    {
	return p->getNamespace();
    }

private:
    P p;
};

namespace PortStorage //TODO: Put in a class, with destructors and such
{
    void AddRegeneratable(I_Regeneratable* regen, std::string name);
    void Regenerate();
    void Regenerate(const std::map<std::string, std::map<std::string, std::vector<std::vector<int>>>> &namespaces);
    void CleanUp(); 
}

#endif
