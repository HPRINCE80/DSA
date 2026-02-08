#include <bits/stdc++.h>
using namespace std;
int largestElements(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int n;
    cout << "Enter the size of the Array::";
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {   cout<<"Enter the "<< i <<" Elements::";
        cin >> arr[i];
    }
    int max = largestElements(arr, n);
    cout << "Maximum Element " << max << " in the Array ::";

    return 0;
}