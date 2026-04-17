#include<bits/stdc++.h>
using namespace std;
string removeOuterPransthese(string s)
{
    string result = "";
    int depth = 0;
    for(char c : s){
        if(c == '('){
            if(depth>0){
                result += c;
            }
            depth++;
        }
        else{
            depth--;
            if(depth > 0)
            result +=c;
        }
    }
    return result;
}
int main(){
      string s = "(()())(())";
    
    cout << removeOuterPransthese(s);
    return 0;
}