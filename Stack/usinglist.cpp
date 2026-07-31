#include <bits/stdc++.h>
using namespace std;

struct Node{
   int val;
   Node *next;
   Node(int d){
    val = d;
    next = NULL;
   }
};
class LinkedListStack {
    private:
    Node *head;
    int size;

    public:
    LinkedListStack() {
        head = NULL;
        size = 0;

    }

    void push(int x){
        Node *element = new Node(x);
        element->next = head;
        head = element;

        size++;
    }
    int pop(){
        if(head == NULL){
            return -1;
        }
        int value = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return value;
    }

    int top(){
        if(head == NULL){
            return -1;
        }
        return head->val;
    }

    bool isEmpty(){
        return (size == 0);
    }
};

int main()
{  
    LinkedListStack st;


    vector<string> commands = {"LinkedListStack", "push", "push","pop","top","isEmpty"};
    vector<vector<int>> inputs = {{}, {1}, {2}, {}, {}, {}};

    
    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            st.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << st.pop() << " ";
        } else if (commands[i] == "top") {
            cout << st.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "LinkedListStack") {
            cout << "null ";
        }
    }
    return 0;
}