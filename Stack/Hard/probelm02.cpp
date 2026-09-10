#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1); // default -1 se fill kar do
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int actualIndex = i % n;

        // yaha likho:
        // 1. while loop: jab tak stack top <= arr[actualIndex] hai, pop karo
        while (!st.empty() && st.top() <= arr[actualIndex])
        {
            st.pop();
        }

        // 2. agar i < n (matlab hum "real" pass me hain, extra round me nahi):
        if (i < n)
        {
            if (st.empty())
            {
                result[actualIndex] = -1;
            }
            else
            {
                result[actualIndex] = st.top();
            }
        }
        //       - agar stack khali hai, result[actualIndex] = -1
        //       - warna result[actualIndex] = stack ka top
        st.push(arr[actualIndex]);
        // 3. arr[actualIndex] ko push kar do (ye hamesha hoga, chahe i < n ho ya na ho)
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> result = nextGreaterElements(arr);

    for (int x : result)
        cout << x << " ";
    // Expected: 2 -1 2

    return 0;
}