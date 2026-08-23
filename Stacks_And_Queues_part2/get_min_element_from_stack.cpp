/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int value) pushes the element value onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:

    -231 <= val <= 231 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
    stack<long long> s;
    long long minVal;
public:
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        } else if(val < minVal){
            s.push(2LL*val - minVal);
            minVal = val;
        } else{
            s.push(val);
        }
    }
    
    void pop() {
       long long t = s.top();
       s.pop();
       if(t < minVal){
        minVal = 2 * minVal - t;
       } 
    }
    
    int top() {
        return s.top() < minVal ? (int)minVal : (int)s.top();
    }
    
    int getMin() {
        return (int)minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout<<"Top: "<<st.top()<<endl;
    cout<< "Min: "<<st.getMin()<<endl;

    st.pop();

    cout<<"After pop:"<<endl;
    cout<<"Top: "<<st.top()<<endl;
    cout<<"Min: "<<st.getMin()<<endl;

    st.pop();

    cout<<"After another pop:"<<endl;
    cout<<"Top: "<<st.top()<<endl;
    cout<<"Min: "<<st.getMin()<<endl;

    return 0;
}