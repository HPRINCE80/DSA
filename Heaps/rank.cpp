#include<bits/stdc++.h>
using namespace std;
vector<int> replacewithrank(vector<int>& arr){
    vector<int> sorted = arr;

    sort(sorted.begin(), sorted.end());

    int rank =1;
    unordered_map<int , int> rankmap;
    for(int num : sorted){
        if(rankmap.find(num) == rankmap.end()){
            rankmap[num] = rank;
            rank++;
        }

    }
    vector<int> result;
    for(int num : arr){
        result.push_back(rankmap[num]);
    }

    return result;


}
int main() {

    vector<int> nums = { 8, 15, 8, 25, 9};
    vector<int> result = replacewithrank(nums);
    for(int r : result){
        cout<<r<<" ";
    }
    return 0;
}