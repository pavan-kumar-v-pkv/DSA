// Given an array of integers nums of unique elements. Return all possible 
// subsets (power set) of the array.
// Do not include the duplicates in the answer.
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > powerSet(vector<int>& nums){
    int n = nums.size();
    vector<vector<int> > result;
    /// variable to store the count of total subsets
    int totalSubsets = 1<<n; // 2^n subsets

    for(int val=0;val<totalSubsets;val++){
        vector<int> subset;
        // traverse on n bits
        for(int i=0;i<n;i++){
            if(val & (1<<i)){
                subset.push_back(nums[i]);
            }
        }

        result.push_back(subset); // add the subset to the result
    }
    return result;
}