#include<bits/stdc++.h>
using namespace std;

string reversestring(string s){
    
     string result = "";
     int n = s.size() -1;

     while( n>= 0){
        while(n>=0 && s[n] == ' '){ n--;}
         if(n<0) break;

         int end =n;

         while(n>=0&& s[n]!=' ' ){ n--;}

         string word = s.substr(n +1, end-n);

         if(!result.empty()){
            result += " ";
         }
         result += word;
     }
     return result;
}
int main(){
string s = " amazing coding skills ";
    cout << reversestring(s) << endl;
    return 0;
    
}