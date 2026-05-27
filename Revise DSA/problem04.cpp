#include <bits/stdc++.h>
using namespace std;

void pattern11(int n)
{

    for (int i = 0; i < n; i++)
    {
        int start = 0;
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }

        cout << endl;
    }
};
void pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        for (int k = 0; k < 2 * (n - i); k++)
        {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern13(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern14(int n)
{
    char start = 'A';
    for (int i = 0; i < n; i++)
    {
        start = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "1" << " ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << ch << " ";
            if (k <= breakpoint)
                ch++;
            else
                ch--;
        }
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << "1" << " ";
        }
        cout << endl;
    }
}
int main()
{
    pattern15(5);

    return 0;
}
