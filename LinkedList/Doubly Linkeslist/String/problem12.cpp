#include <bits/stdc++.h>
using namespace std;

int atmostnumberofstring(string s, int k)
{
    int left = 0, res = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < s.size(); right++)
    {
        freq[s[right]]++;

        while (freq.size() > k)
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        res += (right - left + 1);
    }
    return res;
}
// Function to count substrings with exactly k distinct characters
int countSubstrings(string s, int k) {
    // Exactly k = atMost(k) - atMost(k-1)
    return atmostnumberofstring(s, k) - atmostnumberofstring(s, k - 1);
}
int main()
{ // Sample test
    string s = "pqpqs";
    int k = 2;

    // Output the result
    cout << "Count: " << countSubstrings(s, k) << endl; // Output

    return 0;
}