#include<bits/stdc++.h>
using namespace std;
int Findthepeak(vector<int>& nums){
    int low =0;
    int high = nums.size() -1;
    while(low<high){
        int mid = (low + high)/2;
        if(nums[mid]>nums[mid+1]){
            high = mid;
        }
        else
        {
            low = mid +1;
        }
    }
    return low;
}
int main(){
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int ans = Findthepeak(nums);
    cout<< ans <<endl;
    return 0;
}