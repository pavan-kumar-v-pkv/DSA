// Given collection of candidate numbers (candidates) and a integer target.Find
// all unique combinations in candidates where the sum is equal to the target.
// There can only be one usage of each number in the candidates combination and
// return the answer in sorted order.
// e.g : The combination [1, 1, 2] and [1, 2, 1] are not unique.
#include<bits/stdc++.h>
using namespace std;

// Function to find all unique combinations that sum up to the target
// time: O(2^n * n) in the worst case, where n is the number
// space: O(n) for the recursion stack
void func(int ind, int sum, vector<int>& v2, vector<int>& candidates, vector<vector<int> >& ans){
    // base case: if sum is 0, 
    if(sum == 0){
        ans.push_back(v2);
        return;
    }
    if(sum < 0 || ind == candidates.size())
        return ;

    // include the current candidate in the combination
    v2.push_back(candidates[ind]);
    func(ind+1, sum-candidates[ind], v2, candidates, ans);
    v2.pop_back(); // backtrack

    // skip duplicates
    for(int i=ind+1;i<candidates.size();i++){
        if(candidates[i] != candidates[ind]){
            func(i, sum, v2, candidates, ans);
            break;
        }
    }
}
vector<vector<int> > combinationSum2(vector<int>& candidates, int target){
    vector<vector<int> > ans;
    vector<int> v2;
    sort(candidates.begin(), candidates.end());

    func(0, target, v2, candidates, ans);
    return ans;
}