#include <bits/stdc++.h>
using namespace std;
void shifting(int arr[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            arr[i] = arr[j];
            i++;
        }
    }

    // Step 2: Fill remaining positions with zero
    while (i < n)
    {
        arr[i] = 0;
        i++;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the Array::";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the ELments " << i << ":: ";
        cin >> arr[i];
    }
    cout << "Given Array::";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    shifting(arr, n);
    cout << "\nAfter the shifting the Zera ends::";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}