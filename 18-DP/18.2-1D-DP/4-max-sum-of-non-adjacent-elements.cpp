// Given an integer array nums of size n. Return the maximum sum possible using the elements of nums such that no two elements taken are adjacent 
// in nums.
#include<bits/stdc++.h>
using namespace std;

// recursion
// time: O(2^N), where N is the given size of array. Thisis because each call branches into 2 more calls
// space: O(N), max depth of recursion stack can go up tp n
int func(int ind, vector<int>& nums){
    // base case
    if(ind == 0)
        return nums[ind];
    if(ind < 0)
        return 0;

    // choosing the cuurent element 
    int pick = nums[ind] + func(ind-2, nums);
    // skipping the current element
    int nonPick =  + func(ind-1, nums);

    // return the maximum
    return max(pick, nonPick);
}
int nonAdjacent(vector<int>& nums){
    int ind = nums.size()-1;
    // return the maximum sum
    return func(ind, nums);
}

// memoization
// time: O(N), overlapping subproblems will return the answer in constant time O(1)
// space: O(N)
int func2(int ind, vector<int>& nums, vector<int>& dp){
    // base case
    if(ind == 0)
        return nums[ind];
    if(ind < 0)
        return 0;

    if(dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + func2(ind-2, nums, dp);
    int nonPick = 0 + func2(ind-1, nums, dp);

    return dp[ind] = max(pick, nonPick);
}
int nonAdjacent2(vector<int>& nums){
    int ind = nums.size()-1;
    vector<int> dp(ind+1, -1);
    return func2(ind, nums, dp);
}

// tabulation
// time: O(N)
// space: O(N)
int nonAdjacent3(vector<int>& nums){
    int ind = nums.size();
    vector<int> dp(ind, -1);

    // base case
    dp[0] = nums[0];
    // iterate through the elements of the array
    for(int i=1;i<ind;i++){
        // calculate the maximum value by either picking the current element or not picking it
        int pick = nums[i];
        if(i > 1){
            pick += dp[i-2];
        }
        int nonPick = dp[i-1];

        // store the max value in dp array
        dp[i] = max(pick, nonPick);
    }
    return dp[ind-1];
}

// space optimization
// time: O(N)
// space: O(1)
int nonAdjacent4(vector<int>& nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1;i<n;i++){
        // pick
        int pick = nums[i];
        if(i > 1)
            pick += prev2;

        // not pick
        int nonPick = 0 + prev;
        // maximum at the current element
        int cur_i = max(pick, nonPick);

        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}