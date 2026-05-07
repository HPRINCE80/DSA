#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;       
    Node* prev;     
    Node* next;     
    Node* head = nullptr; // Initialize head of the list4
    // Constructor to initialize node with given value
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};
Node* head = nullptr; // Initialize head of the list
  void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        // If list is empty, set new node as head
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        // Link the new node at the end
        current->next = newNode;
        newNode->prev = current;
    }
Node* removeDuplicates(Node* head){
    if(!head) return head;
    Node* Dummy = new Node(0);
    Dummy->next = head;
    head->prev = Dummy;
    Node* curr = head;
    Node* prev = Dummy;

    while(curr){
        if(curr->next && curr->data == curr->next->data){
            int val = curr->data;

            while(curr && curr->data == val){
                Node* temp = curr;
                curr= curr->next;
                delete temp;

            }
            prev->next = curr;
            if(curr) curr->prev = prev;
        }
        else{
            prev = curr;
            curr = curr->next;  
        }
    }
    Node* newHead = Dummy->next;
    if(newHead) newHead->prev = NULL;
    delete Dummy;
    return newHead;
}
 void printList() {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
int main(){

  // Initial list values (with duplicates)
    vector<int> values = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6,7,7,7,8};

    for (int value : values) {
        insertAtEnd(value);
    }

    // Print the original list
    cout << "Original List: ";
    printList();

    // Remove duplicate nodes (keep only one occurrence)
    head = removeDuplicates(head);

    // Print the updated list
    cout << "After Removing Duplicates (keeping 1 occurrence): ";
    printList();

    return 0;
    
}