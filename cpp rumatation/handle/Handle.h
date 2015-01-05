#ifndef _HANDLE_H_
#define _HANDLE_H_
class Handle;
class Point
{
public:
    Point():m_x(0), m_y(0) { }
    Point(int x, int y):m_x(x), m_y(y) { }
    Point(const Point &p):m_x(p.m_x), m_y(p.m_y) { }
    int x() const { return m_x; }
    int y() const { return m_y; }
    Point& x(int ix) { m_x = ix; return *this; }
    Point& y(int iy) { m_y = iy; return *this; }
private:
    int m_x;
    int m_y;
};

class UPoint
{
    friend class Handle;
private:
    UPoint():u(1) { }
    UPoint(const Point &up):m_p(up), u(1) { }
    UPoint(int x, int y):m_p(x, y), u(1) {}
private:
    Point m_p;
    int u;
};

class Handle
{
public:
    Handle();
    Handle(int, int);
    Handle(const Point &);
    Handle(const Handle &);
    Handle& operator=(const Handle &);
    ~Handle();
    //call function
    int x() const;
    int y() const;
    Handle& x(int);
    Handle& y(int);
private:
    UPoint* m_up;
};
#endif