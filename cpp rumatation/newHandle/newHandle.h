#ifndef _NEW_HANDLE_H_
#define _NEW_HANDLE_H_ value

class Point
{
public:
        Point(): m_x(0), m_y(0) { }
        Point(int x, int y): m_x(x), m_y(y) { }
        int x() { return m_x; }
        int y() { return m_y; }
        Point& x(int xval) { m_x = xval; return *this; }
        Point& y (int yval) { m_y = yval; return *this; }
        ~Point() { }
private:
        int m_x;
        int m_y;
};

class UseCount
{
public:
        UseCount();
        UseCount(const UseCount&);
       
        ~UseCount();
        
        bool only() { return *m_u == 1; }
        bool reattach(const UseCount&);
        bool makeOnly();
private:
        int *m_u;
        UseCount& operator=(const UseCount&);
};

class newHandle
{
public:
        newHandle(): m_p(0) { }
        newHandle(int xval, int yval): m_p(new Point(xval, yval)) { }
        newHandle(const Point& pt): m_p(new Point(pt)) { }
        newHandle(const newHandle& h): m_p(h.m_p), m_u(h.m_u) { }
        newHandle& operator=(const newHandle&);
        ~newHandle();
        
        int x() { return m_p->x(); }
        int y() { return m_p->y(); }
        newHandle& x(int xval);
        newHandle& y(int yval);
private:
        Point *m_p;
       UseCount m_u; 
};

#endif