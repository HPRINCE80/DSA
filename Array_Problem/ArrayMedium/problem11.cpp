#include <bits/stdc++.h>
using namespace std;
void RotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
    RotateMatrix(mat);
    cout << "Rotated Matrix->\n";
    for (auto row : mat)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}