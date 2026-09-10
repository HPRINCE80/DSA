#include<bits/stdc++.h>
using namespace std;
bool rotationcheack(string s, string goal){
    if(s.length() != goal.length()){
        return false;
    }
    string doubled = s+s;
    return doubled.find(goal) != string::npos;

}
int main(){
     string s = "abcde";
    string goal = "cdeab";
    if(rotationcheack(s, goal)){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }

    return 0;
}