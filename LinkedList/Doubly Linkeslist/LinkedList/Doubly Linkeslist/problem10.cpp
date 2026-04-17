#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL)
        return head;

    ListNode *odd = head;
    ListNode *Even = head->next;
    ListNode *Evenhead = Even;

    while (Even != NULL && Even->next != NULL)
    {
        odd->next = Even->next;
        odd = odd->next;

        Even->next = odd->next;
        Even = Even->next;
    }
    odd->next = Evenhead;
    return head;
}
void PrintList(ListNode *head)
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}
ListNode *insertAtEnd(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val);

    if (!head)
        return newNode;

    ListNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

int main()
{
    ListNode *head = NULL;

    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Printing initial LinkedList
    cout << "Initial LinkedList : " << endl;
    PrintList(head);

    // Segregating even and odd nodes
    ListNode *newHead = oddEvenList(head);

    // Printing modified LinkedList
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);

    return 0;
}