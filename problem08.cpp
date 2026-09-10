#include<bits/stdc++.h>
using namespace std;

vector<int> replace(vector<int> &arr, int n){
    vector<int> rankArr;

    for(int i=0;i<n;i++){
        unordered_set<int> s;

        for(int j=0;j<n;j++){
            if(arr[j]<arr[i]){
                s.insert(arr[j]);
            }
        }
        int rank = s.size() +1;

        rankArr.push_back(rank);
    }

    return rankArr;
}

int main(){
    vector<int> arr = {10,20,15,12,40,25};
    int n = arr.size();
    vector<int> result = replace(arr,n);

    cout<<"The ranks of the elements in the array are: ";

    for(int r : result) {
        cout<<r<<" ";
    }

    return 0;
}