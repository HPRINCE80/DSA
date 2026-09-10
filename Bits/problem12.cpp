#include <bits/stdc++.h>
using namespace std;
vector<int> getdivisor(int N)
{
    vector<int> res;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            if (i != N / i)
            {
                res.push_back(N / i);
            }
        }
    }
    return res;
}
int main()
{
    int N = 6;
    vector<int> result = getdivisor(N);
    for(int val : result){
        cout<<val<<" , ";
    }
    cout<<endl;

    return 0;
}