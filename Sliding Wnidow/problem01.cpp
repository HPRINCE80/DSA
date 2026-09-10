#include<bits/stdc++.h>
using namespace std;
int logeststring(string& s){
    unordered_map<char, int> charIndex;
    int left = 0;
    int maxlen = 0;

    for(int right = 0;right<s.size();right++){
        char ch = s[right];

        if(charIndex.find(ch) != charIndex.end() && charIndex[ch] >= left){
            left = charIndex[ch] + 1;
                }
                charIndex[ch] = right;
                maxlen =max(maxlen, right - left +1);
    }
    return maxlen;

}
int main() {
    string s = "cadbzabcd";
    int result =  logeststring(s);
    cout<<result << endl;


    return 0;
}