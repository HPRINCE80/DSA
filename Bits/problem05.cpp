#include<bits/stdc++.h>
using namespace std;
int setrightmostdigit(int n){
    return n | (n+1);
}
int main(){
    int n = 10;
    int result = setrightmostdigit(n);
    cout<<result;
    return 0;
}