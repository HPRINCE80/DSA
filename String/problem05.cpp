#include<bits/stdc++.h>
using namespace std;

bool isomorphicstring(string s, string t){
    int m[256] = {0}, m2[256] = {0};
    int n = s.size();
    for(int i =0;i<n;i++){
        if(m[s[i]] != m2[t[i]]){
            return false;
        }
               m[s[i]] = i + 1;
              m2[t[i]] = i + 1;
    }
    return true;
}

int main(){
     // Sample input strings
      string s = "paper";
      string t = "title";
      
      // Check if strings are isomorphic
      if (isomorphicstring(s, t)) {
          cout << "Strings are isomorphic." << endl;
      } else {
          cout << "Strings are not isomorphic." << endl;
      }

    return 0;
}