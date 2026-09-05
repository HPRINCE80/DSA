
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int targetIndex = n - k;  // kth largest = (n-k)th smallest in sorted ascending order
        int left = 0, right = n - 1;
        
        while (true) {
            int pivotIndex = left + rand() % (right - left + 1);
            pivotIndex = partition(nums, left, right, pivotIndex);
            
            if (pivotIndex == targetIndex) {
                return nums[pivotIndex];
            } else if (pivotIndex < targetIndex) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
    }
    
private:
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        // pivot ko end mein bhej do
        swap(nums[pivotIndex], nums[right]);
        int storeIndex = left;
        
        for (int i = left; i < right; i++) {
            if (nums[i] < pivotValue) {
                swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }
        
        // pivot ko sahi jagah pe wapas rakho
        swap(nums[right], nums[storeIndex]);
        return storeIndex;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 4  ;
    
    cout << "Kth largest element: " << sol.findKthLargest(nums, k) << endl;
    // Output: 5
    
    return 0;
}