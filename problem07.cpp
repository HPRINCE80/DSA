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
 Node* detectloop(Node* head){
    if(head==NULL) return NULL;
    Node* slow = head;
    Node* fast = head;

    // detect cycle
    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){

            slow = head;
            while(slow!=fast){
                
                slow = slow->next;
                fast = fast->next;
                
            }
            return slow;
        }
    }
  return NULL;
 }
int main(){
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

    head->next->next->next->next = head->next;

    Node* result = detectloop(head);

    if(result)
        cout << "Cycle starts at node with value: " << result->data << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}