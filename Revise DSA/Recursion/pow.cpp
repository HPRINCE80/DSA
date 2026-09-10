#include<bits/stdc++.h>
using namespace std;
long long pow(int a , int b){
    if(b<0){
        cout<<"Negative exponent not supported"<<endl;
        return 0;
    }
    if(b==0){
        return 1;
    }
    return a*pow(a,b-1);
}
int main(){
    int a = 2, b = 0;
    cout << pow(a, b) << endl;
    return 0;

}