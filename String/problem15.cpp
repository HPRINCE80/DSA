#include<bits/stdc++.h>
using namespace std;

int  beautySum(string s){
    int n = s.length();
    int totally  =0;
     
    for(int i=0;i<n;i++){
        vector<int> freq(26,0);

        for(int j=0;j<n;j++){
            freq[s[j] - 'a']++;
            
            int maxfreq =0;
            int minfreq = INT_MAX;

            for(int k=0;k<26;k++){
                if(freq[k]>0){
                    maxfreq = max(maxfreq,freq[k]);
                    minfreq = min(minfreq, freq[k]);
                }
            }
                totally += (maxfreq - minfreq);
        }
    }
    return totally;
}
int main(){
 
    string s = "aabcb";
    cout << beautySum(s) << endl;
    return 0;
}