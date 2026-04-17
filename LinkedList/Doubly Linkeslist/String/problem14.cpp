#include<bits/stdc++.h>
using namespace std;

string pliandrome(string s){
    string t = "#";
    for(char c :s){
        t += c;
        t += "#";
    }
    int n = t.size();
    vector<int> p(n,0);
    
    int center =0, right = 0;
    int maxlen = 0,start =0;

    for(int i=0;i<n;i++){
        int mirror = 2*center-i;

        if(i<right){

            p[i] = min(right - i, p[mirror]);
        }

        int l = i- (p[i] +1);
        int r = i+ (p[i] +1);

        while(l>= 0&& r<n && t[l] == t[r]) {
            p[i]++;
            l--;
            r++;
        }
        if(i+ p[i]> right){
            center = i;
            right = i + p[i];
        }
        if(p[i]> maxlen){

            maxlen =p[i];
            start = (i- maxlen)/2;
        }
    }
    return s.substr(start, maxlen);
}
int main(){
    string s = "babad";
    cout<<"Pliandrome string ->  "<< pliandrome(s);
    return 0;
}