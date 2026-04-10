#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "-->";
        head = head->next;
    }
}

Node *deleteNode(Node *head, int N)
{
    Node *Dummy = new Node(0, head);
    Node *slow = Dummy;
    Node *fast = Dummy;
    for (int i = 0; i < N; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    return delNode;

    Node *newHead = Dummy->next;
    delete Dummy; // free dummy node
    return newHead;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Create linked list manually
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    printLL(head);
    cout << endl;

    cout << "Delete at the Node index -> {" << N << "}" << endl;

    // Delete the Nth node from the end
    head = deleteNode(head, N);

    // Print the modified linked list
    printLL(head);
    return 0;
}