// Determine all possible set of k numbers that can be added together to equal 
// n while meeting the following requirements:
// There is only use of numerals 1 through 9.
// A single use is made of each number.
// Return list of every feasible combination that is allowed. The combinations 
// can be returned in any order, but the list cannot have the same combination 
// twice.
#include<bits/stdc++.h>
using namespace std;

// Function to find all unique combinations of k numbers that sum up to n
// time: O(2^9 * k) doe to the exploration of all subsets of the set {1, 2, ..., 9}
// space: O(k) for the recursion stack and storing the current combination
void func(int last, int sum, vector<int>& nums, int k, vector<vector<int> >& ans){
    // if the sum is 0 and the number of elements is k
    if(sum == 0 && nums.size() == k){
        ans.push_back(nums);
        return;
    }
    // if the sum is less than or equal to zero or the number of elements exceeds k
    if(sum <= 0 || nums.size() > k) return;

    // iterate from the last number to 9
    for(int i=last;i<=9;i++){
        // if the current number is less than or equal to the sum
        if(i <= sum){
            // add the number to the current combination
            nums.push_back(i);
            // recursively call the function with the next number and reduced sum
            func(i+1, sum-i, nums, k, ans);
            // backtrack: remove the last number from the current combination
            nums.pop_back();
        }
        else{
            // if the number is greater than the sum, break the loop]
            break;
        }
    }
}
vector<vector<int> >combinationSum3(int k, int n){
    vector<vector<int> > ans;
    vector<int> nums;
    func(1, n, nums, k, ans);
    return ans;
}