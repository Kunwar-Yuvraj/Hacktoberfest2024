#include <iostream>
#include <vector>

using namespace std;

// Function to print the board configuration
void printBoard(const vector<vector<int>>& board) {
    int boardSize = board.size();
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            cout << (board[row][col] ? "Q " : ". ");
        }
        cout << "\n";
    }
}

// Function to check if placing a queen at (row, col) is safe
bool isPlacementSafe(const vector<vector<int>>& board, int row, int col) {
    int boardSize = board.size();

    // Check the row on the left side
    for (int c = 0; c < col; c++) {
        if (board[row][c]) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c]) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (int r = row, c = col; c >= 0 && r < boardSize; r++, c--) {
        if (board[r][c]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool placeQueens(vector<vector<int>>& board, int col) {
    int boardSize = board.size();

    // Base case: All queens are placed
    if (col >= boardSize) {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < boardSize; row++) {
        if (isPlacementSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recursively try to place the remaining queens
            if (placeQueens(board, col + 1)) {
                return true;
            }

            // Backtrack: Remove the queen
            board[row][col] = 0;
        }
    }

    // No valid placement found in this column
    return false;
}

// Function to solve the N-Queens problem
bool solveNQueens(int boardSize) {
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

    if (!placeQueens(board, 0)) {
        cout << "Solution does not exist\n";
        return false;
    }

    printBoard(board);
    return true;
}

// Driver function to test the N-Queens solver
int main() {
    int boardSize;

    // Prompt user for input
    cout << "Enter the size of the board (N): ";
    cin >> boardSize;

    // Validate input
    if (boardSize < 1) {
        cout << "Invalid board size. Please enter a positive integer.\n";
        return 1; // Exit with error
    }

    // Solve the N-Queens problem for the given board size
    if (!solveNQueens(boardSize)) {
        return 1; // Exit with error if no solution exists
    }

    return 0; // Successful execution
}
