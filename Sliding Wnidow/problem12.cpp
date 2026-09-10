#include <bits/stdc++.h>
using namespace std;

string minWindow(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int minLen = INT_MAX, minStart = -1;
    
    int i = 0;
    while (i < n) {
        int j = 0;   // s2 ka pointer
        
        // Step 1: Forward pass — s2 ko match karo, end index dhundo
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                j++;
            }
            i++;
        }
        // Hint: while(i < n) { agar s1[i]==s2[j], j++; agar j==m, break; i++; }
        
        if (j < m) break;   // agar poora s2 match nahi hua, aur koshish karne ka fayda nahi
        
        int end = i-1;   // ye window ka end hai
        
        i--;
        j=m-1;
        while (j>=0)
        {
            if(s1[i]==s2[j]){
                j--;
            }
            i--;
        }
        
        // Step 2: Backward pass — start dhundo
        // Hint: j = m-1; while(j >= 0) { agar s1[i]==s2[j], j--; i--; }
        // jab j < 0 ho jaye, matlab poora s2 (ulta) match ho gaya
        
        int start = i + 1;   // ye window ka start hoga
        
        // Step 3: window length check karo, minLen/minStart update karo
        if (end - start + 1 < minLen) {
            minLen = end - start + 1;
            minStart = start;
        }
        
        // Step 4: agli koshish ke liye i ko start+1 pe le jao (taaki naya window dhundh sake)
        i = start + 1;
    }
    
    return minStart == -1 ? "" : s1.substr(minStart, minLen);
}

int main() {
    string s1 = "abcdebdde";
    string s2 = "bde";
    cout << minWindow(s1, s2) << endl;
    // Expected: "bcde"
    
    return 0;
}