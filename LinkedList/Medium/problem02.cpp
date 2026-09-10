#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

Node *insert(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
        return newNode;
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

vector<vector<int>> findPairs(Node *head, int target)
{
    vector<vector<int>> ans;
    if (!head)
        return ans;
    Node *left = head;
    Node *right = head;

    while (right->next)
    {
        right = right->next;
    }
    while (left != right && right->next != left)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
}
    int main()
    {
        Node *head = NULL;

        // sample sorted DLL
        vector<int> arr = {1, 2, 3, 4, 9};

        for (int x : arr)
        {
            head = insert(head, x);
        }

        int target = 5;

        vector<vector<int>> ans = findPairs(head, target);
        cout<<"This pair Sum is equal to ->\n";

        for (auto &p : ans)
        {
            cout << p[0] << " " << p[1] << endl;
        }

        return 0;
    }