#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n ){
    int reverse = 0;
    
    
    while(n>0){
        int m  = n%10;
        reverse = reverse*10+ m;
        n = n/10;
       }
       return reverse;

}
int main(){
  int n = 321;
  cout<<"Reverse Number-> "<<reverseNumber( n);
    return 0;
}