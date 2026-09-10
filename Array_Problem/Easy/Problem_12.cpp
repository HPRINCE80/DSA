// #include <bits/stdc++.h>
// using namespace std;

//     // Function to find the single non-repeating element using brute force
//     int getSingleElement(vector<int>& arr) {
//         int n = arr.size();

//         // Loop through every element
//         for (int i = 0; i < n; i++) {
//             int num = arr[i]; // current element to check
//             int cnt = 0;

//             // Count occurrences of this element
//             for (int j = 0; j < n; j++) {
//                 if (arr[j] == num)
//                     cnt++;
//             }

//             // If it occurs only once, return it
//             if (cnt == 1) return num;
//         }

//         // This line should never be reached
//         return -1;
//     }

// int main() {
//     vector<int> arr = {4, 1, 2, 1, 2};

//     int ans = getSingleElement(arr);

//     cout << "The single element is: " << ans << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int findElements(vector<int> &nums)
{
    int n = nums.size();
    int xxor = 0;
    for (int i = 0; i < n; i++)
    {
        xxor= xxor ^ nums[i];
    }
    return xxor;
}
int main()
{
    vector<int> nums = {1, 1, 2, 5, 5, 4, 4};
    int find = findElements(nums);
    cout << "Single Elements in the Array" << find << endl;
}