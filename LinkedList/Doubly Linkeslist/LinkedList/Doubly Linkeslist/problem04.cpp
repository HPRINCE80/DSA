#include<bits/stdc++.h>
using namespace std;
class Node{ 
public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = NULL;    
    }
};

Node* findmiddle(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5); 
    Node* middle = findmiddle(head);
    if(middle!=NULL){

        cout <<"Middle element is: " << middle->data << endl;
    }

    return 0;
}