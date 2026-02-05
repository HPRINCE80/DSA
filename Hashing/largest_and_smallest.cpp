#include <bits/stdc++.h>
using namespace std;

int mostFrequentElement(vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : nums) {
        freq[num]++;
    }

    int maxFreq = 0;
    int ans = INT_MAX;

    // Find the element with max frequency
    // If tie, choose smaller element
    for (auto it : freq) {
        int num = it.first;
        int count = it.second;

        if (count > maxFreq) {
            maxFreq = count;
            ans = num;
        } else if (count == maxFreq) {
            ans = min(ans, num);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 4, 1, 3, 3,3,3,3,3};
    cout << mostFrequentElement(nums);
    return 0;
}
