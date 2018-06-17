//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
//


class MinStack {
private:
    int* stackArray;
    int total;
    int pos;
    
    vector<int> mins = {};
    
    void doubleStackArray() {
        total *= 2;
        int* newStackArray = new int[total];
        for (int i = 0; i <= pos; i++) {
            newStackArray[i] = stackArray[i];
        }
        delete stackArray;
        stackArray = newStackArray;
    }
public:
    /** initialize your data structure here. */
    MinStack() {
        pos = -1;
        total = 20;
        stackArray = new int[total];
    }
    
    void push(int x) {
        //TODO: if size exceed orgin size，then double size
        if (pos >= total - 1) {
            doubleStackArray();
        }
        
        pos += 1;
        stackArray[pos] = x;
        if (x <= getMin()) {
            mins.push_back(x);
        }
    }
    
    void pop() {
//        cout << "pop" << stackArray[pos] << "\n";
        if (stackArray[pos] == getMin()) {
            mins.pop_back();
        }
        stackArray[pos] = -1;
        pos -= 1;
    }
    
    int top() {
        return stackArray[pos];
    }
    
    int getMin() {
        if (mins.size() == 0) {
            return INT_MAX;
        }
        return mins[mins.size() - 1];
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
