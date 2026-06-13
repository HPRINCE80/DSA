#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &candidates, int index, vector<int> current, vector<vector<int>> &result)
{
    result.push_back(current);
    if (index == candidates.size())
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue; // skip duplicate

        current.push_back(candidates[i]);
        solve(candidates, i + 1, current, result);
        current.pop_back();
    }
}
int main()
{
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result;
    solve(nums, 0, {}, result);
    for (vector<int> subset : result)
    {   cout<<"[";
        for (int x : subset)
        {
            cout << x <<" ";
            
        }
        cout <<"]";
        cout<<",";
    }
    return 0;
}