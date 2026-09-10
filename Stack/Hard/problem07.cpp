#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollesion(vector<int> &asteroids)
{
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < asteroids.size(); i++)
    {
        int a = asteroids[i];

        if (a > 0)
        {
            st.push(a);
        }

        else
        {
            while (!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top())
            {
                st.pop();
            }
            if (!st.empty() && st.top() == abs(asteroids[i]))
            {

                // Destroy both the asteroids
                st.pop();
            }

            else if (st.empty() || st.top() < 0)
            {
                st.push(a);
            }
        }
    }
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop(); // ye bhi zaroori hai! warna infinite loop chalega
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    vector<int> ast = {5, 10, -5};
    vector<int> res = asteroidCollesion(ast);
    for (int x : res)
        cout << x << " ";
    return 0;
}