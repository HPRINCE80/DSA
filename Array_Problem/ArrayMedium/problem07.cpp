#include <bits/stdc++.h>
using namespace std;
void next_permeutation(vector<int> &nums)
{
    int n = nums.size();
    int indx = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            indx = i;
            break;
        }
    }
    if (indx == -1)
    {
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        return;
    }

    // Find element just greater than nums[index]
    for (int i = n - 1; i > indx; i--)
    {
        // Swap the two
        if (nums[i] > nums[indx])
        {
            swap(nums[i], nums[indx]);
            break;
        }
    }

    // Reverse the part after index
    reverse(nums.begin() + indx + 1, nums.end());
}
int main()
{
    vector<int> nums = {1, 2, 3};
    next_permeutation(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}