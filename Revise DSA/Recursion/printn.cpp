#include <bits/stdc++.h>
using namespace std;
void printn(int current, int n)
{

    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printn(current, n - 1);
}
void printname(string name, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << name << "";
    printname(name, n - 1);
}

int sumnatural(int n)
{
    if (n == 0)
    {    return 0;
    }
    int sum = n + sumnatural(n - 1);
    return sum;
}
int factorial(int n)
{
    if (n == 0)
    {    return 1;
    }
    int sum = n  * factorial(n - 1);
    return sum;
}

int ReverArray(int arr[]){
    // int n = arr.size
    


}


int main()
{
    // printn(1, 5);
    // printname("\nRadhey Radhey",     // cout << sumnatural(4);
    cout<<"Factorial given number is -> "<<factorial(4);

    return 0;
}