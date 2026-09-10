#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long fastPow(long long base, long long exp, long long MOD)
{
    long long result = 1;

    base = base % MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {

            result = result * base % MOD;
        }
        exp = exp / 2;
        base = base * base % MOD;
    }
    return result;
}
int countGoodNumber(long long n)
{
    long long evencount = (n + 1) / 2; // Count of even positions
    long long oddcount = n / 2;        // Count of odd positions

    long long evenway = fastPow(5, evencount, MOD);
    long long oddway = fastPow(4, oddcount, MOD);

    return (evenway * oddway) % MOD;
}

int main()
{
    cout << countGoodNumber(4);
    return 0;
}