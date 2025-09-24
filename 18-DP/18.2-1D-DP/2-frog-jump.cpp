// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the 
// height of the ith step.
// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() 
// denotes the absolute difference. The frog can jump from any step either one or two steps, provided it exists.
// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
#include<bits/stdc++.h>
using namespace std;

// recursion
// time: O(2^N)
// space: O(N)
int solve(vector<int>& heights, int ind){
    // base case: if the frog is at the first step
    if(ind == 0) return 0;

    // recursively calculate the energy required to jump to
    // the current step from the previous step
    int jumpOne = solve(heights, ind-1) + abs(heights[ind] - heights[ind-1]);
    // initialize the jumpTwo to a large value
    int jumpTwo = INT_MAX;
    // if possible, recursively calculate the energy required to juump to the current step from 2 steps back
    if(ind > 1){
        jumpTwo = solve(heights, ind-2) + abs(heights[ind] - heights[ind-2]);
    }

    return min(jumpOne, jumpTwo);
}
int frogJump(vector<int>& heights){
    int n = heights.size();
    return solve(heights, n-1);
}

// memoization
// time: O(N)
// space: O(N)
int solve2(int ind, vector<int>& heights, vector<int>& dp){
    // base case: if the frog is at the first step
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    // recursively calculate the energy required to jump to
    // the current step from the previous step
    int jumpOne = solve2(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    // initialize the jumpTwo to a large value
    int jumpTwo = INT_MAX;
    // if possible, recursively calculate the energy required to juump to the current step from 2 steps back
    if(ind > 1){
        jumpTwo = solve2(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    }

    return dp[ind] = min(jumpOne, jumpTwo);
}
int frogJump2(vector<int>& heights){
    int n = heights.size();
    vector<int> dp(n-1, -1);
    return solve2(n-1, heights, dp);
}

// tabulation
// time: O(N)
// space: O(N)
int frogJump3(vector<int>& heights){
    int n = heights.size();
    vector<int> dp(n, -1);
    dp[0] = 0; // base case

    for(int ind = 1; ind < n; ind++){
        int jumpOne = dp[ind-1] + abs(heights[ind] - heights[ind-1]);
        int jumpTwo = INT_MAX;
        // store minimum energy for this stair
        if(ind > 1){
            jumpTwo = dp[ind - 2] + abs(heights[ind] - heights[ind - 2]);
        }
        dp[ind] = min(jumpOne, jumpTwo);
    }

    return dp[n-1];
}

// space optimized
// time: O(N)
// space: O(1)
int frogJump4(vector<int>& heights){
    int n = heights.size();
    int prev = 0, prev2 = 0; // base cases

    for(int ind = 1; ind < n; ind++){
        int jumpOne = prev + abs(heights[ind] - heights[ind-1]);
        int jumpTwo = INT_MAX;
        // store minimum energy for this stair
        if(ind > 1){
            jumpTwo = prev2 + abs(heights[ind] - heights[ind - 2]);
        }
        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }

    return prev;
}