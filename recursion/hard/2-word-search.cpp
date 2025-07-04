// Given a grid of n x m dimension grid of characters board and a string word.
// The word can be created by assembling the letters of successively surrounding
// cells, whether they are next to each other vertically or horizontally. It is 
// forbidden to use the same letter cell more than once.

// Return true if the word exists in the grid otherwise false.
#include <bits/stdc++.h>
using namespace std;    

// Function to check if the word can be formed in the grid
// time: O(n * m * 4^k) where n is the number of rows, m is the number of columns, and k is the length of the word
// space: (O(n * m) for the visited array and recursion stack
bool func(vector<vector<char> >& board, int i, int j, string& s, int k){
    // if all characters of the word are found
    if(k == s.size())
        return true;
    // boundary conditions and character mismatch check
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != s[k]){
        return false;
    }
    // initialise the answer as false
    bool ans = false;
    // temporarily mark the cell as visited
    char temp = board[i][j];
    board[i][j] = '#';
    // explore all four directions: down, up, down, right, left
    ans |= func(board, i+1, j, s, k+1);
    ans |= func(board, i-1, j, s, k+1);
    ans |= func(board, i, j+1, s, k+1);
    ans |= func(board, i, j-1, s, k+1);
    // backtrack: unmark the cell
    board[i][j] = temp;
    return ans;
}
bool exist(vector<vector<char> >& board, string word){
    // iterate through each cell in the grid
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            // if the first character macthes, start the search
            if(board[i][j] == word[0]){
                if(func(board, i, j, word, 0))
                    return true;
            }
        }
    }
    return false;
}    