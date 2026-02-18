#include <bits/stdc++.h>
using namespace std;
bool findelements(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)

            return true;
    }
 
    return false;
}
int main()
{
    vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 6;
    bool answer = findelements(nums, target);
    cout << boolalpha;
    cout << answer << endl;
    return 0;
}