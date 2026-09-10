// #include<bits/stdc++.h>
// using namespace std;

// int BinarySumSubArray(vector<int>& arr, int goal){
//     int n = arr.size();

//     int count = 0;
//     for(int i=0;i<n;++i)
//     {
//         int sum =0;
//         for(int j=i;j<n;++j){
//            sum = arr[j] + sum;
//            if(sum==goal){

//                count++;
//             }
//         }

//     }
//     return count;
// }
// int main()
// {   vector<int> arr = {1, 1, 0, 1, 0, 0, 1};
//     int goal = 3;
//     cout<<BinarySumSubArray(arr,goal);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int k)
{
    // If k is negative, no such subarrays exist

    int left = 0;

    int res = 0;

    // Traverse the array using right pointer
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] % 2 != 0)
        {
            k--;
        }
        while (k < 0)
        {
            if (nums[left] % 2 != 0)
                k++;
                left++;
        }
        res += (right - left + 1);
    }
    return res;
}

// Function to calculate number of subarrays with sum exactly equal to goal
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    // Return difference between subarrays with sum at most goal and at most (goal - 1)
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

// Helper function to compute number of subarrays with sum at most k

// Driver code
int main()
{

    vector<int> nums = {1, 1, 2, 1, 1};
    int goal = 3;
    cout << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}
