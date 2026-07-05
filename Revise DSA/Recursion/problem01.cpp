#include<bits/stdc++.h>
using namespace std;
int print(int n){
    int sum = 0;
    if(n==0)  return 0;

    sum += n;


    
    sum += print(n-1);
    
    return sum;
}

int main(){
   int ans =  print(4);
   cout<<ans;
    return 0;
}