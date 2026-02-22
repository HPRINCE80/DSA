#include<bits/stdc++.h>
using namespace std;
long long CalculateHour(vector<int>& nums, int k){
    long long hour = 0;
    for(int pile : nums){
        hour += (pile + k - 1) / k;
    }
    return hour;
}
int MinEatingSpeed(vector<int>& nums , int h){
    int low = 1;
    int n = nums.size();
    int high = *max_element(nums.begin(), nums.end());
    int answer = high;
    while(low<=high){
        int mid = low + (high - low)/2;
         long long requiredHours = CalculateHour(nums, mid);
         if(requiredHours<= h){
            answer = mid;
            high = mid -1;

         }
         else{
            low = mid +1;
         }
    }
    return answer;
}
int main(){
    vector<int> nums = {25, 12, 8, 14, 19};
    int h = 5;

    int result = MinEatingSpeed(nums, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}