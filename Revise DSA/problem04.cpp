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
void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        for (int k = 1; k < 2 * i + 1; k++)
        {
            cout << "1 ";
        }
        for (int l = 0; l < n - i; l++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        for (int k = 0; k < 2 * (n - i - 1); k++)
        {
            cout << "1 ";
        }
        for (int l = 0; l <= i; l++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern20(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << "  ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "* ";
        }
        for (int k = 0; k <= 2 * i + 1; k++)
        {
            cout << "  ";
        }
        for (int p = 0; p < n - i - 1; p++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
void pattern22(int n) {
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            int top   = i;
            int left  = j;
            int bottom = (2*n-2) - i;
            int right  = (2*n-2) - j;

            cout << n - min({top, left, bottom, right}) << " ";
        }
        cout << endl;
    }
}
int main()
{
    pattern22(5);

    return 0;
}
