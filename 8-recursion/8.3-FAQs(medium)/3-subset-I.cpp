// Given an array nums of n integers.Return sum of all subsets of the array nums.
// Output can be printed in any order.
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the sum of all subsets of the array
// time: O(2^n)
// space: O(n) for the recursion stack
void func(int ind, int sum, vector<int>& nums, vector<int>& ans){
    // base case: if index reaches the end of the nums vector
    if(ind == nums.size()){
        ans.push_back(sum);
        return;
    }

    // include the current element in the sum
    func(ind+1, sum + nums[ind], nums, ans);
    // exclude the current element from the sum
    func(ind+1, sum, nums, ans);
}
vector<int> subsetSum(vector<int>& nums){
    vector<int> ans;
    func(0, 0, nums, ans);
    return ans;
}