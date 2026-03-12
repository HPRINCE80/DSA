#include <bits/stdc++.h>
using namespace std;

int kthelements(vector<int> &nums, vector<int> &nums2, int k)
{
    int m = nums.size();
    int n = nums2.size();
    if (m > n)
    {
        return kthelements(nums2, nums, k);
    }
    int left = k;
    int low = max(0, k - n), high = min(k, m);
    int mid1 = (low + high) >> 1;
    int mid2 = left - mid1;

    int l1 = (mid1 > 0) ? nums[mid1 - 1] : INT_MIN;
    int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
    int r1 = (mid1 < m) ? nums[mid1] : INT_MAX;
    int r2 = (mid2 < n) ? nums2[mid2] : INT_MAX;

    if (l1 <= r2 && l2 <= r1)
    {
        return max(l1, l2);
    }
    else if (l1 > l2)
    {
        high = mid1 - 1;
    }
    else
    {
        low = mid1 + 1;
    }

    return -1;
}
int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    // Create an instance of Solution class
    // Print the answer
    cout << "The " << k << "-th element of two sorted arrays is: "
         << kthelements(a, b, k) << '\n';

    return 0;
}