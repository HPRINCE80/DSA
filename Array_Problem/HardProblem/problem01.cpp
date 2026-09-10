#include <bits/stdc++.h>
using namespace std;
long long FindPascal(int r, int c)
{
    int n = r - 1;
    int k = c - 1;
    if (k > n - k)
    {
        k = n - k;
    }
    long long res = 1;
    for (int i = 0; i < k; i++)
    {
        res = res * (n - i);
        res = res / (i+1);
    }
    return res;
}
int main()
{
    int r, c;
    cout << "Enter the Value of r and c->\n";
    cin >> r >> c;
    
    cout<<FindPascal(r,c);
    return 0;
}