#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int k)
{
    // Hint: ye function "at most k distinct integers" wale
    // total subarrays count karega (sliding window se)
    if (k < 0)
        return 0;

    int n = nums.size();
    // unordered_map<int, int> freq;
    unordered_map<int, int> freq;
    int l = 0, count = 0;
    for (int r = 0; r < n; r++)
    {
        freq[nums[r]]++;
        while (freq.size() > k)
        {
            freq[nums[l]]--;
            if (freq[nums[l]] == 0)
            {                        // 👈 agar count 0 ho jaye
                freq.erase(nums[l]); // 👈 hashmap se hata do
            }
            l++;
        }
        count += (r - l + 1);
    }
    return count;
}

int subarrays(vector<int> &nums, int k)
{

    return atMost(nums, k) - atMost(nums, k - 1);
}

int main()
{

    vector<int> nums = {1, 2, 1, 2, 3};

    int k = 2;
    cout << subarrays(nums, k);

    return 0;
}