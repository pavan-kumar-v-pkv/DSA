// The challenge of arranging n queens on a n × n chessboard so that no two 
// queens attack one another is known as the "n-queens puzzle."
// Return every unique solution to the n-queens puzzle given an integer n. The 
// answer can be returned in any sequence.
// Every solution has a unique board arrangement for the placement of the 
// n-queens, where 'Q' and '.' stand for a queen and an empty space, respectively.
#include <bits/stdc++.h>
using namespace std;

// Function to check if a queen can be placed at position (row, col)
// time: O(N!) where N is the number of queens
// space: O(N) for the recursion stack
class Solution{
    public:
    bool isSafe1(int row, int col, vector<string>& board, int n){
        int r = row, c = col;
        // check the left diagonal
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        // reset to the original position
        r = row;
        c = col;
        // check left side
        while(c >= 0){
            if(board[r][c] == 'Q')
                return false;
            c--;
        }
        // reset to the original position
        r = row;
        c = col;
        // check lower left diagonal
        while(r < n && c >= 0){
            if(board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string> >& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe1(row, col , board, n)){
                board[row][col] = 'Q'; // Place the queen
                solve(col+1, board, ans, n); // Recur to place the next queen
                board[row][col] = '.'; // Backtrack: remove the queen
            }
        }
    }
    vector<vector<string> > solveNQueens(int n){
        vector<vector<string> > ans;
        vector<string> board(n);
        // Initialize the board with '.' representing empty spaces
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        // Start the backtracking process from the first column
        solve(0, board, ans, n);
        return ans;
    }
};

