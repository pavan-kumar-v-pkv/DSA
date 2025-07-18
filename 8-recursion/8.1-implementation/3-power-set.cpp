// Given an array of integers nums of unique elements. Return all possible 
// subsets (power set) of the array.
// Do not include the duplicates in the answer.
#include<bits/stdc++.h>
using namespace std;

// Function to generate the power set of a given set
// time: O(2^n)
// space: O(n * 2^n) for storing the result
// The recursion stack space is O(n) in the worst case.
void func(int index, int n, vector<int>& nums, vector<int>& currentSet, vector<vector<int> >& ans){
    // base case: if the index is equal to the size of the input set, add the current set to the result
    if(index == n){
        ans.push_back(currentSet);
        return;
    }
    // include the current element in the current set
    currentSet.push_back(nums[index]);
    func(index+1, n, nums, currentSet, ans);
    // backtrack: remove the last element from the current set
    currentSet.pop_back();

    // exclude the current element from the current set
    func(index+1, n, nums, currentSet, ans);
    // no need to backtrack here as we are already at the next index
}
vector<vector<int> > powerSet(vector<int>& nums){
    vector<vector<int> > ans;
    vector<int> currentSet;
    func(0, nums.size(), nums, currentSet, ans);
    return ans;
}