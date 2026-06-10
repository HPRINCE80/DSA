#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int e){
    int i = s;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    // agar left mein kuch bacha ho
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // agar right mein kuch bacha ho
    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i - s];
    }
}
void merge_sort(vector<int> &arr, int s, int e)
{
    if (s == e)
    {
        return;
    }
    int mid = (s + e) / 2;

    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);

    merge(arr,s,mid,e);

}

int main()
{  
     vector<int> arr = {5, 2, 8, 4, 1};
     merge_sort(arr,0,arr.size()-1);
     for(int x: arr){
        cout<<x<<" ";
     }
     cout<<endl;
    return 0;
}