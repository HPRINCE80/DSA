#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to count nodes in linked list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next; // move to next node
    }
    return count;
}

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    // Create linked list: 10 -> 20 -> 30 -> 40
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = new Node();
    head->next->next->next->data = 40;
    head->next->next->next->next = nullptr;

    cout << "Linked List: ";
    printList(head);

    int totalNodes = countNodes(head);
    cout << "Total nodes in the linked list: " << totalNodes << endl;

    return 0;
}