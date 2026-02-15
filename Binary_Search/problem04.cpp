#include<bits/stdc++.h>
using namespace std;
int SearchInsert(vector<int>& nums, int target){
    int left=0;
    int right = nums.size() -1;
    int ans = nums.size();
    while(left<=right){
        int mid =  (right+left)/2;
        if(nums[mid]>=target){
            ans = mid;
            right = mid -1;
            
        }
        
        
        else{
            left = mid +1;
        }
        }
        return ans;
}
int main(){
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    cout<<"Target Value is inserted and Present at index number-> "<<SearchInsert(nums,target);
    
    return 0;

}