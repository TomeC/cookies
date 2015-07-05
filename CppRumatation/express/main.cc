#include "expr.h"
#include <iostream>
using namespace std;

int main ()
{
        Expr t = Expr ('*', Expr ('-', 5), Expr ('+', 3, 4));
        cout<<t<<endl;
        return 0;
}