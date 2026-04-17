#include<bits/stdc++.h>
using namespace std;
void printNumber(int i , int n) {
    int sum = 0;
    sum = sum + i;
    cout<<"Sum till now: "<< sum << endl;
    if(i<1)
    {
        return;
    }
    cout<< i <<endl;
    printNumber(i-1,n);
}
int main()
{
    int n;
cout<<"Enter the Value of N ";
cin>> n;
printNumber(n,n);
return 0;

}