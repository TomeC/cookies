#include "newHandle.h"

UseCount::UseCount(): m_u(new int(1)) { }

UseCount::UseCount(const UseCount& u): m_u(u.m_u) { ++*m_u; }

UseCount::~UseCount() 
{
        if (--*m_u == 0)
        {
                delete m_u;
        }
}

bool UseCount::reattach(const UseCount& u)
{
        ++*u.m_u;
        if (--m_u == 0)
        {
                delete m_u;
                m_u = u.m_u;
                return true;
        }
        m_u = u.m_u;
        return false;
}
bool UseCount::makeOnly()
{
        if (*m_u == 1)
        {
                return false;
        }
        m_u = new int(1);
        return true;
}
newHandle::~newHandle()
{
        if (m_u.only())
        {
                delete m_p;
        }
}
newHandle& newHandle::operator=(const newHandle& h)
{
        if (m_u.reattach(h.m_u))
        {
                delete m_p;
        }
        m_p = h.m_p;
        return *this;
}

newHandle& newHandle::x(int xval)
{
        if (m_u.makeOnly())
        {
                m_p = new Point(*m_p);
        }
        m_p->x(xval);
        return *this;
}
newHandle& newHandle::y(int yval)
{
        if (m_u.makeOnly())
        {
                m_p = new Point(*m_p);
        }
        m_p->y(yval);
        return *this;
}