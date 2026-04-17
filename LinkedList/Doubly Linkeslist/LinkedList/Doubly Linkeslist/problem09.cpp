#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;    

    }
     Node (int data1){
        data = data1;
        next = nullptr;
     }
    };
    Node* reverseLinkedList(Node* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        Node* newHead = reverseLinkedList(head->next);
        Node* front = head->next;
        head->next = NULL;
        front->next = head;

        return newHead;
    }
  bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    } 
    Node* slow = head;
    Node* fast = head;

    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newhead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* second = newhead;
    while(second!= NULL){
        if(first->data != second->data){
            reverseLinkedList(newhead);
            return false;
        }
        first = first->next;    
        second = second->next;
    }
        reverseLinkedList(newhead);
        return true;

  }

  void printLinkedList(Node* head){
    Node* temp =  head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
  }
  cout<<endl;
  }
  int main(){
      Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
  }