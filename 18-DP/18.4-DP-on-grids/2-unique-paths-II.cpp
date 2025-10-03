// Given an m x n 2d array named matrix, where each cell is either 0 or 1. Return the number of unique ways to go 
// from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]). A cell is blocked if its value is 1, and no path is possible through that cell.

// Movement is allowed in only two directions from a cell - right and bottom.
#include<bits/stdc++.h>
using namespace std;

// recursive solution
// time: O(2^((m+n)*(m+n)))
// space: O(m+n)
int solve(int i, int j, vector<vector<int>>& matrix){
    // base case
    if(i >= 0 && j >= 0 && matrix[i][j] == 1)
        return 0;
    if(i == 0 && j == 0)
        return 1;
    if(i < 0 || j < 0)
        return 0;

    int up = solve(i-1, j, matrix);
    int left = solve(i, j-1, matrix);

    return up+left;
}
int uniquePathsWithObstacles(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    return solve(m-1, n-1, matrix);
}

// memoization:
// time: O(M*N)
// space: O((M+1)+(N-1)) + O(M*N)
int solve2(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    // base case
    if(i >= 0 && j >= 0 && matrix[i][j] == 1)
        return 0;
    if(i == 0 && j == 0)
        return 1;
    if(i < 0 || j < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i-1, j, matrix);
    int left = solve(i, j-1, matrix);

    return dp[i][j] = up+left;
}
int uniquePathsWithObstacles2(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve2(m-1, n-1, matrix, dp);
}

// tabulation
// time: O(M*N)
// space: O(M*N)
int solve3(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 1){
                // obstacle
                dp[i][j] = 0;
                continue;
            }
            if(i==0 && j==0){
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if(i > 0)
                up = dp[i-1][j];
            if(j > 0)
                left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}
int uniquePathsWithObstacles3(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve3(m, n, matrix, dp);
}