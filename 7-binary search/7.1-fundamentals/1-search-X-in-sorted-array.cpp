// // Given a sorted array of integers nums with 0-based indexing, find the index of a 
// specified target integer. If the target is found in the array, return its index. 
// If the target is not found, return -1.

#include <bits/stdc++.h>
using namespace std;

int searchInSortedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To prevent overflow

        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}