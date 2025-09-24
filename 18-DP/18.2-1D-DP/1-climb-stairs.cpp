// Given an integer n, there is a staircase with n steps, starting from the 0th step.

// Determine the number of unique ways to reach the nth step, given that each move can be either 1 or 2 steps at 
// a time.
#include<bits/stdc++.h>
using namespace std;

// recursion
// time: O(2^N)
// space: O(N)

int climbStairs(int n){
    // base case
    if(n == 0) return 1;
    if(n == 1) return 1;

    // taking 1 step at a time
    int oneStep = climbStairs(n-1);
    // taking 2 steps at a time
    int twoSteps = climbStairs(n-2);
    // return total ways
    return oneStep + twoSteps;
}

// memoization
// time: O(N)
// space: O(N) + O(N)
int func(int n, vector<int>& dp){
    // base condition
    if(n <= 1){
        return 1;
    }
    // check if the subproblem is already solved
    if(dp[n] != -1){
        return dp[n];
    }
    // return the calculated value
    return dp[n] = func(n-1, dp) + func(n-2, dp);
}
int climbStairs2(int n){
    vector<int> dp(n+1, -1);
    return func(n, dp);
}

// tabulation
// time: O(N)
// space: O(N)
int climbStairs3(int n){
    // declare dp array of size n+1
    vector<int> dp(n+1, -1);
    // insert the values of base conditions
    dp[0] = 1;
    dp[1] = 1;

    // iterate and update every index of dp array
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// space optimization
int climbStairs4(int n){
    // initialise two variables to store previous results
    int prev2 = 1;
    int prev = 1;

    // iterate and update the variables
    for(int i=2;i<=n;i++){
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}
