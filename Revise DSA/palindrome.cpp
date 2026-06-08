#include<bits/stdc++.h>
using namespace std;
int main(){

    int n  = 1213;
    int number = n;
    int reverse = 0;
    while(number != 0){
        reverse = reverse * 10 + number % 10;
        number = number / 10;
    }
    if(reverse == n){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "Not Palindrome" << endl;
    }
    return 0;
}