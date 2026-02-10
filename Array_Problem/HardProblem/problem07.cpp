#include <bits/stdc++.h>
using namespace std;
void ArrayMerged(vector<int> &nums, vector<int> &nums2)
{
    int m = nums2.size();
    int n = nums.size() - m;
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums[i] > nums2[j])
        {
            nums[k--] = nums[i--];
        }
        else
        {
            nums[k--] = nums2[j--];
        }
    }
    while (j >= 0)
    {
        nums[k--] = nums2[j--];
    }
}
int main()
{
    vector<int> nums = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    ArrayMerged(nums, nums2);
    cout << "These Aray s merged and sorted->\n";
    for (int ans : nums)
    {
        cout << ans << " ";
    }

    return 0;
}