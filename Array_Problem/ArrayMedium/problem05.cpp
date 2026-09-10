#include <bits/stdc++.h>
using namespace std;
int findMaxProfit(vector<int>& nums)
{
    int max_profit = 0;
    int minprice = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        minprice = min(minprice, nums[i]);
        max_profit = max(max_profit, nums[i] - minprice);
    }
    return max_profit;
}
int main()
{
    vector<int> nums = {10, 17, 5, 8, 15, 9};
    int ans = findMaxProfit(nums);
    cout << "Maximime Profit-> " << ans << endl;
    return 0;
}