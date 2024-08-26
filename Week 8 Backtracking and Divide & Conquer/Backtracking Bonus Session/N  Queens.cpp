#include <vector>           // Required for using the vector data structure
#include <string>           // Required for using the string class
#include <unordered_map>    // Required for using the unordered_map data structure

using namespace std;

class Solution {
public:
    // Maps to track whether a row, top diagonal, or bottom diagonal is already occupied by a queen
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> topDiagonal;
    unordered_map<int, bool> bottomDiagonal;

    // Function to store the current board configuration as a solution
    // board: 2D character board representing the current state of the chessboard
    // ans: vector of solutions, where each solution is a vector of strings
    void storeSolution(vector<vector<char>>& board, vector<vector<string>>& ans) {
        vector<string> tempSol;
        for (auto vec : board) {
            string temp = "";
            for (auto ch : vec) {
                temp.push_back(ch);
            }
            tempSol.push_back(temp);
        }
        ans.push_back(tempSol); // Store the current solution
    }

    // Function to check if it's safe to place a queen at (row, col)
    // row: the row index
    // col: the column index
    // board: 2D character board representing the current state of the chessboard
    bool isSafe(int row, int col, vector<vector<char>>& board) {
        // Check if the row is already occupied by another queen
        if (rowCheck[row]) return false;
        // Check if the top diagonal (/) is already occupied by another queen
        if (topDiagonal[col - row]) return false;
        // Check if the bottom diagonal (\) is already occupied by another queen
        if (bottomDiagonal[row + col]) return false;

        // If none of the above conditions are true, the place is safe
        return true;
    }

    // Recursive function to solve the N-Queens problem
    // board: 2D character board representing the current state of the chessboard
    // ans: vector of solutions, where each solution is a vector of strings
    // n: the size of the chessboard (n x n)
    // col: the current column to place a queen
    void solve(vector<vector<char>>& board, vector<vector<string>>& ans, int n, int col) {
        // Base case: if all columns have been processed, store the solution
        if (col >= n) {
            storeSolution(board, ans);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board)) {
                // Place the queen at (row, col)
                board[row][col] = 'Q';
                // Mark the current row, top diagonal, and bottom diagonal as occupied
                rowCheck[row] = true;
                topDiagonal[col - row] = true;
                bottomDiagonal[row + col] = true;

                // Recur to place the next queen in the next column
                solve(board, ans, n, col + 1);

                // Backtrack: remove the queen and unmark the row, diagonals
                board[row][col] = '.';
                rowCheck[row] = false;
                topDiagonal[col - row] = false;
                bottomDiagonal[row + col] = false;
            }
        }
    }

    // Function to solve the N-Queens problem and return all possible solutions
    // n: the size of the chessboard (n x n)
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;  // To store all possible solutions
        vector<vector<char>> board(n, vector<char>(n, '.'));  // Initialize an empty n x n board
        int col = 0;  // Start placing queens from the first column
        solve(board, ans, n, col);  // Start the recursive solution
        return ans;  // Return all possible solutions
    }
};
