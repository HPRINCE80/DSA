#include<bits/stdc++.h>
using namespace std;

int maxdepth(string s){
    int currentdepth = 0;
    int maxdepth =0;
    for(char c : s){
        if(c == '('){
            currentdepth++;
            maxdepth = max(maxdepth, currentdepth);
        }
        else if(c== ')'){
            currentdepth--;
        }
    }
    return maxdepth;
}
int main(){

    string s = "(1+(2*3)+((8)/4))+1";
    cout<<"Max depth ->  "<<maxdepth(s);

    return 0;
}