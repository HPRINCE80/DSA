#include<bits/stdc++.h>
using namespace std;
string longestcommonstring(vector<string>& s){
    sort(s.begin(), s.end());
    string first = s[0];
    string last = s[s.size() -1];

    string ans = "";

    for(int i =0;i<min(first.size(), last.size()); i++){
        if(first[i]== last[i]){
            ans += first[i];
        }
        else{
            break;
        }

    }
    return ans;
}
int main(){
     vector<string> strs = {"flower","flow","flight"};
  cout<<"Common elements->  "<< longestcommonstring(strs);
    return 0;
}