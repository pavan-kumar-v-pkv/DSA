// Given an array nums and an integer k.Return the number of non-empty 
// subsequences of nums such that the sum of all elements in the subsequence is 
// equal to k.
#include<bits/stdc++.h>
using namespace std;

// Function to count all subsequences with sum equal to k
// time: O(2^n)
// space: O(n)  for the recursion stack
int func(int ind, int sum, vector<int>& nums){
    // base case: if sum is 0, one valid, subsequence is found
    if(sum == 0) return 1;
    // base case: if all elements are processed or sum becomes negative, no valid subsequence
    if(ind == nums.size() || sum < 0) return 0;

    return func(ind+1, sum-nums[ind], nums) + func(ind+1, sum, nums);
}
int countSubsequences(vector<int>& nums, int target){
    return func(0, target, nums);
}