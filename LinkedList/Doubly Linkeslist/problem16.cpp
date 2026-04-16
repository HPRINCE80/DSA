#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode *Mergesort(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;

    ListNode *left = Mergesort(head);
    ListNode *right = Mergesort(mid);

    return merge(left, right);
}
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < n; i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Driver code
int main()
{
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode *head = createList(arr, n);

    cout << "Original Linked List: ";
    printList(head);

    // Sort linked list
    head = Mergesort(head);

    cout << "Sorted Linked List:   ";
    printList(head);

    return 0;
}
