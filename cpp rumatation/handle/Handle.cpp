#include "Handle.h"

Handle::Handle():m_up(0) { }

Handle::Handle(int x, int y):m_up(new UPoint(x, y)) { }

Handle::Handle(const Point &p):m_up(new UPoint(p)) { }

Handle::Handle(const Handle &h):m_up(h.m_up) { ++h.m_up->u; }

Handle::~Handle()
{
    if (--m_up->u == 0)
    {
        delete m_up;
    }
}

Handle& Handle::operator=(const Handle &h)
{
    ++h.m_up->u;
    if (--m_up->u == 0)
    {
        delete m_up;
    }
    m_up = h.m_up;
    return *this;
}

int Handle::x() const
{
    return m_up->m_p.x();
}

int Handle::y() const
{
    return m_up->m_p.y();
}

/*
//指针语义
Handle& Handle::x(int x)
{
    m_up->m_p.x(x);
    return *this;
}
Handle& Handle::y(int y)
{
    m_up->m_p.y(y);
    return *this;
}
*/
//值语义
Handle& Handle::x(int x)
{
    if (m_up->u != 1)
    {
        --m_up->u;
        m_up = new UPoint(m_up->m_p);
    }
    m_up->m_p.x(x);
    return *this;
}

Handle& Handle::y(int y)
{
    if (m_up->u != 1)
    {
        --m_up->u;
        m_up = new UPoint(m_up->m_p);
    }
    m_up->m_p.y(y);
    return *this;
}
