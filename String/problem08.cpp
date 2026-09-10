#include<bits/stdc++.h>
using namespace std;

vector<char> solve(string s){
    int freq[256] = {0};

    for(char c : s){
        freq[c]++;
    }
    vector<char> ans;
    for(int i=0;i<256;i++){
        if(freq[i]>0){
            ans.push_back((char)i);
        }
    }
    sort(ans.begin(), ans.end() , [&](char a, char b){
        if(freq[a]==freq[b])
        return a <b;
        return freq[a] > freq[b];
    });
    return ans;
}

int main(){
    string s = "trrree";

    vector<char> result = solve(s);

    for(char c : result)
        cout << c << " ";
    return 0;
}