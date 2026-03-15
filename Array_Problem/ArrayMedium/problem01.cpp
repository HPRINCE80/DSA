// #include <bits/stdc++.h>
// using namespace std;
// vector<int> findthesum(vector<int>& nums, int target)
// {
//     int n = nums.size();
//     int sum;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             sum = nums[i] + nums[j];

//             if (nums[i] + nums[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }
// int main()
// {
//     vector<int> nums = {1, 6, 2, 10, 3};
//     int target = 13;
//     vector<int> result = findthesum(nums, target);

// if (result[0] != -1)
// {
//     cout << "Target found at indices: "
//          << result[0] << " and " << result[1] << endl;
// }
// else
// {
//     cout << "Target not found" << endl;
// }

    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
    // Variant 1: Check if two numbers sum to target using two-pointer approach
    string twoSumExists(vector<int> arr, int target) {
        int n = arr.size();
        // Create a vector of pairs to remember original indices after sorting
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
        // Sort based on the element values
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        // Loop until pointers cross
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                return "YES";  // Pair found
            } else if (sum < target) {
                left++;  // Need bigger sum, move left pointer right
            } else {
                right--; // Need smaller sum, move right pointer left
            }
        }
        return "NO";  // No pair found
    }

    // Variant 2: Return original indices of two numbers that sum to target
    vector<int> twoSumIndices(vector<int> arr, int target) {
        int n = arr.size();
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                // Return original indices
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};  // No pair found
    }


int main() {
    
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 19;

    cout << twoSumExists(arr, target) << "\n";
    vector<int> res = twoSumIndices(arr, target);
    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}
