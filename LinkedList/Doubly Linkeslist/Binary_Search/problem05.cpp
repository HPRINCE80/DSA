#include<bits/stdc++.h>
using namespace std;
pair<int,int> FindNumber(vector<int>& nums , int x){
    int left = 0;
    int right = nums.size() -1;
    int floorval = -1;
    int ceival = -1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid]==x){
            floorval = nums[mid];
            ceival = nums[mid];
            return {floorval,ceival};
        }
        else if(nums[mid]<x){
            floorval= nums[mid];

            left = mid +1;
        }
        else{
            ceival = nums[mid];
            right = mid -1;

        }
    }
    return {floorval, ceival};
}
int main(){
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x =5;
    pair<int,int> ans = FindNumber(nums,x);
    cout<<"Floor-> "<< ans.first<<endl;
    cout<<"Cei-> "<< ans.second<<endl;

    return 0;
}