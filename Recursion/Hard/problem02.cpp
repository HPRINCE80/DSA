#include<bits/stdc++.h>
using namespace std;
bool word(string s,int index, vector<string>& dict){
    if(index == s.size()) 
        return true;
    
    for(int i = index; i < (int)s.size(); i++) {
        string sub = s.substr(index, i - index + 1);
        if (find(dict.begin(), dict.end(), sub) != dict.end()) {
            if (word(s, i + 1, dict))
                return true;
        }
    }
    return false;


}
int main(){
    string s = "takeuforward";
    vector<string> dict = {"take" , "forward" , "you", "u"};

    bool result =  word(s,0,dict);
    cout<<boolalpha;
cout<<result;

    return 0;
}