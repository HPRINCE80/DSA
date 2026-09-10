#include<bits/stdc++.h>
using namespace std;
 
vector<int> insertionsort(vector<int>& arr, int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = key;
        }

    }
    return arr;

    
}

int main(){
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = 6;
    cout << "Before sorting->";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    insertionsort(arr,n);
      cout << "After insertion->";
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";

    cout << "\n";


}