#include <bits/stdc++.h>
using namespace std;
bool calsplit(vector<int> &nums, int k, int max)
{
    int n = nums.size();
    int SubArray = 1;
    int CurrentSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (CurrentSum + nums[i] <= max)
        {
            CurrentSum += nums[i];
        }
        else
        {
            SubArray++;
            CurrentSum = nums[i];
            if (SubArray > k)
                return false;
        }
    }
    return true;
}
int splitArray(vector<int> nums, int k)
{
    if(k > nums.size()) return -1;
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calsplit(nums, k, mid))
        {

            ans = mid;
            high = mid - 1;
        }

        else
        {
            low = mid +1;
        }
    }
    return ans;
}

int main()
{ vector<int> nums = {1, 2, 3, 4, 5};
int k = 8;
cout<<boolalpha;
cout<<"Answer-> "<<splitArray(nums,k);
    return 0;
}