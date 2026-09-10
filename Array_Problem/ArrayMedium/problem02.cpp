#include <bits/stdc++.h>
using namespace std;
void sort_0to1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
}
void sort1_0_to_1(vector<int> &nums)
{
    int count0 = 1, count1 = 0, count2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count0++;
        }
        else if (nums[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    int index = 0;

    for (int i = 0; i < count0; i++)
        nums[index++] = 0;

    for (int i = 0; i < count1; i++)
        nums[index++] = 1;

    for (int i = 0; i < count2; i++)
        nums[index++] = 2;
}
void usingoptimals(vector<int> &nums)
{
    int l = 0, mid = 0, high = nums.size() - 1, n = nums.size();
    
    while (mid < high)
    {
         if (nums[mid] == 0)
        {
            l++;
            mid++;
            swap(nums[l], nums[mid]);
        }
       else if (nums[mid] == 1)
        {
            mid++;
        }
         else 
        {
            high--;
            swap(nums[mid], nums[high]);
        }
    }
}
int main()
{
    vector<int> nums = {0, 1, 2, 0, 2, 0, 0};
    sort_0to1(nums);
    cout << "Arrenging Array-> ";
    for (int i : nums)
    {
        cout << i << " ";
    }
    sort1_0_to_1(nums);
    cout << "\nSort the Array in order 0 to 1->Using Better Aporouch->";
    for (int x : nums)
    {
        cout << x << " ";
    }
   usingoptimals(nums);
   cout<<"\nSortinh the Array by order 0 to 1 using optimals Apporouch->";
   for(int h : nums){
    cout<< h << " ";
   }
    return 0;
}
