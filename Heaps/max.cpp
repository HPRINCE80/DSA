#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombination(vector<int> &nums1, vector<int> &num2, int k)
{
    vector<int> allsum;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < num2.size(); j++)
        {
            allsum.push_back(nums1[i] + num2[j]);
        }
        sort(allsum.begin(), allsum.end(), greater<int>());

        vector<int> result(allsum.begin(), allsum.begin() + k);

        return result;
    }
}
    int main(){
        vector<int> nums1 = {7, 3};
        vector<int> nums2 = {1, 6};

        int k = 2;
        vector<int> result = maxCombination(nums1, nums2, k);
        for (int r : result)
        {
            cout << r << " ";
        }
        cout << endl;
        return 0;

    }