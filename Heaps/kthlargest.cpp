#include<bits/stdc++.h>
using namespace std;
class solution {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    public:
    solution(int k, vector<int>& nums) {
        size = k;

        for(int num : nums){
            minHeap.push(num);

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }

    int add(int val){
        minHeap.push(val);

        if(minHeap.size() > size){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
int main() {
    vector<int> nums = {4,5,8,2};
    solution kthLargest(3,nums);

    cout << kthLargest.add(3) << endl;  // Output: 4
    cout << kthLargest.add(5) << endl;  // Output: 5
    cout << kthLargest.add(10) << endl; // Output: 5
    cout << kthLargest.add(9) << endl;  // Output: 8
    cout << kthLargest.add(4) << endl;

    return 0;
}