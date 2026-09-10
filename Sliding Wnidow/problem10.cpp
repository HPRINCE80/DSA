#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {

    if (t.empty() || s.empty()) return "";
    
    unordered_map<char, int> need, window;
    
    for(char c: t){ need[c]++;}
    
    
    int have = 0, required = need.size();   // 'required' = kitne unique characters chahiye
    int l = 0;
    int minLen = INT_MAX, minStart = 0;
    
    for (int r = 0; r < s.size(); r++) {
        // Step 2: current character ko window me add karo
        window[s[r]]++;
        
        
        // Step 3: agar current character 'need' me hai AUR ab uski required count match ho gayi hai
        if(need.count(s[r]) && window[s[r]] == need[s[r]]){
            have++;
        }
        //         to 'have' badhao
        
        
        // Step 4: jab have == required, shrink karo jitna ho sake
        while (have == required) {
            if(r-l+1<minLen){
                minLen = r-l+1;
                minStart = l;
            }
            window[s[l]]--;
            if(need.count(s[l]) && window[s[l]] <need[s[l]]){
                have--;
            }
            //    agar us character ki count 'need' se kam ho jaye, 'have' bhi kam karo
            
            // l ko aage badhao
            l++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;

    // Expected: "BANC"
    
    return 0;
}