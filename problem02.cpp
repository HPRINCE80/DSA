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
    Node* deleteNode(Node* head){
        if(head==NULL) return NULL;

        if(head->next==NULL){
            delete head;
            return NULL;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
        return head;
    }
    void printList(Node* head){
        Node* temp = head;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original list:\n";
    printList(head);

    cout << "List after deleting last node:\n";
    head = deleteNode(head);

    // Print list after deletion
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}

