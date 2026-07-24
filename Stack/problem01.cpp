//  #include<bits/stdc++.h>
//  using namespace std;
//  int main(){

//     return 0;
//  }

 #include <bits/stdc++.h>
using namespace std;

class ArrayStack {
private:
    // Array to hold elements
    int* stackArray;
    // Maximum capacity
    int capacity; 
     // Index of top element  
    int topIndex;   

public:
    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        // Initialize stack as empty
        topIndex = -1; 
    }

    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Pushes element x 
    void push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        return stackArray[topIndex--];
    }

    // Returns top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }

   /* Returns true if the 
   stack is empty, false otherwise*/
    bool isEmpty() {
        return topIndex == -1;
    }
};

// Main Function
int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
}