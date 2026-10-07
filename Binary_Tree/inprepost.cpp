#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* Left;
    Node* Right;

    Node(int val) {
        int data = val;
         Left = nullptr;
        Right = nullptr;


    }
};

void alltraversal(Node* root){
    vector<int> pre, in, post;
    if(root == nullptr)
    return;

    stack<pair<Node* , int>>st;
    st.push({root,1});
    while (!st.empty())
    {
        Node* node = st.top().first;
        int state = st.top().second;
        if(state==1){
            pre.push_back(node->data);
            st.top().second++;
            if(node->Left != nullptr){
                st.push({node->Left,1});

            }

        }

        else if(state ==2){
            in.push_back(node->data);
            st.top().second++;
            if(node->Right!= nullptr){
                st.push({node->Right,1});

            }
        }
        else{
            post.push_back(node->data);
            st.pop();
        }
    }

    for(int r : pre){
        cout<<r;
    }
    
    for(int r : in){
        cout<<r;
    }
    
    for(int r : post){
        cout<<r;
    }
    
}
int main() {
    
    return 0;
}