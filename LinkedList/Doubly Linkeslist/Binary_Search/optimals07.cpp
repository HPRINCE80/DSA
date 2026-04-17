#include<bits/stdc++.h>
using namespace std;
int Search(vector<int>& nums,int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left<=right){
        int mid = (left+right)/2;
       // If mid id target 
       if(nums[mid]==target){
            return mid;
        }
        // Cheak left part is sorted
        if(nums[left]<=nums[mid]){
            if(target >= nums[left] && target < nums[mid])
              right = mid -1;
              else 
              left =  mid +1; 
        }
        // right half sorted ha 
        else{
            if(target > nums[mid] && target <= nums[right])
            left = mid +1;
            else 
            right - mid -1;
        }
        }
        return -1;
}
int main()
{
    vector<int> nums =  {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = Search(nums, target);
    cout << "Index: " << result;

    return 0;
}
