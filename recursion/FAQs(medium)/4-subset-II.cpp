// Given an integer array nums, which can have duplicate entries, provide the power set. Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.
#include<bits/stdc++.h>
using namespace std;

// Function to generate the power set of a given set with duplicates
// time: O(n * 2^n) 
// space: O(n) for storing the result
void func(int ind, vector<int>& arr, vector<int>& nums, vector<vector<int> >& ans){
    // base case: if index reaches the end of nums
    if(ind == nums.size()){
        ans.push_back(arr);
        return;
    }

    // include the current element in the subset
    arr.push_back(nums[ind]);
    func(ind+1, arr, nums, ans);
    arr.pop_back(); // backtrack

    // skip duplicates
    for(int i=ind+1; i<nums.size();i++){
        if(nums[i] != nums[ind]){
            func(i, arr, nums, ans);
            return; // return to avoid further duplicates
        }
    }
    // ensure the function finsihes when no more unique elments are left
    func(nums.size(), arr, nums, ans);
}
vector<vector<int> > subsets(vector<int>& nums){
    vector<vector<int> > ans;
    vector<int> arr;
    sort(nums.begin(), nums.end()); // sort the array to handle duplicates
    func(0, arr, nums, ans);
    return ans;
}