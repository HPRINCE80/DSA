#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapifyDown(vector<int>& nums, int n, int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if (left < n && nums[left] < nums[smallest]) {
            smallest = left;
        }
        if (right < n && nums[right] < nums[smallest]) {
            smallest = right;
        }
        
        if (smallest != i) {
            swap(nums[i], nums[smallest]);
            heapifyDown(nums, n, smallest);  // recursively check niche
        }
    }
    
    void heapifyUp(vector<int>& nums, int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            
            if (nums[i] < nums[parent]) {
                swap(nums[i], nums[parent]);
                i = parent;  // upar move karo
            } else {
                break;  // sahi jagah mil gayi
            }
        }
    }
    
    void sortedArray(vector<int>& nums, int ind, int val) {
        int oldVal = nums[ind];
        nums[ind] = val;
        
        if (val > oldVal) {
            // naya value bada hai, neeche ki taraf heapify karo
            heapifyDown(nums, nums.size(), ind);
        } else {
            // naya value chhota hai, upar ki taraf heapify karo
            heapifyUp(nums, ind);
        }
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 4, 6, 7, 8};
    int ind = 2, val = 10;
    
    Solution sol;
    sol.sortedArray(nums, ind, val);
    
    cout << "Modified Heap: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    return 0;
}