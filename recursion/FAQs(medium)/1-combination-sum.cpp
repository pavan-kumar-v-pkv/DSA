// Provided with a goal integer target and an array of unique integer candidates,
// provide a list of all possible combinations of candidates in which the 
// selected numbers add up to the target. The combinations can be returned in 
// any order.
// A candidate may be selected from the pool an infinite number of times. There
// are two distinct combinations if the frequency of at least one of the 
// selected figures differs.
// The test cases are created so that, for the given input, there are fewer 
// than 150 possible combinations that add up to the target.
// If there is no possible subsequences then return empty vector.
#include<bits/stdc++.h>
using namespace std;

// Function to find all combinations that sum up to the target  
// time: O(2^n) in the worst case, where n is the number of candidates
// space: O(n) for the recursion stack
void func(vector<int>& candidates, int index, int sum, vector<int>& v2, vector<vector<int> >& ans){
    // base case: if sum is zero, ad current subsequence to the result
    if(sum == 0){
        ans.push_back(v2);
        return;
    }
    // base case: if the sum becomes negative or index is out of bounds, return
    if(sum < 0 || index < 0) return;

    // include the current candidate in the combination
    v2.push_back(candidates[index]);
    // recursively call the function with the same index (to allow infinite selection)
    func(candidates, index, sum - candidates[index], v2, ans);
    // backtrack: remove the last added candidate
    v2.pop_back();

    // exclude the current candidate from the combination
    func(candidates, index - 1, sum, v2, ans);
    // no need to backtrack here as we are already at the next index
}
vector<vector<int> > cominationSum(vector<int>& candidates, int target){
    vector<vector<int> > ans;
    vector<int> v;

    func(candidates, candidates.size()-1, target, v, ans);
    return ans;
}