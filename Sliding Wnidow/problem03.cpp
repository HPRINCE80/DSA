#include<bits/stdc++.h>
using namespace std;

int fruites(vector<int>& nums){
    int maxfruite = 0;
    int n = nums.size();
    for(int i =0;i<nums.size();i++){
        unordered_map<int , int> basket;
        int currentCount = 0;
        for(int j=0;j<n;++j){
            basket[nums[j]]++;


            if(basket.size() > 2){
                break;
            }
            currentCount++;
        }
        maxfruite = max(maxfruite, currentCount);
    }
    return maxfruite;
}
int main() {

    vector<int> fruits = {1, 2, 1};
    cout <<fruites(fruits) << endl;
    return 0;
}