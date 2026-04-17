#include <bits/stdc++.h>
using namespace std;

// Class to compute upper bound
class UpperBoundFinder {
public:
    // Function to find the upper bound using binary search
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;  // Default answer if x is >= all elements

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] > x) {
                ans = mid;        // Potential answer found
                high = mid - 1;   // Try to find smaller valid index on the left
            } else {
                low = mid + 1;    // Move right if mid is <= x
            }
        }
        return ans;  // Index of the first element > x
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 9, 15, 19};  // Sorted input array
    int n = arr.size();                     // Size of the array
    int x = 9;                              // Target value

    UpperBoundFinder finder;               // Create object
    int ind = finder.upperBound(arr, x, n);  // Call method

    cout << "The upper bound is the index: " << ind << "\n";  // Output result
    return 0;
}