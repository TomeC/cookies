#ifndef _EXPR_H_
#define _EXPR_H_

#include <iostream>
using namespace std;

class ExprNode;
class Expr
{
        friend ostream& operator<< (ostream&, const Expr&);
public:
        Expr (int);
        Expr (const char&, Expr);
        Expr (const char&, Expr, Expr);
        Expr (const Expr& t);
        Expr& operator= (const Expr&);
        ~Expr ();
private:
        ExprNode *p;  
};
class ExprNode
{
        friend ostream& operator<<(ostream&, const Expr&);
        friend class Expr;
protected:
        ExprNode (): use (1) { }
        virtual void print (ostream&) const = 0;
        virtual ~ExprNode () { }
private:
        int use;
};

class IntNode: public ExprNode
{
 private:
        friend class Expr;
        int m_n;
        
        IntNode (int n): m_n (n) { }
        void print (ostream& out) const { out<<m_n; }      
};

class UnaryNode: public ExprNode
{
private:
        friend class Expr;
        UnaryNode (const char &op, const Expr& b): m_op (op), m_opnd (b) { }
        void print (ostream& out) const { out<<"("<<m_op<<m_opnd<<")"; }      
private:
        char m_op;
        Expr m_opnd;
};   

class BinaryNode: public ExprNode
{
        friend class Expr;
private:
        BinaryNode (const char& op, Expr& b, Expr& c): m_op (op), 
                m_left (b), m_right (c) { }
        void print (ostream& out) const { out<<"("<<m_left<<m_op<<m_right<<")"; }
private:
        char m_op;
        Expr m_left;
        Expr m_right;
};

#endif