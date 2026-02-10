#include <bits/stdc++.h>
using namespace std;
vector<int> findmisingelements(vector<int> &nums)
{
    int n = nums.size();
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = -xr ^ nums[i];
        xr = xr ^ (i + 1);
    }
    int number = (xr & ~(xr - 1));
    int one = 0;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if ((nums[i] & number != 0))
        {
            one = one ^ nums[i];
        }
        else
        {
            zero = zero ^ nums[i];
        }
    }
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == zero)
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        return {zero, one};
    }
    return {one, zero};
}
int main()
{
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> result = findmisingelements(nums);
    cout<<"The repeating and missing number is->"<<"{ "<<result[0]<<","<<result[1]<<" }";

    return 0;
}