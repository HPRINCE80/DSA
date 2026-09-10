#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int index, vector<int> current, vector<vector<int>>& result){
    
    if(index==nums.size()){
        result.push_back(current);
        return;
    }

    solve(nums,index+1,current,result);
    current.push_back(nums[index]);
    solve(nums,index+1,current,result);

    current.pop_back();

    
}
int main(){
   vector<int> nums = {1,2,3};

   vector<vector<int>> result;
   solve(nums,0,{},result);

   for(vector<int> subset : result){
    for(int x : subset){
        cout<<x<<" ";
    }
    cout << endl;
}




    return 0;
}