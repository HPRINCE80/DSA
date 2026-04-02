#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    
};
Node* insertAtHead(Node* head, int X) {
    Node* newNode = new Node();
    newNode->next = head;
    newNode->data = X;
    return newNode;
}
void printlist(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
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
    head = insertAtHead(head, X);

    cout << "Modified List after inserting " << X << " at head: ";
    printlist(head);
    return 0;
}