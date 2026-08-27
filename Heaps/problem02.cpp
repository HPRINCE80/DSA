#include<bits/stdc++.h>
using namespace std;
bool isMinHeap(vector<int>& nums){
    int n = nums.size();
    for(int i=0;i<n;i++){

        int left = (2*i) +1;
        if(left<n && nums[i] > nums[left]){
            return false;
        }
        
        int right = (2*i) +2;
        if(right<n && nums[i]> nums[right]){
            return false;
        }
        
    }
    return true;
}
int main(){
    vector<int> nums = {10, 20, 30, 21, 23};
    cout<<boolalpha;
    cout<<isMinHeap(nums);

    return 0;
}