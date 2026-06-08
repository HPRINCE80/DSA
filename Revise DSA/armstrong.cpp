#include <bits/stdc++.h>
using namespace std;
void armstrong(int n)
{
    int len = to_string(n).length();
    int sum = 0;
    int temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
       int pow =1;
        for(int i=0;i<len;i++){
            pow = pow * digit;
        }
        sum = sum + pow;
        temp = temp / 10;
    }
    if (sum == n)
    {
        cout << "Number is AramStrong->";
    }
    else
    {
        cout << "Not Aramstrong->";
    }
}

void divisor(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}

bool prime(int n){
    if(n<=1) {
        return false;
    }
    for(int i = 2; i*i<=n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main()
{
    if(prime(3)){
        cout<<"Number is prime->";
    }
    else{
        cout<<"Not prime->";
    }
    return 0;
}