// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an 
// integer k.

// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. 
// The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.

// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
#include<bits/stdc++.h>
using namespace std;

// recursive approach
// time: O(kN), function is called recursively for each index from N-1 to 0
// space: O(N)

int func(int ind, vector<int>& heights, int k){
    // base case
    if(ind == 0)
        return 0;

    // initialise mmStep to INT_MAX
    int mmStep = INT_MAX;

    // try all possible ways
    for(int j=1;j<=k;j++){
        // check if ind-j is non negative
        if(ind-j >= 0){
            int jump = func(ind-j, heights, k) + abs(heights[ind] - heights[ind-j]);
            // update the minimum energy
            mmStep = min(jump, mmStep);
        }
    }
    return mmStep;
}
int frogJump(vector<int>& heights, int k){
    int ind = heights.size()-1;

    // return the minimum energy
    return func(ind, heights, k);
}

// memoization
// time: O(k*N)
// space: O(N)
int func2(int ind, vector<int>& heights, int k, vector<int>& dp){
    // base case
    if(ind == 0)
        return 0;

    // if the result for this index has been previously calculated, return it
    if(dp[ind] != -1) return dp[ind];

    // initialise the ans to INT_MAX;
    int ans = INT_MAX;

    // try all possible steps
    for(int j=1;j<=k;j++){
        // check if ind-j is non-negative
        if(ind-j >= 0){
            int jump = func2(ind-j, heights, k, dp) + abs(heights[ind] - heights[ind-j]);
            //update the minimum energy
            ans = min(ans,jump);
        }
    }
    return dp[ind] = ans;
}
int frogJump2(vector<int>& heights, int k){
    int ind = heights.size()-1;
    // initialise a memoization array to store calculated results
    vector<int> dp(ind+1, -1);
    // return the minimum energy
    return func2(ind, heights, k, dp);
}

// tabulation
// time: O(k*N)
// space: O(N)
int frogJump3(vector<int>& heights, int k){
    int ind = heights.size();

    // initialised a tabulation array to store the calculated results
    vector<int> dp(ind+1, -1);

    dp[0] = 0;

    // loop through the arrau
    for(int i=1;i<ind;i++){
        int mmSteps = INT_MAX;
        // loop to try all possible jumps from 1 to k
        for(int j=1;j<=k;j++){
            if(i - j >= 0){
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[ind-1];
}