#include <bits/stdc++.h>
using namespace std;
vector<int> replacewithramk(vector<int> &arr)
{
    vector<int> rankArr;

    for (int i = 0; i < arr.size(); i++)
    {

        unordered_set<int> smaller;

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] < arr[i])
            {
                smaller.insert(arr[j]);
            }
        }
        int rank = smaller.size() + 1;
        rankArr.push_back(rank);
    }
    return rankArr;
}
int main()
{

    vector<int> arr = {20, 15, 26, 2, 98, 6};
    vector<int> result = replacewithramk(arr);
    for(int r : result){
        cout<<r<<" ";
    }
    return 0;
}