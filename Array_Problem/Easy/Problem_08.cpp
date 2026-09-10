#include <bits/stdc++.h>
using namespace std;
int searchElements(int arr[], int n, int tar)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == tar)
        {

            return i;
        }
    }
    return -1;
}
int main()
{
    int n, tar;
    cout << "Enter the size of the Array-> ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Elments " << i << "-> ";
        cin >> arr[i];
    }
    cout << "Given Array-> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nSearching Elements::";
    cin >> tar;

    int result = searchElements(arr, n, tar);

    cout << "Your Target Elements at the index " << result;

    return 0;
}