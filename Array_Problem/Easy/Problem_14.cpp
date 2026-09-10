// #include <bits/stdc++.h>
// using namespace std;
// int LongestSubArray(vector<int> &nums, int k)
// {
//     int len = 0;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int sum = 0;
//             for (int idx = i; idx <= j; idx++)
//             {

//                 sum = sum + nums[idx];
//             }
//                 if (sum == k)
//                 {
//                     len = max(len, j - i + 1);
//             }
//         }
//     }
//     return len;
// }
// int main()
// {
//     vector<int> nums = {10, 5, 2, 7, 1, 9};
//     int k = 15;
//     int ans = LongestSubArray(nums, k);
//     cout << "longestSubarray " << ans << endl;
//     //return 0;
// }

// Optimal approch
#include <bits/stdc++.h>
using namespace std;


    // Function to get the length of longest subarray with sum equal to k
    int getLongestSubarray(vector<int>& a, int k) {
        int n = a.size();
        map<int, int> preSumMap; // prefixSum -> earliest index
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i]; // compute running prefix sum

            // Case 1: If the entire sum from 0 to i is equal to k
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Case 2: If (sum - k) is seen before, a valid subarray exists
            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Only store the first occurrence of each prefix sum
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }


int main() {
    vector<int> a = { -1, 1, 1 };
    int k = 1;

    
    int len = getLongestSubarray(a, k);

    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}