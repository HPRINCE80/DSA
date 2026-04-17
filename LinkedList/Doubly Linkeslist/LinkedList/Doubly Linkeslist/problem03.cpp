#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev=NULL;
    }
};
Node* reverseDLL(Node* head){
    if(head==NULL) return NULL;
    Node* temp = NULL;
    Node* current = head;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL){
        head = temp->prev;
    }
    return head;
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    cout << "Before Reverse Linked List: \n";
    printList(head);

    head = reverseDLL(head);

    cout << "After Reverse Linked List: \n";
    printList(head);

    return 0;
}
