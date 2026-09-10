#include<bits/stdc++.h>
using namespace std;
void arrargene(vector<int> arr){
    int n = arr.size();
    const int MOD = 1e9 + 7;
    int sum =0;
    // int start = 0;

    for(int start =0;start<n;start++){
        for(int j=start;j<n;j++){
            cout<<"{";
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
            int summid;
            
            for(int print=start;print<=j;print++){

                cout<<arr[print]<<" ";
                minVal = min(minVal, arr[print]); 
                maxVal = max(maxVal,arr[print]);
                  // poore array ka min);
                summid = maxVal - minVal;
            }
            cout<<"}"<<endl;
            sum = (sum + summid) % MOD;
        }
        
    }
    cout << "Minimum: " << sum<< endl;
}
int main(){
    vector<int> arr = {1, 2, 3};
    arrargene(arr);


    return 0;
}