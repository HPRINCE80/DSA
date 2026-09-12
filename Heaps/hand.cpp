#include <bits/stdc++.h>
using namespace std;


    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // If total cards can't be divided evenly, return false
        if (hand.size() % groupSize != 0) return false;

        // Store the frequency of each card
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        // Create an iterator pointing to the beginning of the frequency map
        auto it = freq.begin();

        // Loop through all keys in the map
        while (it != freq.end()) {

            // Skip cards that are already used up
            if (it->second == 0) {
                ++it;
                continue;
            }

            // Store the starting card of the group
            int start = it->first;

            // Number of times we need to form this group
            int count = it->second;

            // Try to form a group of consecutive cards of size groupSize
            for (int i = 0; i < groupSize; ++i) {

                // If the current required card is missing or doesn't have enough frequency
                if (freq[start + i] < count) return false;

                // Decrease the frequency for current card
                freq[start + i] -= count;
            }

            // Move the iterator to the next element
            ++it;
        }

        // All groups formed successfully
        return true;
    }


// Driver code
int main() {
    

    // Test case 1
    vector<int> hand1 = {1,2,3,6,2,3,4,7,8};
    int groupSize1 = 3;
    cout<<boolalpha;
    cout << isNStraightHand(hand1, groupSize1) << endl;  
    // Output: 1 (true)

    // Test case 2
    vector<int> hand2 = {1,2,3,4,5};
    int groupSize2 = 4;
    cout<<boolalpha;
    cout << isNStraightHand(hand2, groupSize2) << endl; 
    // Output: 0 (false)

    return 0;
}
