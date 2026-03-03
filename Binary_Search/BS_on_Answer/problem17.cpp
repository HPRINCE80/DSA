#include<bits/stdc++.h>
using namespace std;

bool canShip(vector<int>& weights, int days, int capacity) {
    int requiredDays = 1;   // start with day 1
    int currentWeight = 0;

    for (int w : weights) {
        if (currentWeight + w > capacity) {
            requiredDays++;     // need one more day
            currentWeight = 0;
        }
        currentWeight += w;
    }

    return requiredDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());  // minimum possible capacity
    int high = 0;

    for (int w : weights)
        high += w;   // maximum possible capacity

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, days, mid)) {
            high = mid;   // try smaller capacity
        } else {
            low = mid + 1;  // increase capacity
        }
    }

    return low;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << "Minimum capacity required: "
         << shipWithinDays(weights, days) << endl;

    return 0;
}