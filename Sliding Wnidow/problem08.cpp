#include<bits/stdc++.h>
using namespace std;

int optimalsSolution(string s, int k){
    int n = s.size();
    int r=0;
    int maxlength =0;
    int l =0;
    unordered_map<char, int>freq;
    if(k==0) return 0;
    for(int r=0;r<n;r++){
        freq[s[r]]++;
        while(freq.size()>k){
          freq[s[l]]--;
          if(freq[s[l]]==0){
            freq.erase(s[l]);
          }
          l++;
        }
        
        maxlength = max(maxlength,r-l+1);

    }
    return maxlength;
}


int lengthsubarray(string arr, int k){
    int maxlength =0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        unordered_map<char, int> freq;
        for(int j =i;j<n;j++){
            freq[arr[j]];

            if(freq.size() > k) break;
            maxlength = max(maxlength,j-i+1);
        }
    }
    return maxlength;
}
int main(){

    string s ="aababbcaacc";
    int k =2;
    cout<<optimalsSolution(s,k);


    return 0;
}