#include <bits/stdc++.h>
using namespace std;

int optimalsSolution(vector<int> &arr)
{
    int maxlen = 0;
    int lastfruite = -1, secondlast = -1;
    int currcount = 0, lastfruitest = 0;
    for (int fruite : arr)
    {
        if (fruite == lastfruite || fruite == secondlast)
        {
            currcount++;
        }
        else
        {
            currcount = lastfruitest + 1;
        }
    

        if (fruite == lastfruite)
        {
            lastfruitest++;
        }
        else
        {
            lastfruitest = 1;
            secondlast = lastfruite;
            lastfruite = fruite;
        }
        maxlen = max(maxlen, currcount);
    }
    return maxlen;
}

int fruits(vector<int> &arr)
{
    int maxfruite = 0;
    int n = arr.size();
    for (int start = 0; start < n; start++)
    {
        unordered_map<int, int> basket;
        int currentCount = 0;
        for (int end = 0; end < n; end++)
        {
            basket[arr[end]];
            if (basket.size() > 2)
            {
                break;
            }
            currentCount++;
        }
        maxfruite = max(maxfruite, currentCount);
    }
    return maxfruite;
}
int main()
{

    vector<int> fruit = {1, 2, 1};
    cout << fruits(fruit) << endl; // Output: 3
    return 0;

    return 0;
}