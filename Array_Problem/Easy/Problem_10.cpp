#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());

    int expected = mx * (mx + 1) / 2
                 - (mn - 1) * mn / 2;

    int actual = 0;
    for (int x : nums)
        actual += x;

    return expected - actual;
}
int main(){
    vector<int> nums = {1,2,3,5};
    int ele = missingNumber(nums);
    cout<<"Missing Elemenmts->"<<ele<< endl;
}
