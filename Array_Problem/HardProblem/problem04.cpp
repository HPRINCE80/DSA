#include <bits/stdc++.h>
using namespace std;
int longestsunarray(vector<int> &nums)
{
    unordered_map<int, int> mp;

    int n = nums.size();
    int prefix = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += nums[i];

        if (prefix == 0)
        {
            sum = i + 1;
        }
        if (mp.find(prefix) != mp.end())
        {
            sum = max(sum, i - mp[prefix]);
        }
        else
        {
            mp[prefix] = i;
        }
    }
    return sum;
}
int main()
{
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
    int ans = longestsunarray(nums);
    cout << "Maximune sum of the Array-> " << ans << " ";
}
