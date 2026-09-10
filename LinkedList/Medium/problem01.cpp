#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

// Insert at end (helper for driver)
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Print DLL
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 🔥 Optimal function
Node* deleteTarget(Node* head, int target) {
    Node* curr = head;

    while (curr != NULL) {
        Node* nextNode = curr->next; // store next

        if (curr->val == target) {
            // if it's head
            if (curr->prev == NULL) {
                head = curr->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                curr->prev->next = curr->next;
                if (curr->next != NULL)
                    curr->next->prev = curr->prev;
            }

            delete curr; // free memory
        }

        curr = nextNode;
    }

    return head;
}

// 🚀 Driver Code
int main() {
    Node* head = NULL;

    // Create list: 1 <-> 2 <-> 3 <-> 2 <-> 4
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);

    cout << "Original List:\n";
    printList(head);

    int target = 2;
    head = deleteTarget(head, target);

    cout << "After deleting " << target << ":\n";
    printList(head);

    return 0;
}