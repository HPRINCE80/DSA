#include <bits/stdc++.h>
using namespace std;

// Recursive Binary Search function
int binarySearch(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1; // Base case: target not found

    // Find middle index
    int mid = (low + high) / 2;

    // If target is found at mid
    if (nums[mid] == target)
        return mid;
    // If target is greater, search right half
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    // Otherwise, search left half
    return binarySearch(nums, low, mid - 1, target);
}

// Public function to initiate search
int search(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17}; // sorted array
    int target = 6;                              // target element to search

    // Create object of Solution class
    int ind = search(a, target);

    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: " << ind << endl;

    return 0;
}
