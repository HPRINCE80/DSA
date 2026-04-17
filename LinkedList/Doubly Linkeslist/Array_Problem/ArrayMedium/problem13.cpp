#include <bits/stdc++.h>
using namespace std;
int SubArray(vector<int>&nums, int k)
{
    int count = 0;
    int sum = 0;
    unordered_map<int, int> PrefixSumcount;
    int PrefixSum = 0;
    int n = nums.size();
    PrefixSumcount[0] = 1;
    for (int i = 0; i < n; i++)
    {
        PrefixSum += nums[i];

        int remove = PrefixSum - k;
        if (PrefixSumcount.find(remove) != PrefixSumcount.end());

        {
            count += PrefixSumcount[remove];
        }
        PrefixSumcount[PrefixSum]++;
    }
    return count;
}
int main()
{
    vector<int> nums = { {1, 2, 3}};
    int k = 5;
    int answer = SubArray(nums,k);
    cout<<"The Nunber of Sub Array->  "<<answer<<endl;

    return 0;
}