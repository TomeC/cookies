/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

*/
#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    void push(int x) {
        data_.push (x);
		if (min_.empty () || x <= min_.top ())
			min_.push (x);
    }

    void pop() {
        if (!data_.empty ())
		{
			if (data_.top () == min_.top ())
				min_.pop ();
			data_.pop ();
		}
		return;
    }

    int top() {
        if (!data_.empty ())
			return data_.top ();
		return NULL;
    }

    int getMin() {
        if (!min_.empty ())
			return min_.top ();
		return NULL;
    }
private:
	//i have list as the data structure, but the answer is "memeory limit exceed error"
    stack <int> data_;
	stack <int> min_;
};
int main ()
{
	MinStack m;
	m.push (2);
	m.push (2);
	m.push (3);
	m.push (5);
	cout<<m.getMin ()<<endl;
	cout<<m.top ()<<endl;
	
	m.pop ();
	cout<<m.getMin ()<<endl;
	cout<<m.top ()<<endl;
	m.push (1);
	//m.pop ();
	cout<<m.getMin ()<<endl;
	cout<<m.top ()<<endl;
	
	m.pop ();
	cout<<m.getMin ()<<endl;
	cout<<m.top ()<<endl;

	m.pop ();
	cout<<m.getMin ()<<endl;
	cout<<m.top ()<<endl;

	m.pop ();
	cout<<m.getMin ()<<endl;
	cout<<m.top ()<<endl;

	return 0;
}