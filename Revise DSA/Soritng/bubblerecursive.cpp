#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr, int n)
{
    if (n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            swap(arr[i + 1], arr[i]);
        }
    }
    bubblesort(arr, n - 1);
}
int main()
{
    vector<int> arr = {5, 2, 8, 4, 1};
    cout<<"Befire the sorting->  ";
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"After sorting-> ";
    bubblesort(arr, arr.size());
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}