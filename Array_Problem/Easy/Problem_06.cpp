#include <bits/stdc++.h>
using namespace std;
void leftshift(int arr[], int n)
{
    int i = 0, temp = 0, temp1 = 0;
    temp1 = arr[1];
    temp = arr[0];
    for (int i = 2; i < n; i++)
    {
        arr[i - 2] = arr[i];
    }
    arr[n - 1] = temp1;
    arr[n - 2] = temp;
};
int main()
{

    int n;
    cout << "Enter the size of the Array::";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Elements->" << i << "::";
        cin >> arr[i];
    }
    cout << "Your Inputs Array::";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    leftshift(arr, n);
    cout << "\nAfter shifting the Aarray::";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
