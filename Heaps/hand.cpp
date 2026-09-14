#include <bits/stdc++.h>
using namespace std;

bool isright(vector<int> &hand, int k)
{
    int arrsize = hand.size();

    if (arrsize % k != 0)
    {
        return false;
    }

    map<int, int> freq;
    for (int card : hand)
    {
        freq[card]++;
    }

    while (!freq.empty())
    {
        int start = freq.begin()->first;

        for (int i = start; i < start + k; i++)
        {
            if (freq.find(i) == freq.end())
            {
                return false;
            }
            freq[i]--;

            if (freq[i] == 0)
            {
                freq.erase(i);
            }
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {1,2,3,6,2,3,4,7,8};
    int k = 3;
    cout << boolalpha;
    cout << isright(nums, k);

    return 0;
}
