#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;  // min-heap
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for(int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if(minHeap.size() > k) {
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    
    cout << kthLargest.add(3) << endl;  // 4
    cout << kthLargest.add(5) << endl;  // 5
    cout << kthLargest.add(10) << endl; // 5
    cout << kthLargest.add(9) << endl;  // 8
    cout << kthLargest.add(4) << endl;  // 8
    
    return 0;
}