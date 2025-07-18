// Create a program that fills in the blank cells in a Sudoku puzzle to solve
// it.
// Every sudoku solution needs to follow to these guidelines:
// 1) In every row, the numbers 1 through 9 must appear exactly once.
// 2) In every column, the numbers 1 through 9 must appear exactly once.
// 3) In each of the grid's nine 3x3 sub-boxes, the numbers 1 through 9 must
// appear exactly once.
// Empty cells are indicated by the '.' character.
#include <bits/stdc++.h>
using namespace std;

// Function to check if placing num in cell (i, j) is valid
// time: O(9^E) where E is the number of empty cells
// space: O(1) for the visited array and recursion stack
bool areRulesMet(vector<vector<char> >& board, int row, int col, char digit){
    for(int i=0;i<9;i++){
        if(board[row][i] == digit || board[i][col] == digit)
            return false;
    }
    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;
    for(int i=startRow;i<startRow+3;i++){
        for(int j=startCol;j<startCol+3;j++){
            if(board[i][j] == digit)
                return false; // digit already exists in the 3x3 sub-box
        }
    }
    return true; // placing digit in cell (row, col) is valid
}
bool solve(vector<vector<char>> &board)
{
    // size of the board
    int n = 9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // empty cell found
            if (board[i][j] == '.')
            {
                // try placing numbers 1 to 9 in the cell
                for (char num = '1'; num <= '9'; num++)
                {
                    // check if placing num in cell (i, j) is valid
                    if (areRulesMet(board, i, j, num))
                    {
                        // place the number in the cell
                        board[i][j] = num;
                        // recursively call the function to solve the rest of the board
                        if (solve(board))
                        {
                            return true; // if solved, return true
                        }
                        else
                        {
                            // backtrack: unmark the cell
                            board[i][j] = '.';
                        }
                    }
                }
                return false; // if no number can be placed, return false
            }
        }
    }
    return true; // if no empty cell found, return true (board is solved)
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}
