#include<bits/stdc++.h>
using namespace std;

bool check(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i] == '('){
            s.push(str[i]);
        }
        else{
            if(s.empty()){
                return false;
            }
            else{
                s.pop();
            }
        } 
    }
    return s.empty();
}
int main(){
     string str = "((()))";
     cout<<boolalpha;
     cout<<check(str)<<endl;
    return 0;
}