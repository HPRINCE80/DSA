#include<bits/stdc++.h>
using namespace std;
int countSubarrayXOR(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xr = 0;
        for (int j = i; j < n; j++)
        {

            xr ^= nums[j];
            if (xr == k)
            {
                count++;
            }
        }
    }
    return count;
}
int optimals(vector<int> & nums , int k ){
    int n = nums.size();
    unordered_map<int,int> freq;
    freq[0] = 1;
    int prefix = 0;
    int count =0;
    for(int i=0;i<n;i++){
        prefix  ^= i;
        int target = prefix  ^ k;
        if(freq.find(target)!= freq.end()){
            count += freq[target];

        }
        freq[prefix]++;
    }
    return count;



}
int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k =6;
 cout<<"Maximume XOR of the Array-> "<< countSubarrayXOR(nums,k);
 cout<<"\nMaximume XOR of the Array using Optimals approuch-> "<< optimals(nums,k);
    
    return 0;
}