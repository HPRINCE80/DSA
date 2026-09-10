#include <bits/stdc++.h>
using namespace std;
void ZeroMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            col0 = 0;
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for( int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            matrix[i][j] = 0;
            
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<n;j++){
            matrix[0][j]=0; 
        }
    }
    if(col0==0){
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }
}

int main()
{ 
    vector<vector<int>> matrix = {{1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
         ZeroMatrix(matrix);
         cout<<"These a Zero Matrix->\n";
         for(auto row : matrix){
            for(auto val : row){
                cout<<val<<" ";
            }
            cout<<endl; 
         }
}