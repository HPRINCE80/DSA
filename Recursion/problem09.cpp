#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& nums, int index,int current_sum, vector<int>& result){
    
    if(index==nums.size()){
        result.push_back(current_sum);
        return;
    }

    solve(nums, index+1, current_sum, result);
    solve(nums, index+1, current_sum + nums[index], result);
    
}
int main(){
    vector<int> nums =  {1, 2, 3};
    vector<int> result;
    solve(nums,0,0,result);

     for(int x : result){
    
        cout<<x<<" ";
    }
    cout << endl;

    return 0;
}