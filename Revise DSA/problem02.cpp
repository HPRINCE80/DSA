#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n =5;
    for (int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"1"<<" ";
        }
        for(int k =0;k< n-i;k++){
            cout<<"*"<<" ";

        }
            for(int l=0;l<n-i;l++){
                cout<<"*"<<" ";
            }
            for(int m=0;m<i;m++){
                cout<<"1"<<" ";
            }
        cout<<endl;
    }
    return 0;
}