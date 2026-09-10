#include<bits/stdc++.h>
using namespace std;
int Search(vector<int>& nums){
    int left = 0;
    int n = nums.size();
    int right = n-1;
    while(left<right){
        int mid = left + (right - left)/2;
        if(nums[mid]> nums[right]){
            left = mid +1;
        }
        else{
            right = mid;
        }
    }
    return nums[left];
}
int main(){
    vector<int> nums =  {4, 5, 6, 7,  1, 2, 3};
    int ans = Search(nums);
    cout<<ans<<endl;
    
    return 0;
}