class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int sum;
        set<vector<int>> st;
        if(n<3) return {};
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k =j+1;k<n;k++){
                     if((nums[i] + nums[j] + nums[k])==0){
                                vector<int> temp = {nums[i], nums[j] , nums[k]};
                                sort(temp.begin(), temp.end());
                                st.insert(temp);

         
         }}
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());

         return ans;
        
        
    }
};