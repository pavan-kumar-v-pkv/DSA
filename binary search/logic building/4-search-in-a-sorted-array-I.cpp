// Given an integer array nums, sorted in ascending order (with distinct values) 
// and a target value k. The array is rotated at some pivot point that is unknown. 
// Find the index at which k is present and if k is not present return -1.
#include <bits/stdc++.h>
using namespace std;


// brute force approach
// time complexity: O(n)
// space complexity: O(1)
int searchInRotatedArrayBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == k) {
            return i; // return the index if k is found
        }
    }
    return -1; // return -1 if k is not found
}

// using binary search to find the index of k in the rotated sorted array
// time complexity: O(log n)
// space complexity: O(1)
int searchInRotatedArrayBinarySearch(vector<int>& nums, int k) {
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        // if mid point is the target
        if(nums[mid] == k)
            return mid;

        // if left half is sorted
        if(nums[low] <= nums[mid]){
            // check if k is in the left half
            if(nums[low] <= k && k <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1; // k is in the right half
            }
        }
        else{
            // if right half is sorted
            // check if k is in the right half
            if(nums[mid] <= k && k <= nums[high]){
                low = mid + 1; // k is in the right half
            }
            else{
                high = mid - 1; // k is in the left half
            }
        }
    }
    return -1; // return -1 if k is not found
}