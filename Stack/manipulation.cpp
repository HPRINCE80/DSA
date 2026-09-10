#include<bits/stdc++.h>
using namespace std;
int countword(vector<string>& v){
    stack<string> s;

    for(string word : v){
        if(!s.empty() && s.top() == word){
            s.pop();
        }
        else{
            s.push(word);
        }
        }
        return s.size();
    }

int main(){
    vector<string> arr = {"hello", "world", "world", "hello"};
    cout<<"word left:"<<countword(arr)<<endl;
    
    return 0;
}