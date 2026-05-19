#include<bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* child;
    
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

// ==========================================
// HELPER: Do sorted lists ko merge karo
// (child pointer se connected hain dono)
// ==========================================
Node* mergeTwoLists(Node* a, Node* b) {
    // Base cases
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        // Recursively baaki merge karo
        result->child = mergeTwoLists(a->child, b);
    } else {
        result = b;
        result->child = mergeTwoLists(a, b->child);
    }

    result->next = nullptr; // next ko null karo (flatten mein sirf child chahiye)
    return result;
}

// ==========================================
// MAIN FUNCTION: Flatten karo poori list
// ==========================================
Node* flatten(Node* root) {
    // Base case: agar list empty hai ya sirf ek column hai
    if (!root || !root->next)
        return root;

    // Pehle aage ki saari lists ko flatten karo (Recursion)
    root->next = flatten(root->next);

    // Ab current column ko baaki flatten list se merge karo
    root = mergeTwoLists(root, root->next);

    return root;
}

// ==========================================
// UTILITY: List print karo
// ==========================================
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->child) cout << " -> ";
        head = head->child;
    }
    cout << endl;
}

// ==========================================
// UTILITY: Node banana aur child se connect
// ==========================================
Node* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->child = new Node(vals[i]);
        curr = curr->child;
    }
    return head;
}

// ==========================================
// MAIN: Example chalate hain
// ==========================================
int main() {
    /*
     * List banao:
     * 5 -> 10 -> 19 -> 28
     * |          |     |
     * 7         22    35
     * |                |
     * 8               40
     * |
     * 30
     */

    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = createList({7, 8, 30});
    head->next->next->child = new Node(22);
    head->next->next->next->child = createList({35, 40});

    cout << "Before Flattening:" << endl;
    Node* temp = head;
    while (temp) {
        cout << "Column: " << temp->data;
        Node* c = temp->child;
        while (c) { cout << " -> " << c->data; c = c->child; }
        cout << endl;
        temp = temp->next;
    }

    Node* result = flatten(head);

    cout << "\nAfter Flattening (sorted by child):" << endl;
    printList(result);

    return 0;
}