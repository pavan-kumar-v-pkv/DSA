// Given two integers m and n, representing the number of rows and columns of a 2d array named matrix. Return the 
// number of unique ways to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]).
// Movement is allowed only in two directions from a cell: right and bottom.

#include<bits/stdc++.h>
using namespace std;

// recursive approach
// time: O(2^(m*n))
// space: O(()m-1) + (n-1)
int solve(int i, int j){
    // base cases:
    if(i==0 && j==0)
        return 1;
    // if we go out of bounds
    if(i < 0 || j < 0)
        return 0;

    // calculare the number of ways by moving up and left recursively
    int up = solve(i-1, j);
    int left = solve(i, j-1);

    // return the total ways
    return up + left;
}
int uniquePath(int m, int n){
    return solve(m-1, n-1);
}

// memoization:
// time: O(M*N)
// space: recursion stack space: O((n-1)+(m-1)) and O(m*n) for DP array
int solve2(int i, int j, vector<vector<int>>& dp){
    // base case
    if(i == 0 && j == 0)
        return 1;
    // if we go out of bounds
    if(i < 0 || j < 0){
        return 0;
    }

    // if we have already computer the number of ways for this cell, return it
    if(dp[i][j] != -1) return dp[i][j];

    int up = solve2(i-1, j, dp);
    int left = solve2(i, j-1, dp);

    return dp[i][j] = up + left;
}
int uniquePath2(int m, int n){
    // initialise a memoization table (dp) to store the results of subproblems
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // return the total count (0 based indexing)
    return solve2(m-1, n-1, dp);
}

// tabulation
// time: O(M*N)
// space: O(M*N)
int func3(int m , int n, vector<vector<int>>& dp){
    // loop through the grid using 2 nested loops
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // base condition
            if(i==0 && j==0){
                dp[i][j] = 1;
                // skip the rest of the loop and contine with the next iteration
                continue;
            }

            // initialise variables to store the number of ways from cell above and left
            int up = 0;
            int left = 0;

            // if we are not at the first row (i > 0), update up with the value from the cell above
            if(i > 0)
                up = dp[i-1][j];
            // if we are not at the first column (j > 0), update left with the value from the cell to left
            if(j > 0)
                left = dp[i][j-1];

            // calculate the number of ways to reach the current cell by adding up and left
            dp[i][j] = up + left;

        }
    }
    return dp[m-1][n-1];
}
int uniquePaths3(int m, int n){
    // initialise a memoization table to store the results of subproblems
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // return the total count
    return func3(m, n, dp);
}