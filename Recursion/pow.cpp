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

double optimalsmypow(double x , long long n){
    if(n<0){
        x = 1/x;
        n = -n;
    }
    double ans = 1;

    while(n>0){
        if(n%2 == 1){
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    return ans;
}
int main(){
    cout<<myPow(2.00000, 10)<<endl;
    cout<<"using optimal: "<<optimalsmypow(2.00000, 10)<<endl;
    
    return 0;
}