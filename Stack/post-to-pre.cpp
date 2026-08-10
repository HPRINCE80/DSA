#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string postfix) {
    stack<string> s;
    int n = postfix.size();
    
    for (int i = 0; i < n; i++) {
        char c = postfix[i];
        
        if (isalnum(c)) {
            s.push(string(1,c));
        }
        else {
            // yaha likho:
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            // 2 elements pop karo (op1, op2)
            // naya string banao: operator + op2 + op1
            s.push(c + op2 + op1);
            // push kar do
        }
    }
    
    return s.top();
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << postfixToPrefix(postfix);
    return 0;
}