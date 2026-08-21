#include<bits/stdc++.h>
using namespace std;
int fruits(vector<int>& arr){
    int maxfruite = 0;
    int n = arr.size();
    for(int start = 0;start<n;start++){
        unordered_map<int, int> basket;
        int currentCount = 0;
        for(int end = 0;end<n;end++){
            basket[arr[end]];
            if (basket.size() > 2) {
                break;
            }  
            currentCount++;
                }
                  maxfruite = max(maxfruite, currentCount);
    }
    return maxfruite;
}
int main() {


    vector<int> fruit = {1, 2, 1};
    cout <<fruits(fruit) << endl; // Output: 3
    return 0;


    return 0;
}