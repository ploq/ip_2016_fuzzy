#ifndef PORTSTORAGE_HPP
#define PORTSTORAGE_HPP

class I_Regeneratable
{
public:
    virtual ~I_Regeneratable() {}
    virtual void Regenerate() = 0;
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

    void Regenerate()
	{
	    p->Regenerate();
	}

private:
    P p;
};

namespace PortStorage
{
    void AddRegeneratable(I_Regeneratable* regen);
    void Regenerate();
}

#endif
