#include <bits/stdc++.h>
using namespace std;
int countDigit(int n)
{
    int count = 0;

    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}
 
int countDigitoptimals(int n)
{
    return floor(log10(n) + 1);
}
int main()
{  
    cout << "Enter a number: ";
    int n;
    cin >> n;
    cout << "Number of digits in " << n << " is: " << countDigit(n) << endl;
    cout << "Number of digits in " << n << " is: " << countDigitoptimals(n) << endl;
}