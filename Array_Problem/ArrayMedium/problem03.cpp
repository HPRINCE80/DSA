#include <bits/stdc++.h>
using namespace std;
int CounttheMaximume(vector<int> &nums)
{ // using brute force Apporouch
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
            if (count > n / 2)
            {
                return nums[i];
            }
        }
    }
    return -1;
}
// using Better Approuch
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int num : nums)
    {
        mp[num]++;           // count badhao
        if (mp[num] > n / 2) // majority mil gayi
            return num;
    }
    return -1;
}
// optimal Approuch
int majaorityelements_byusingoptimals(vector<int> &nums)
{
    int count = 0;
    int ele;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            ele = nums[i];
        }
        else if (nums[i] == ele)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele)
            count2++;
    }
    if (count2 > nums.size() / 2)
    {
        return ele;
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 0, 0, 1, 1, 1, 1, 7, 7};
    // int ans = CounttheMaximume(nums);
    int ans = majaorityelements_byusingoptimals(nums);
    cout << "Count in this Array the Maximume number is -> " << ans << endl;
    // int ans2 = majorityElement(nums);
    // cout << "maximune elements in the Array->" << ans2 << endl;
    return 0;
}