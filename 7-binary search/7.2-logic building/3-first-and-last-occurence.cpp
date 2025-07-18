// Given an array of integers nums sorted in non-decreasing order, 
// find the starting and ending position of a given target value. 
// If the target is not found in the array, return [-1, -1].
#include <bits/stdc++.h>
using namespace std;    

// brute force approach
// time complexity: O(n)
// space complexity: O(1)
vector<int> searchRangeBruteForce(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans(2, -1); // default answer is [-1, -1]
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            if (ans[0] == -1) {
                ans[0] = i; // first occurrence
            }
            ans[1] = i; // last occurrence
        }
    }
    return ans;
}

// using lower bound and upper bound algorithms
// time complexity: O(log n)
// space complexity: O(1)
// for the first occurence, we can use the lower bound algorithm
// for the last occurence, we can use the upper bound algorithm, 
// where it will point to the first element greater than the target and we can subtract 1 to get the last occurrence
int lowerBound(vector<int>& nums, int x){
    int low = 0, high = nums.size() - 1;
    int ans = nums.size(); // default answer is size of the array
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1; // search in the left half
        }else{
            low = mid + 1; // search in the right half
        }
    }
    return ans; // return the index of the lower bound
}

int upperBound(vector<int>& nums, int x){
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target){
    int first = lowerBound(nums, target);
    int last = upperBound(nums, target) - 1; // subtract 1 to get the last occurence
    if(first == nums.size() || nums[first] != target){
        vector<int> temp;
        temp.push_back(-1);
        temp.push_back(-1);
        return temp; // target not found
    }
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}
