#include "expr.h"

Expr::Expr (int n)
{
        p = new IntNode (n);
}
Expr::Expr (const char& op, Expr t)
{
        p = new UnaryNode (op, t);
}
Expr::Expr (const char& op, Expr left, Expr right)
{
        p = new BinaryNode (op, left, right);
}
Expr::Expr (const Expr& t)
{ 
        p = t.p;
         ++p->use; 
 }
Expr::~Expr () 
{ 
        if (--p->use == 0) 
                delete p;
}
Expr& Expr::operator= (const Expr& rhs)
{
        rhs.p->use++;
        if (--p->use == 0)
                delete p;
        p = rhs.p;
        return *this;
}
ostream& operator<< (ostream& out, const Expr& t)
{
        t.p->print (out);
        return out;
}