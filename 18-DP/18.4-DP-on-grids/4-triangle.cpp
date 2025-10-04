// Given a 2d integer array named triangle with n rows. Its first row has 1 element and each succeeding row has one 
// more element in it than the row above it.
// Return the minimum falling path sum from the first row to the last.
// Movement is allowed only to the bottom or bottom-right cell from the current cell.
#include<bits/stdc++.h>
using namespace std;

// recursion
// time: O(2^N)
// space: O(N)
int func(int i, int j, vector<vector<int>>& triangle, int n){
    // if we're at botton row, return value of current cell
    if(i == n-1)
        return triangle[i][j];

    // calculate the sum of 2 possible paths
    int down = triangle[i][j] + func(i+1, j, triangle, n);
    int diagonal = triangle[i][j] + func(i+1, j+1, triangle, n);

    return min(down, diagonal);
}
int minTriangleSum(vector<vector<int>>& triangle){
    // get the number of rows in the triangle
    int n = triangle.size();

    // return the minimum path sum;
    return func(0, 0, triangle, n);
}

// memoization
// time: O(N)
// space: O(N)
int func2(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
    // if result i already calculated
    if(dp[i][j] != -1)
        return dp[i][j];
    // if we're at botton row, return value of current cell
    if(i == n-1)
        return triangle[i][j];

    // calculate the sum of 2 possible paths
    int down = triangle[i][j] + func2(i+1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + func2(i+1, j+1, triangle, n, dp);

    return min(down, diagonal);
}
int minTriangleSum2(vector<vector<int>>& triangle){
    // get the number of rows in the triangle
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // return the minimum path sum;
    return func2(0, 0, triangle, n, dp);
}

// tabulation
// time: O(N*N), as the traiangle is traversed using 2 nested loops
// space: O(N*N), external DP space
int func3(vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
    // initialze the bottom row of dp with the values from the triangle
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    // iterate through the triangle rows in reverse order
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            // calculate the min path sum for current cell
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}
int minTriangleSum3(vector<vector<int>>& triangle){
    // get the number of rows in the triangle
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // return the minimum path sum;
    return func3(triangle, n, dp);
}