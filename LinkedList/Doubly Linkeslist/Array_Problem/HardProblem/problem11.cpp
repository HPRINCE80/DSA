#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // This function returns the maximum product
    // of any contiguous subarray using optimized approach
    int maxProduct(vector<int>& nums) {
        // Initialize answer, max and min product as first element
        int res = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        // Traverse from second element
        for (int i = 1; i < nums.size(); i++) {
            // Store current number
            int curr = nums[i];

            // If current number is negative, swap max and min
            if (curr < 0) swap(maxProd, minProd);

            // Update max and min product ending at current index
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            // Update global result
            res = max(res, maxProd);
        }

        // Return the result
        return res;
    }
};

int main() {
    vector<int> nums = {4, 5, 3, 7, 1, 2};
    Solution sol;
    cout << sol.maxProduct(nums);
    return 0;
}
