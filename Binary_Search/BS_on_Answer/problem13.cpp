#include<bits/stdc++.h>
using namespace std;
int Square(int x){
    if(x <2) return x;
    int left = 1 , right = x /2,ans = 0;
    while(left<right){
        long long mid = left + (right - left)/2;
        if(mid * mid <= x){
            ans = mid;
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }
    return ans;
}
int main(){
    cout<<Square(64);

    return 0;
}