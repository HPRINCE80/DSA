class Solution {
public:
    long long subarraySum(vector<int>& nums, int k) {
        unordered_map<long long , long long> prefixCount;

        prefixCount[0] = 1;

        long long prefixSum = 0;
        long long count = 0;

        for(int value : nums){
            prefixSum += value;

            long long needSum = prefixSum - k;
            if(prefixCount.find(needSum) != prefixCount.end()){
                count += prefixCount[needSum];
            }

            prefixCount[prefixSum]++;

        }
        return count;
    }
};