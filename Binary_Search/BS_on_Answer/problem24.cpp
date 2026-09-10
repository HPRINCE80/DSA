#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& C, int A, long long maxLoad)
{
    int painters = 1;
    long long curr = 0;

    for(int i=0;i<C.size();i++)
    {
        if(curr + C[i] <= maxLoad)
        {
            curr += C[i];
        }
        else
        {
            painters++;
            curr = C[i];

            if(painters > A)
                return false;
        }
    }

    return true;
}

long long paint(int A, int B, vector<int>& C)
{
    long long low = *max_element(C.begin(), C.end());
    long long high = accumulate(C.begin(), C.end(), 0LL);

    long long ans = high;

    while(low <= high)
    {
        long long mid = (low + high)/2;

        if(possible(C,A,mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }

    return ans * B;
}

int main()
{
    vector<int> C = {2,1,5,6,2,3};
    int A = 2;
    int B = 5;

    cout << paint(A,B,C);
}