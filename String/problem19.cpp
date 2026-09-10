#include<bits/stdc++.h>
using namespace std;
int expand(string &s, int left, int right) {
    int count = 0;

    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}

int countPalindromes(string s) {
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        // odd length
        count += expand(s, i, i);

        // even length
        count += expand(s, i, i + 1);
    }

    return count;
}

int main() {
    string s = "aaa";
    cout << countPalindromes(s);

return 0;
}
