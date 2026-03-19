#include <bits/stdc++.h>
using namespace std;

int RomentoInteger(string s)
{
    int res = 0;
    unordered_map<char, int> romen = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < s.size()-1; i++)
    {
        if (romen[s[i]] < romen[s[i + 1]])
        {
            res -= romen[s[i]];
        }
        else
        {
            res += romen[s[i]];
        }
    }
    return res + romen[s.back()];
}
int main()
{ 
    string s =  "III"; 
    cout<<"Interger Form-> "<<RomentoInteger(s);
    return 0;
}