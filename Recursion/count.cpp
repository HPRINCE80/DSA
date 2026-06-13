#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums, int index, int current_sum, int k){
    if(index == nums.size()){
    if(current_sum == k) return 1;
    else return 0;

}
    // solve(nums, index+1, current_sum + nums[index], k);


    return solve(nums, index+1, current_sum, k) + solve(nums, index+1, current_sum + nums[index], k);
}
bool solvetrue(vector<int>& nums, int index, int current_sum, int k){
    if(index == nums.size()){
    if(current_sum == k) return true;
    else return false;

}
    // solve(nums, index+1, current_sum + nums[index], k);


    return solvetrue(nums, index+1, current_sum, k) || solvetrue(nums, index+1, current_sum + nums[index], k);
}



int main(){

     vector<int> nums = {1, 2, 3, 4, 5};
     int target = 5;
//      if(solvetrue(nums, 0, 0, target))
//     cout << "Yes";
// else
//     cout << "No";
    //   cout<<boolalpha;
      cout << "Number of subsequences with target sum " << target << ": "
         << solve(nums, 0,0,target) << endl;

    return 0;
}