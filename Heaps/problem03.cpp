#include<bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>& arr){
    int n = arr.size();
    for(int i =0;i<n;i++){
        int left = 2*i+1;
        int right = 2*i+2;
        if(left <n && arr[i] > arr[left]) return false;

        if(right <n && arr[i] > arr[right]) return false;
    }
    return true;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    if(isMinHeap(arr)) 
    {
        cout<<"The array is a min heap"<<endl;
    }
    else {
        cout<<"The array is not a min heap"<<endl;
    }
    return 0;
}