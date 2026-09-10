#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, string current, int n, vector<string> &result)
{

    if (current.size() == 2 * n)
    {
        result.push_back(current);
        return;
    }
    if (open < n)
    {
        solve(open + 1, close, current + "(", n, result);
    }

    if (close < open)
    {
        solve(open, close + 1, current + ")", n, result);
    }
}
vector<string> generateParentheses(int n)
{
    vector<string> result;
    solve(0, 0, "", n, result);
    return result;
}
int main()
{
    int n = 5;
    vector<string> s = generateParentheses(n);
    for (string i : s)
    {
        cout<<"valid Parentheses->  " << i<<endl;
    }

    return 0;
}