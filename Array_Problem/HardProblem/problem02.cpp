#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Triplet(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
vector<vector<int>> OpttimalsSolution(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] +nums[right];
            if (sum == 0)
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++,right--;
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0)
                left++;
            else
                right--;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {2, -2, 0, 3, -3, 5};
    vector<vector<int>> aswer = OpttimalsSolution(nums);
    cout << "Output is here->\n";
    for (auto &triplet : aswer)
    {
        for (int x : triplet)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}