#include <bits/stdc++.h>
using namespace std;
bool Anagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
        freq[s[i] - 'A']++;

    for (int i = 0; i < t.size(); i++)
        freq[t[i] - 'A']--;
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            return false;

    return true;
}
int main()
{
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";
    if (Anagram(Str1, Str2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}