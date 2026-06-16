#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}
void palindrome(string s, int index, vector<string> current, vector<vector<string>> &result)
{
    if (index == s.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        string sub = s.substr(index, i - index + 1);
        if (isPalindrome(sub))
        {
            current.push_back(sub);
            palindrome(s, i + 1, current, result);
            current.pop_back();
        }
    }
}
int main()
{
    string s = "aabaa";
    vector<vector<string>> result;
    palindrome(s, 0, {}, result);
    for (vector<string> subset : result)
    {
        cout << "{";
        for (string word : subset)
        {
            cout << word << " ";
        }
        cout << "} ,";
    }
    return 0;
}