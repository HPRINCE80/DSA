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
            for(int print=start;print<=j;print++){

                cout<<arr[print]<<" ";
                minVal = min(minVal, arr[print]); 
                  // poore array ka min);
            }
            cout<<"}"<<endl;
            sum = (sum + minVal) % MOD;
        }
        
    }
    cout << "Minimum: " << sum<< endl;
}
int main(){
    vector<int> arr = {3, 1, 2, 5};
    arrargene(arr);


    return 0;
}