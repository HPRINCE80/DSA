#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int n){
    stack<int> s;
    for(int i =0;i<n;i++){
        s.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        arr[i] = s.top();
        s.pop();
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr,n);
   cout<<"Reversed Array is:";
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }
    return 0;
}