#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    
};
// Function to delete head
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr; // list is empty
    }

    Node* temp = head;       // save current head
    head = head->next;       // move head to next node
    delete temp;             // free memory
    return head;             // return new head
}
// Node* insertAtHead(Node* head, int X) {
//     Node* newNode = new Node();
//     newNode->next = head;
//     newNode->data = X;
//     return newNode;
// }
void printlist(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {

    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = nullptr;

    cout << "Original List: ";
    printlist(head);

    int X = 5; // Value to insert at head
    // head = insertAtHead(head, X);
        head = deleteHead(head);

    cout << "Modified List after deleting head: ";
    printlist(head);
    return 0;
} 