'''
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

'''
class MinStack:
    def __init__ (self):
            self.data_ = []
            self.min_ = []   
    # @param x, an integer
    # @return an integer
    def push(self, x):
        self.data_.append (x)
        if len (self.min_) == 0 or x <= self.min_[-1]:
            self.min_.append (x)
        return x

    # @return nothing
    def pop(self):
        if len (self.data_) == 0:
            return
        tmp = self.data_.pop ()
        if tmp == self.min_[-1]:
            self.min_.pop ()

    # @return an integer
    def top(self):
        if len (self.data_) == 0:
            return 0
        return self.data_[-1]

    # @return an integer
    def getMin(self):
        if len (self.min_) == 0:
                return 0
        return self.min_[-1]