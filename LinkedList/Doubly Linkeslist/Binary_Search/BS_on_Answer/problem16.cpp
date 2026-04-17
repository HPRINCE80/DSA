#include<bits/stdc++.h>
using namespace std;
bool posible(vector<int>& nums , int day , int m ,int k){
    int n = nums.size();
    int count = 0;
    int boqute =0;
    for(int i =0;i<n;i++){
        if(nums[i]<=day){
            count++;
            if(count== k){
                boqute++;
                count=0;

            }
        }else{
            count = 0;

        }
    }   return boqute >= m;
}
int FindBo(vector<int>& nums, int k, int m){
    long long total = 1LL * k * m; // Total flowers required

   // If total required flowers > available flowers, it's impossible
   if (total > nums.size()) return -1;
    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    int answer = -1;
    while(low<high){

        int mid = low + (high-low)/2;
        if(posible(nums,mid,m,k)){
            answer = mid;
            high = mid -1;
        }else{
            low = mid +1;
        }
        
    } return answer;
}
int main(){
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m =2,k=3;
    cout<<FindBo(arr,m,k);
    return 0;
}