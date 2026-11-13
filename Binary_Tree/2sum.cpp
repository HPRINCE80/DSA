
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<2) return {};
        int sum;
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum = nums[i] + nums[j];
                if(sum==target) 
                return {i,j};
            }
        }
        return {};
    }
};