// Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2), where N is the number of elements in the array
// space: O(1), no extra space is used
int maxProductSubArray(vector<int>& nums){
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++){
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++){
            result = max(result, p);
            p *= nums[j];
        }
        result = max(result, p);
    }
    return result;
}

// optimal appraoch
// time: O(N), where N is the number of elements in the array
// space: O(1), no extra space is used
// Goal: Find the contiguous subarray with the maximum product.
// Key Insights:
// Product of an even number of negatives is positive.
// Product of an odd number of negatives is negative.
// Zero resets the product, so we restart from the next element.
// Strategy:
// Traverse the array from both directions (left to right and right to left) in a single loop.
// Maintain:
// prefixProduct for the left-to-right traversal.
// suffixProduct for the right-to-left traversal.
// maxProduct to keep track of the maximum product seen so far.
// If prefixProduct or suffixProduct becomes zero (due to a 0 in the array), reset it to 1 to start fresh.
// At each step, update maxProduct with the maximum of current prefix, suffix, and previous max.
// Result: Return maxProduct after the full traversal.
int maxProductSubArray2(vector<int>& arr){
    int n = arr.size();
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n-i-1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}
