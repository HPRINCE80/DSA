#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* reverselist(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void printlist(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
  Node* head = new Node(1);   
    head->next = new Node(2);
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5); 
    cout<<"Linked list->\n";
    printlist(head);
    cout<<endl;
    Node* reverse = reverselist(head);
    cout<<"Reverse Linked list->\n";
 while(reverse!=NULL){

     cout<<reverse->data<<" ";
     reverse = reverse->next;
 }
 cout<<endl;
    return 0;
}