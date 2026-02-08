#include <bits/stdc++.h>
using namespace std;

// Function to remove duplicates from sorted array in-place
int removeDuplicates(int nums[], int n)
{

    // Pointer for the position of last unique element
    int i = 0;

    // Traverse the array starting from the second element
    for (int j = 1; j < n; j++)
    {
        // If current element is different from last unique element
        if (nums[j] != nums[i])
        {
            // Move pointer for unique element forward
            i++;
            // Place the new unique element at the next position
            nums[i] = nums[j];
        }
    }

    // i is index of last unique element, count = i + 1
    return i + 1;
}

int main()
{
    int n;
    cout << "Enter the size of the Array::";
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Elements " << i << " ::";
        cin >> nums[i];
    }
    cout << "Given Array::";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    sort(nums, nums + n);
    int k = removeDuplicates(nums, n);

    cout << "\nUnique count = " << k << "\n";
    cout << "Array after removing duplicates: ";
    for (int x = 0; x < k; x++)
    {
        cout << nums[x] << " ";
    }
    cout << endl;
}
