#include <bits/stdc++.h>
using namespace std;

// Class to implement Minimum Stack
class MinStack {
private:
    // Initialize a stack
    stack <pair<int,int>> st;
    
public:
    
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {value, value} );
            return;
        }
        
        // Update the current minimum 
        int mini = min(getMin(), value);
        
        // Add the pair to the stack
        st.push({value, mini});
    }
    
    // Method to pop a value from stack
    void pop() {
        // Using in-built pop method
        st.pop(); 
    }
    
    // Method to get the top of stack
    int top() {
        // Return the top value
        return st.top().first;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return the minimum
        return st.top().second;
    }
};

int main() {
    MinStack s;
    
    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}