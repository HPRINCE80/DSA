#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^') // Exponent operator has highest precedence
        return 3;
    else if (c == '/' || c == '*') // Multiplication and division have higher precedence than addition
        return 2;
    else if (c == '+' || c == '-') // Addition and subtraction have lowest precedence
        return 1;
    else
        return -1;
}

// The main function to convert infix expression to postfix expression
string infixToPostfix(string s)
{
    stack<char> st; // Stack to hold operators and parentheses
    string result;  // String to hold the resulting postfix expression

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the scanned character is an operand, add it to the result string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an ‘(‘, push it to the stack
        else if (c == '(')
            st.push('(');

        // If the scanned character is a ‘)’, pop from stack until an ‘(‘ is encountered
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop the ‘(‘ from the stack
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c); // Push the current operator to the stack
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result; // Output the result
}

string InfixtoPrefix(string infix)
{
    int n = infix.size();

    // Step 1: Reverse karo aur brackets swap karo
    string reversed = "";
    for (int i = n - 1; i >= 0; i--)
    {
        char c = infix[i];
        if (c == '(')
            reversed += ')';
        else if (c == ')')
            reversed += '(';
        else
            reversed += c;
    }
    string postfix = infixToPostfix(reversed);

    // Step 3: Postfix ko reverse karo → yahi prefix hai
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    string exp = "(p+q)*(m-n)"; // Infix expression
    cout << "Infix expression: " << exp << endl;
    cout<<"Prefix Expresion :" <<InfixtoPrefix(exp);
    
    return 0;
}