#include <bits/stdc++.h>
using namespace std;
void zeroMatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int col = 0; col < n; col++)
                {
                    if (matrix[i][col] != 0)
                    {
                        matrix[i][col] = -1;
                    }
                }
                for (int row = 0; row < m; row++)
                {
                    if (matrix[row][j] != 0)
                    {
                        matrix[row][j] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    zeroMatrix(arr);
    cout << "Zero Matrix->\n";
    for (auto row : arr)
    {
        for (auto i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
//  using namespace std;

// class Solution {
// public:
//      // Function to set entire row and column to 0 if an element in the matrix is 0
//     void setZeroes(vector<vector<int>>& matrix) {
//         // Get number of rows
//         int m = matrix.size();
//         // Get number of columns
//         int n = matrix[0].size();

//         // Traverse each cell of the matrix
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // If current cell is zero
//                 if (matrix[i][j] == 0) {
//                     // Mark all elements in this row as -1 (except existing zeros)
//                     for (int col = 0; col < n; col++) {
//                         if (matrix[i][col] != 0)
//                             matrix[i][col] = -1;
//                     }
//                     // Mark all elements in this column as -1 (except existing zeros)
//                     for (int row = 0; row < m; row++) {
//                         if (matrix[row][j] != 0)
//                             matrix[row][j] = -1;
//                     }
//                 }
//             }
//         }

//         // Second pass: replace all -1 markers with 0
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == -1)
//                     matrix[i][j] = 0;
//             }
//         }
//     }
// };

// int main() {
//     // Example matrix
//     vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

//     // Create Solution object
//     Solution sol;
//     // Call function to modify matrix
//     sol.setZeroes(matrix);

//     // Print final matrix
//     for (auto row : matrix) {
//         for (auto val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }