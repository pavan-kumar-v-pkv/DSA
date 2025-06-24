// Given a sorted array of nums consisting of distinct integers and a target
// value, return the index if the target is found. If not, return the index 
// where it would be if it were inserted in order.
#include <bits/stdc++.h>
using namespace std;

// using binary search to find the insert position
// using lower-bound algorithm
// time complexity: O(log n)
// space complexity: O(1)
int searchInsert(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = n; // default answer is n, if target is greater than all elements

    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1; // look for a smaller index on the left side
        }
        else{
            low = mid + 1; // look for a larger index on the right side
        }
    }
    return ans;
}