#include <bits/stdc++.h>
using namespace std;

// Class to find the lower bound index in an array
class LowerBoundFinder {
public:
    // Function to find the lower bound using binary search
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0;           // Start of search range
        int high = n - 1;      // End of search range
        int ans = n;           // Default to n (not found)

        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2;  // Middle index

            if (arr[mid] >= x) {
                ans = mid;           // Store possible answer
                high = mid - 1;      // Try to find smaller index on left side
            } else {
                low = mid + 1;       // Move right if current element is less than x
            }
        }
        return ans;  // Return the index of the lower bound
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};  // Sorted input array
    int n = arr.size();                  // Size of array
    int x = 9;                           // Target value

    LowerBoundFinder finder;            // Create object of the class
    int ind = finder.lowerBound(arr, n, x);  // Call method to find lower bound

    cout << "The lower bound is the index: " << ind << "\n";  // Output the result
    return 0;
}
