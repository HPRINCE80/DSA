#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    // Returns the length of the longest consecutive sequence.
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int longestLength = 0;
 
        // Examine every distinct value as a possible sequence start.
        for (int value : values) {
            // A present predecessor means this value lies inside a sequence.
            if (values.count(value - 1)) {
                continue;
            }
 
            int currentLength = 1;
            int nextValue = value + 1;
 
            // Extend the sequence while each next consecutive value exists.
            while (values.count(nextValue)) {
                currentLength++;
                nextValue++;
            }
 
            longestLength = max(longestLength, currentLength);
        }
 
        return longestLength;