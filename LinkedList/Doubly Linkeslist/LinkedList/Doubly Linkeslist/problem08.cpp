#include<bits/stdc++.h>
using namespace std;
class Node{
public:
   int data;
   Node* next;
   Node(int x){
    data = x;
    next = NULL;
   }
};

int findlength(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            int count =1;
            Node* temp = slow->next;
            while(temp!=slow){
                count++;
                temp = temp->next;

            }
            return count;


        }
    }
    return 0;
}

int main(){
      Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Linking the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a loop from fifth to second
    fifth->next = second;

    // Creating a Solution object
    

    // Getting the loop length
    int loopLength = findlength(head);

    // Printing the result
    if (loopLength > 0) {
        cout << "Length of the loop: "
             << loopLength << endl;
    } else {
        cout << "No loop found in the linked list."
             << endl;
    }

    return 0;
}
