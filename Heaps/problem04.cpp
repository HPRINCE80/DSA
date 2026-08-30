#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
        largest = left;

    if (right < n && nums[right] > nums[largest])
        largest = right;

    if (largest != i) {
        swap(nums[i], nums[largest]);
        maxHeapify(nums, n, largest); // neeche recursively fix karo
    }
}

vector<int> convertMinToMaxHeap(vector<int>& nums) {
    int n = nums.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(nums, n, i);
    }
    return nums;
}

int main() {
    vector<int> nums = {1, 3, 6, 5, 9, 8};
    vector<int> result = convertMinToMaxHeap(nums);
    for (int x : result) cout << x << " ";
    return 0;
}