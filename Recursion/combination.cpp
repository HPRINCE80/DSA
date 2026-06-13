#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int index, int current_sum, vector<int> current, vector<vector<int>> &result, int target)
{
    if (current_sum == target)
    {
        result.push_back(current);
        return;
    }

    if (current_sum > target)
        return;


    if(index == candidates.size()) return;
    solve(candidates, index + 1, current_sum, current, result, target);
    current.push_back(candidates[index]);
    solve(candidates, index, current_sum + candidates[index], current, result, target);
    current.pop_back(); // backtrack!
}
int main()
{
    vector<int> nums =  {2, 3, 5, 4};
    int n = 7;
    vector<vector<int>> result;
    solve(nums, 0, 0, {}, result, n);
    for(vector<int> subset : result){
    for(int x : subset){
        cout<<x<<" ";
    }
    cout << endl;
}

    return 0;
}