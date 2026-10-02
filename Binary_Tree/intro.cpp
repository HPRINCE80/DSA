#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int Value)
    {
        data = Value;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    int x;
    cout << "Enter the root Number-> : ";
    cin >> x;
    int first, Second;
    queue<Node*> q;
    Node *root = new Node(x);
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout << "Enter the left value of " << temp->data << " :";
        cin >>first;
        if (first != -1)
        {
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cout << "Enter the Right value of " << temp->data << ": ";
        cin >> Second;
        if (Second != -1)
        {
            temp->right = new Node(Second);
            q.push(temp->right);
        }
    }

    return 0;
}