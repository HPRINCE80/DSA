#include<bits/stdc++.h>
using namespace std;
bool Search(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n -1;
    while(low<high){
        int mid = (low+high)/2;
        if(nums[mid]== target){
            return true;
        }
        if(nums[low]== nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
        // if the left half sorted 
        if(nums[low]<= nums[mid]){
            if(nums[low]<= target && target <= nums[mid]) {
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        else{
            // Right half is sorted
            if(nums[mid]<= target && target <= nums[high] ) {
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
    }
    return false;
}
int main(){
    vector<int> nums =  {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;
    bool ans = Search(nums,target);
    cout<<boolalpha;
    cout<< ans<<endl;

    return 0;
}