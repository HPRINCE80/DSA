#include <bits/stdc++.h>
using namespace std;
void solve(string digits, int index, string current, vector<string> &result, vector<string> mapping)
{
    if (index == digits.size())
    {
        result.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];
    for (char c : letters)
    {
        solve(digits, index + 1, current + c, result, mapping);
    }
}
int main()
{
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string digit = "34";
    vector<string> result;

    solve(digit, 0, "", result, mapping);

    for (string s : result)
    {
        cout << "[";
        
        {
            cout << s;
        }
        cout << "]";
        cout << ",";
    }

    return 0;
}