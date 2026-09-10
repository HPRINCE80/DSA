#include <bits/stdc++.h>
using namespace std;
int findlenght(vector<int> &nums)
{
    int n = nums.size();
    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = findlenght(nums);
    cout << "These is a Maximume Lenght of the given Array-> ";

    cout << ans << " ";

    return 0;
}