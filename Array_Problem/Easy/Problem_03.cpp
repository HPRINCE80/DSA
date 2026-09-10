#include <bits/stdc++.h>
using namespace std;
bool sorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the size of the Array::";
    cin >> n;
    int arr[n];
    cout << "Enter the Elments::";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<boolalpha;
    cout<< sorted(arr, n);
        
}