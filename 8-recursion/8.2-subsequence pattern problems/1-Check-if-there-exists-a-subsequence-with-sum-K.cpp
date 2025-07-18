// Given an array nums and an integer k. R﻿eturn true if there exist 
// subsequences such that the sum of all elements in subsequences is equal to
// k else false.
#include<bits/stdc++.h>
using namespace std;

// Function to check if there exists a subsequence with sum equal to k
// time: O(2^n)
// space: O(n) for the recursion stack
bool func(int ind, int sum, vector<int>& nums){
    // base case: if all elements are processed, check if sum is 0
    if(ind == nums.size())
        return sum == 0;

    return func(ind+1, sum-nums[ind], nums) || func(ind+1, sum, nums);
}
bool checkSubsequencesSum(vector<int>& nums, int target){
    return func(0, target, nums);
}