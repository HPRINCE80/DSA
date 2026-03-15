#include <bits/stdc++.h>
using namespace std;
vector<int> findLeaderElements(vector<int> &nums)
{
    int n = nums.size();
    int max = nums[n - 1];
    vector<int> answer;
    answer.push_back(max);
    for (int i = n-2; i >= 0; i--)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            answer.push_back(nums[i]);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main()
{
    vector<int> nums = {1, 2, 5, 3, 1, 2};
    vector<int> ans = findLeaderElements(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ,";
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> findLeaderElements(vector<int> &nums)
// {
//     int n = nums.size();
//     int maxElem = nums[n - 1];

//     vector<int> answer;
//     answer.push_back(maxElem);   // last element is leader

//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (nums[i] > maxElem)
//         {
//             maxElem = nums[i];
//             answer.push_back(nums[i]);
//         }
//     }

//     reverse(answer.begin(), answer.end());
//     return answer;
// }

// int main()
// {
//     vector<int> nums = {1, 2, 5, 3, 1, 2};
//     vector<int> ans = findLeaderElements(nums);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ,";
//     }

//     return 0;
// }
