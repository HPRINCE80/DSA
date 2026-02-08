#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> FourSum(vector<int> nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = n - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {

                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Move right pointer skipping duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) left++;
                else
                right--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, -2, 3, 5, 7, 9};
    int target = 7;
    vector<vector<int>> ans = FourSum(nums, target);
    cout<<"The Sum of these value is equal to the Target->\n";
    for (auto quad : ans)
    {
        for (int num : quad)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}