// Given an integer array nums, sorted in ascending order (may contain duplicate
// values) and a target value k. Now the array is rotated at some pivot point 
// unknown to you. Return True if k is present and otherwise, return False.
#include <bits/stdc++.h>
using namespace std;

bool searchInRotatedArray(vector<int>& nums, int k) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == k) return true;
        // edge case: if low, mid, and high are equal, we cannot determine the sorted half
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue; // skip the duplicates
        }
        // If left half is sorted
        if (nums[low] < nums[mid]) {
            // Check if k is in the left half
            if (nums[low] <= k && k < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // If right half is sorted
        else if (nums[low] > nums[mid]) {
            // Check if k is in the right half
            if (nums[mid] < k && k <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
    }
    return false;
}
