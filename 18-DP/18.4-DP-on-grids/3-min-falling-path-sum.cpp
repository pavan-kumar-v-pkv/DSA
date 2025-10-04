// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either 
// directly below or diagonally left/right. Specifically, the next element from position (row, col) will be 
// (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
#include<bits/stdc++.h>
using namespace std;

// recursion
// time: O(3^N*M)
// space: O(N)
int func(int i, int j, int m, vector<vector<int>>& matrix){
    // base conditions
    if(j < 0 || j >= m)
        return 1e9;
    if(i == 0)
        return matrix[i][j];

    // calculate the minimum path sum by considering three possible directions:
    // up, left diagonal, and right diagonal
    int up = matrix[i][j] + func(i-1, j, m, matrix);
    int leftDiagonal = matrix[i][j] + func(i-1, j-1, m, matrix);
    int rightDiagonal = matrix[i][j] + func(i-1, j+1, m, matrix);

    return min(up, min(leftDiagonal, rightDiagonal));
}
int minFallingPathSum(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int mini = INT_MAX;

    // iterate through each cell in the first row to find the minimum path
    // sum starting from each of them
    for(int j=0;j<m;j++){
        int ans = func(n-1, j, m, matrix);
        mini = min(mini, ans);
    }

    return mini;
}


// memoization:
// time: O(N*M)
// space: O(N*M)
int func2(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    // base conditions
    if(j < 0 || j >= m)
        return 1e9;
    if(i == 0)
        return matrix[i][j];

    // if the result for this cell is already calculated, return it
    if(dp[i][j] != -1)
        return dp[i][j];

    // calculate the minimum path sum by considering three possible directions:
    // up, left diagonal, and right diagonal
    int up = matrix[i][j] + func2(i-1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + func2(i-1, j-1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + func2(i-1, j+1, m, matrix, dp);

    return min(up, min(leftDiagonal, rightDiagonal));
}
int minFallingPathSum2(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    // memoization table to store computed results
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int mini = INT_MAX;

    // iterate through each cell in the first row to find the minimum path
    // sum starting from each of them
    for(int j=0;j<m;j++){
        int ans = func2(n-1, j, m, matrix, dp);
        mini = min(mini, ans);
    }

    return mini;
}

// tabulation
// time: O(N*M)
// space: O(N*M)
int minFallingPathSum3(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // initialize the first row of dp with values from the matrix
    for(int j=0;j<m;j++){
        dp[0][j] = matrix[0][j];
    }

    // iterate through the matrix rows starting from the second row
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            // calculate the minum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

            // up direction
            int up = matrix[i][j] + dp[i-1][j];
            
            // left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0){
                leftDiagonal += dp[i-1][j-1];
            }
            else{
                leftDiagonal += 1e9;
            }

            // right diagonal direction
            int rightDiagonal = matrix[i][j];
            if(j + 1 < m){
                rightDiagonal += dp[i-1][j+1];
            }
            else{
                rightDiagonal += 1e9;
            }

            // store the minimum of the three paths in dp
            dp[i][j] = min(up, leftDiagonal, rightDiagonal);
        }
    }

    // find the minimum value in the last row of dp, which represents the minimum path sums ending at each cell
    int mini = INT_MAX;
    for(int j=0;j<m;j++){
        mini = max(mini, dp[n-1][j]);
    }

    return mini;
}