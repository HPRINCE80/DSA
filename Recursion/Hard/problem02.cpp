#include <bits/stdc++.h>
using namespace std;


    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col, vector<vector<char>> &board, int n) {
        // Check all columns to the left in the same row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Return true if no attack is possible
        return true;
    }

    // Backtracking function to place queens column by column
    void solve(int col, vector<vector<char>> &board,
               vector<vector<string>> &ans, int n) {
        // If all columns are filled, add current board to answer
        if (col == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                // Convert row vector to string
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        // Try placing queen in all rows of current column
        for (int row = 0; row < n; row++) {
            // Place queen only if safe
            if (isSafe(row, col, board, n)) {
                // Place queen
                board[row][col] = 'Q';
                // Recurse for next column
                solve(col + 1, board, ans, n); 
                // Backtrack and remove queen
                board[row][col] = '.';        
            }
        }
    }

    // Main function to call backtracking
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // Create empty board of size n x n
        vector<vector<char>> board(n, vector<char>(n, '.'));

        // Start backtracking from column 0
        solve(0, board, ans, n);
        return ans;
    }


int main() {
    

    // Set board size
    int n = 4;

    // Get all solutions
    vector<vector<string>> res = solveNQueens(n);

    // Print each board
    for (auto &board : res) {
        for (auto &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
