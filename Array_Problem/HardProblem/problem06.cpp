#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> MergedOverlapping(vector<vector<int>>& nums)
{
    int n = nums.size();
    vector<vector<int>> merged;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (merged.empty() || merged.back()[1] <  nums[i][0])
        {
            merged.push_back(nums[i]);
        }
        else
        {
            merged.back()[1] = max(
                merged.back()[1], nums[i][1]);
        }
    }
    return merged;
}
int main(){
    vector<vector<int>> nums = { {1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> answer = MergedOverlapping(nums);
    cout<<"NOt Overlapping in this Pair->\n";
    for (auto i : answer)
    {
        cout << "[" << i[0] << "," << i[1] << "] ";
    }



    return 0;
}