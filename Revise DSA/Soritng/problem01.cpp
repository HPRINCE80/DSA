#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n)
{
    // int n = arr.size();
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }

        temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
    cout << "After insertion->";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Bubblesort(vector<int> &arr)
{
    int n = arr.size();
    int temp = 0;
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "After insertion->";
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";

    cout << "\n";
}

void BubblesortOwn(vector<int> &arr)
{
    int temp = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
    cout << "After insertion->";
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";

    cout << "\n";
}

vector<int> insertionsort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();
    cout << "Before sorting->";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    insertionsort(arr);

    cout << "After insertion->";
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";

    cout << "\n";
    // BubblesortOwn(arr);

    return 0;
}