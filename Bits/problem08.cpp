#include<bits/stdc++.h>
using namespace  std;
int getnumber(vector<int>& arr){
    int n = arr.size();
    int xorr = 0;
    for(int i=0;i<n;i++){
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
int main(){
    vector<int> arr = {4, 1, 2, 1, 2,4,4,4};
    int ans = getnumber(arr);
    
    cout << "The single element is: " << ans << endl;
    return 0;
}