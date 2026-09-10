#include <bits/stdc++.h>
using namespace std;
double power(double x, int n)
{
    if (n == 0)
        return 1.0;

    if (n == 1)
        return x;
    if (n % 2 == 0)
        return power(x * x, n / 2);

    return x * power(x * x, n / 2);
}
double mypow(double x, int n)
{
    int num = n;
    if (num < 0)
    {
        return (1.0 / power(x, -1 * num));
    }
    return power(x, num);
}
int main()
{
    double x = 2;
    int n = 2;

    // Calculate x raised to n
    double result = mypow(x, n);

    // Print the result
    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}