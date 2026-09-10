#include<bits/stdc++.h>
using namespace std;
void printname(int i, int n)
{
    if(i>n)
    {
        return;
    }
    cout<<"Prince\n";
    printname(i+1,n);
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin >> n;
    printname(1,n);
    return 0;
}