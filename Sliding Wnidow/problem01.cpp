#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;  // character -> last seen index
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        char ch = s[right];

        // Agar character pehle dekha ja chuka hai AND wo current window ke andar hai
        if (charIndex.find(ch) != charIndex.end() && charIndex[ch] >= left) {
            left = charIndex[ch] + 1;   // window shrink karo
        }

        charIndex[ch] = right;   // update last seen index
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}  

int main()
{
    string s = "cadbzabcd";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}