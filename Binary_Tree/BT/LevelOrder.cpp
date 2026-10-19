#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> findSpiral(Node* root){
    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);
    vector<int> ans;
    while (!s1.empty() && !s2.empty()){

        if(!s1.empty()){
            while (!s1.empty())
            {
                Node* temp  = s1.top();
                s1.pop();
                ans.push_back(temp->data);

                if(temp->right)
                s2.push(temp->right);

                if(temp->left)
                s2.push(temp->left);
            }
            
        }
        else{

            if(!s2.empty()){
                while (!s2.empty())
                {
                    Node* temp1 = s2.top();
                    s2.pop();
                    ans.push_back(temp1->data);

                    if(temp1->left)
                    s1.push(temp1->left);

                    if(temp1->right)
                    s1.push(temp1->right);
                }
                
            }
        
        
    }

    return ans;
    
    

}
int main() {

    return 0;
}