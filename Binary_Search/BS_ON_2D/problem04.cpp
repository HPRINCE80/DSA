#include <bits/stdc++.h>
using namespace std;
vector<int> findthenumber(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxrow = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][mid] > matrix[maxrow][mid])
            {
                maxrow = i;
            }
        }

        int left = (mid - 1 >= 0) ? matrix[maxrow][mid - 1] : -1;
        int right = (mid + 1 < m) ? matrix[maxrow][mid + 1] : -1;

        if(matrix[maxrow][mid]> left && matrix[maxrow][mid]> right){
            return {maxrow, mid};
        }
        else if(left> matrix[maxrow][mid]){
            high = mid -1;

        }
        else{
            low = mid -1;
        }
    }
    return {-1,-1};
}
int main()
{
        vector<vector<int>> mat = {
        {10,20,15},
        {21,30,14},
        {7,16,32}
    };

    vector<int> ans = findthenumber(mat);

    cout << ans[0] << " " << ans[1];
    return 0;
}