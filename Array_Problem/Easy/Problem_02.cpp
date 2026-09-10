#include <bits/stdc++.h>
using namespace std;

int sorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = 0;
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the Array::";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    { // input the Array
        cout << "Enter the " << i + 1 << " Elements::";
        cin >> arr[i];
    }
    sorted(arr, n);
    cout << "Sorted Aarry is :: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nSecond Largest Element is ::" << arr[n - 2] << endl;
    cout << "Second Smallest Elements is ::" << arr[1];
    return 0;
}