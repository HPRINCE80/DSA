#include <bits/stdc++.h>
using namespace std;
int maxOnes(vector<int> &nums, int k)
{
    int maxlen = 0;
    int len =0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int zero = 0;
        for (int j = 0; j < n; j++)
        {   if(nums[j]==0){
            zero++;
        }
            if(zero > k){
                break;
            }
            len = j-i+1;
            maxlen = max(maxlen, len);

        }
    }
    return maxlen;
}

int optimals(vector<int>& nums, int k) {

        // Left pointer of the sliding window
        int left = 0;

        // Counter for zeros in the current window
        int zerocount = 0;

        // Variable to store the maximum valid window length
        int maxlen = 0;

        // Right pointer expands the window
        for (int right = 0; right < nums.size(); right++) {

            // If current element is 0, increment zerocount
            if (nums[right] == 0) {
                zerocount++;
            }

            // If zero count exceeds k, move left pointer and adjust zerocount
            if (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                // Shrink the window from left
                left++; 
            }

            // Update the maximum window size
            maxlen = max(maxlen, right - left + 1);
        }

        // Return the maximum length found
        return maxlen;
    }

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 3;
    int result = optimals(nums,k);
    cout<<result<<endl;
    return 0;
}