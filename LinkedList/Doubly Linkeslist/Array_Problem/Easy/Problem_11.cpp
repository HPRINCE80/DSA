#include <bits/stdc++.h>
using namespace std;
int consecutive_ones(vector<int>& nums)
{
    int maxi = 0;
    int count = 0;
    for (int i=0;i<nums.size();i++)           
    {
        if (nums[i] == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
            {
                count = 0;
            }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1};
    cout << "Consecutive ones ->" << consecutive_ones(nums)<<endl;
    return 0;
}