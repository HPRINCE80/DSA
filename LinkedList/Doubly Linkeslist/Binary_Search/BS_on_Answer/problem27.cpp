#include<bits/stdc++.h>
using namespace std;
double findmedian(vector<int>& nums, vector<int>& nums2){
    vector<int> merged;
    int i=0,j=0;
    while(i<nums.size() && j<nums.size()){
        if(nums[i]<nums2[j])
        merged.push_back(nums[i])
        i++;
    }
    else{
        merged.push_back(nums2[j]);
        j++;
    }
}

int main(){
    return 0;
}