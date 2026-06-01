#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    if(n == 0 || x == 1.0) return 1;
    long long temp = n;

    if(n < 0){
        x =1;
        temp = -1 * 1LL * n;
    }
    double ans = 1;
    for(long long i =1;i<= temp;i++){
        ans *= x;
    }

    return ans;
}
int main(){
    cout<<myPow(2.00000, 10)<<endl;
    
    return 0;
}