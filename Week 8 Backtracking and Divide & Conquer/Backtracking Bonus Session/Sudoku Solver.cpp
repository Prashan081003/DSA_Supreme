#include <vector>   // Required for using the vector data structure

using namespace std;

class Solution {
public:
    // Function to check if placing the value at (row, col) is safe
    // row: the row index
    // col: the column index
    // value: the character value (1-9) to be placed
    // board: 2D vector representing the Sudoku board
    bool isSafe(int row, int col, char value, vector<vector<char>>& board) {
        int n = board.size(); // Get the size of the board (9x9 for Sudoku)

        // Check the row for the same value
        for (int i = 0; i < n; i++) {
            if (board[row][i] == value) {
                return false;
            }
        }

        // Check the column for the same value
        for (int i = 0; i < n; i++) {
            if (board[i][col] == value) {
                return false;
            }
        }

        // Check the 3x3 subgrid for the same value
        // (row/3) gives the subgrid's row index, and (col/3) gives the subgrid's column index
        for (int i = 0; i < n; i++) {
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
                return false;
            }
        }

        // If the value is not found in the same row, column, or subgrid, it's safe to place
        return true;
    }

    // Recursive function to solve the Sudoku puzzle
    // board: 2D vector representing the Sudoku board
    bool solve(vector<vector<char>>& board) {
        int n = board.size(); // Get the size of the board (9x9 for Sudoku)

        // Iterate through each cell of the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check for an empty cell
                if (board[i][j] == '.') {
                    // Try placing each digit from '1' to '9'
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isSafe(i, j, ch, board)) {
                            // Place the digit in the cell
                            board[i][j] = ch;

                            // Recursively attempt to solve the rest of the board
                            bool recursionKaAns = solve(board);
                            if (recursionKaAns) return true; // If successful, return true
                            else {
                                // If not successful, backtrack by resetting the cell
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false; // If no digit can be placed, return false
                }
            }
        }
        return true; // If the board is successfully filled, return true
    }

    // Main function to solve the Sudoku puzzle
    // board: 2D vector representing the Sudoku board
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // Start solving the board
    }
};
