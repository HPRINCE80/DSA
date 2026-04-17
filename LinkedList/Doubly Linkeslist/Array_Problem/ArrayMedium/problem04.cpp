#include <bits/stdc++.h>
using namespace std;
int MaximumeSubarray(vector<int> &nums)
{
    int curr_sum = nums[0];
    int max_sum = nums[0];
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        curr_sum = max(nums[i], curr_sum + nums[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}
int main()
{
    vector<int> nums = {2, 3, 5, -2, 7, -4};
    int ans = MaximumeSubarray(nums);
    cout<<"Maximume Subarray "<< ans<<endl;
    return 0;
}