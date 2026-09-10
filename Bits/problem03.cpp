#include<bits/stdc++.h>
using namespace std;

bool ispower(int n){
    return n> 0 && (n& (n-1)) == 0;
}
int main(){
    cout<<boolalpha;
    cout<<ispower(3);

    return 0;
}