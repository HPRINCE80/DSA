#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& nums, int k) {
    // Step 1: Max-heap banao (hint: default priority_queue max-heap hoti hai)
    priority_queue<int> maxHeap;
    
    // Step 2: Har element ko loop mein push karo
    for(int i = 0; i < nums.size(); i++) {
        maxHeap.push(nums[i]);
        
        // Step 3: Agar size k se bada ho gaya, top nikaal do
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    // Step 4: Answer return karo
    return maxHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    cout << "Kth Smallest Element: " << kthSmallest(nums, k) << endl;
    
    return 0;
}