#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the Array::";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    map<int , int> freq;
    //counting frequency
    for(int i =0;i<n;i++){
        freq[arr[i]]++;
    } //printing frequency
    for(auto it: freq){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}