#include <bits/stdc++.h>
using namespace std;
// vector<int> ReaaregetheArray(vector<int> &nums)
// {
//     vector<int> pos;
//     vector<int> neg;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] > 0)
//         {
//             pos.push_back(nums[i]);
//         }
//         else
//         {
//             neg.push_back(nums[i]);
//         }
//     }
//     for (int i = 0; i < n / 2; i++)
//     {
//         nums[2 * i] = pos[i];
//         nums[2 * i + 1] = neg[i];
//     }
//     return nums;
// }
// using optimals approuch
vector<int> Arrengetheorder(vector<int>& arr)
{
    int pos = 0;
    int neg = 1;
    int n = arr.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            res[pos] = arr[i];
            pos += 2;
        }
        else
        {
            res[neg] = arr[i];
            neg += 2;
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {2, 4, 5, -1, -3, -4};
    vector<int> ans = Arrengetheorder(arr);
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ", ";
    }
    return 0;
}