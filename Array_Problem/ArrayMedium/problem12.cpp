#include <bits/stdc++.h>
using namespace std;
vector<int> SprialMatrix(vector<vector<int>> &matrix)
{
    vector<int> result;
    int top = 0;
    int left = 0;
    int n = matrix.size() - 1;
    int m = matrix[0].size() - 1;
    // Traverse the matrix in spiral order
    while (top <= n && left <= m)
    {
        for (int i = left; i <= m; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        for (int j = top; j <= n; j++)
        {
            result.push_back(matrix[j][m]);
        }
        m--;
        if (top <= n)
        {
            for (int i = m; i >= left; i--)
            {
                result.push_back(matrix[n][i]);
            }
            n--;
        }
        if (left <= m)
        {
            for (int i = n; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
         
        vector<int> answer = SprialMatrix(matrix);
        cout<<"Sprial Matrix->\n";
        
            for(auto val : answer){
                cout<< val<<" ";
            }
            
    

    return 0;
}