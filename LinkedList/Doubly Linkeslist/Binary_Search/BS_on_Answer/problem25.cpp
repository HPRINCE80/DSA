#include <bits/stdc++.h>
using namespace std;
int numberofgussesStation( long double dist, vector<int>& arr)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int numberinBetween = (arr[i] - arr[i - 1]) / dist;
        if ((arr[i] - arr[i - 1]) == (dist * numberinBetween))
        {
            numberinBetween--;
        }
        cnt += numberinBetween;
    }
    return cnt;
}

long double minmisemaxDistance(vector<int> &nums, int k)
{
    int n = nums.size();
    long double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(nums[i + 1] - nums[i]));
    }
    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int cnt = numberofgussesStation(mid, nums);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    
    long double ans = minmisemaxDistance(arr, k);

    cout << "The answer is: " << ans << "\n";

    return 0;
}