#include<bits/stdc++.h>
using namespace std;
int DaysNeeded(vector<int>& weight, int capacity){
    int Days = 1;
    int currentload = 0;
    for(int w : weight){
        if(currentload + w > capacity){
            Days++;
            currentload = w;
        }else{
            currentload += w;
        }
    }
    return Days;
}
 int shipWithinDays(vector<int>& weights, int d) {
        // Find maximum weight as minimum capacity
        int left = *max_element(weights.begin(), weights.end());
        // Find total sum as maximum capacity
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Iterate from minimum to maximum capacity
        for (int capacity = left; capacity <= right; capacity++) {
            // Calculate days needed for current capacity
            int needed = DaysNeeded(weights, capacity);
            // If days needed are less than or equal to d, return capacity
            if (needed <= d) {
                return capacity;
            }
        }
        // Should never reach here given constraints
        return right;
    }
int main() {
    vector<int> weights = {5,4,5,2,3,4,5,6};
    // Days to ship
    int d = 5;
    // Create Solution instance
    
    // Call the function and print result
    cout <<shipWithinDays(weights, d) << "\n";
    return 0;
}