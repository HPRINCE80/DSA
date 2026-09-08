#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // MIN-heap
    
    int n = arr.size();
    
    for(int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
        
        if(minHeap.size() > k) {
            minHeap.pop();  // sabse chhota nikaal do
        }
    }
    
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 6, 4};
    int k = 2;
    
    cout << "Kth Largest Element: " << kthLargest(nums, k) << endl;
    
    return 0;
}