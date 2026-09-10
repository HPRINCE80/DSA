#include<bits/stdc++.h>
using namespace std; 
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;

    }
};
ListNode* rotateRight(ListNode* head,int k){
    if(!head || !head->next || k==0) return head;

    int length =1;
    ListNode* tail = head;
    while(tail->next){
        tail = tail->next;
        length++;
    }
    tail->next = head;
    k = k%length;

    int stepsToNewHead = length - k;
    ListNode* newTail = tail;
    for(int i=0;i<stepsToNewHead;i++){
        newTail = newTail->next;
    }
    ListNode* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

int main(){
      // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;

    
    ListNode* newHead = rotateRight(head, k);

    // Print the rotated list
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}