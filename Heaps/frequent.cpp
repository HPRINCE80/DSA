#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Frequency count karo
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Step 2: Min-heap banao (frequency ke basis pe), size k maintain karo
    // pair<frequency, number>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    
    for (auto& it : freq) {
        int number = it.first;
        int frequency = it.second;
        
        minHeap.push({frequency, number});
        
        if (minHeap.size() > k) {
            minHeap.pop();  // sabse kam frequency wala nikal do
        }
    }
    
    // Step 3: Heap se result nikalo
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);  // number chahiye, frequency nahi
        minHeap.pop();
    }
    
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    
    vector<int> result = topKFrequent(nums, k);
    
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}