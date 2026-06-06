#include<bits/stdc++.h>
using namespace std;
void printn(int current , int n){
    
    if(current>n){
        return;
    }
    cout<<current<<" ";
    printn(current+1, n);
}
void printname(string name, int n){
    if(n==0){
        return;
    }
    cout<<name<<"\n"; 
    printname(name, n-1);
}
int main(){
    // printn(1, 5);
    printname("Radhey Radhey", 3);
    return 0;
}