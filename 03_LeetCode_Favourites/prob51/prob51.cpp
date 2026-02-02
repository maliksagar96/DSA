/*
  The cells on a chess board(or in a matrix) having equal values of row - col share the same diagonal and having equal values of row + col share the same anti-diagonal or the other diagonal. 
  This is very useful information in the n queens problem. 
  The logic that I wrote is simple but not the most efficient however. The most efficient solution is written at the bottom.   

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

  vector<vector<string>> queen_positions;

  vector<vector<string>> solveNQueens(int n) {
  
    vector<string> curr_queen(n, string(n, '.'));
    unordered_set<int> cols, diag, anti_diag;
    backtrack(n, 0, curr_queen, cols, diag, anti_diag);
    return queen_positions;

  }

  void backtrack(int n, int row, vector<string>& curr_queen, unordered_set<int>& cols, unordered_set<int>& diag, unordered_set<int>& anti_diag) {
    
    //return logic
    if(row == n) {
      queen_positions.push_back(curr_queen);
      return;
    }


    //backtrack logic
    for(int col = 0;col<n;col++) {
      if(cols.count(col) || diag.count(row-col) || anti_diag.count(row+col))
        continue;

      curr_queen[row][col] = 'Q';
      cols.insert(col);
      diag.insert(row-col);
      anti_diag.insert(row+col);

      backtrack(n, row+1, curr_queen, cols, diag, anti_diag);

      curr_queen[row][col] = '.';
      cols.erase(col);
      diag.erase(row-col);
      anti_diag.erase(row+col);

    }
  }

};

int main() {

  return 0;
}


 class Solution {
private: 
    // Helper function to check if placing a queen at position (row,col) is safe
    bool isSafePlace(int n, vector<string>& nQueens, int row, int col) {
        // Check if there's any queen in the same column above current position
        for(int i=0; i<n; i++) {
            if(nQueens[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal for any queen
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal for any queen
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }

        // If no conflicts found, position is safe
        return true;
    }

    // Recursive helper function to solve N-Queens problem
    void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int row) {
        // Base case: if we've placed queens in all rows, we found a valid solution
        if(row == n) {
            output.push_back(nQueens);
            return;
        }

        // Try placing queen in each column of current row
        for(int col=0; col<n; col++) {
            // If current position is safe
            if(isSafePlace(n, nQueens, row, col)) {
                // Place queen
                nQueens[row][col] = 'Q';
                // Recursively solve for next row
                solveNQueens(n, output, nQueens, row+1);
                // Backtrack: remove queen for trying next position
                nQueens[row][col] = '.';
            }
        }
    }

public:
    // Main function to solve N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;  // Stores all valid solutions
        vector<string> nQueens(n, string(n, '.')); // Initialize empty board
        solveNQueens(n, output, nQueens, 0); // Start solving from row 0
        return output;
    }
};