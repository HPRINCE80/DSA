#include<bits/stdc++.h>
using namespace std;

vector<int> maxsliding(vector<int>& nums, int k){
    deque<int> dq;

    vector<int> result;

    for(int i=0;i<nums.size();i++){
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
          // 2. YE STEP MISSING THA — back se chote elements nikalo
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
         dq.push_back(i);

        if(i >= k-1){
            result.push_back(nums[dq.front()]);
        }

    }
    return result;
}
int main (){

     vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans = maxsliding(arr,k);

    for(int num : ans){
        cout<<num<<" ";
    }

    return 0;
}