#include<bits/stdc++.h>
using namespace std;
int countStudent(vector<int>& arr , int pages){
    int n = arr.size();
    int student = 1;
    long long Pagestudent = 0;
    for(int i=0;i<n;i++){
        if(Pagestudent + arr[i] <= pages){
            Pagestudent =+ arr[i];
        }
        else{
            student++;
            Pagestudent = arr[i];

        }
    }
    return student;
}
int findpage(vector<int>& arr,int n , int m ){
    if(m>n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while (low<=high)
    {
        int mid = (low+high)/2;
        int student = countStudent(arr,mid);
        if(student> m ){
            low = mid+1;
        }else{
            low = mid -1;
        }
    }
    return low;
    
}
int main(){
    
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findpage(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;

}