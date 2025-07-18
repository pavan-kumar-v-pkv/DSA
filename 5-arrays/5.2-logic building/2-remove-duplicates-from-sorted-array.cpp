#include<bits/stdc++.h>
using namespace std;
// Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once. Return the number of unique elements in the array.
// If the number of unique elements be k, then,
// Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
// The remaining elements, as well as the size of the array does not matter in terms of correctness.
// An array sorted in non-decreasing order is an array where every element to the right of an element is either equal to or greater in value than that element.

class Solution {
    // Time Complexity: O(N * log N) + O(N), for using hashset, it will take O(N * log N) and also to traverse the array once O(N). Here N is the size of the array.
    // Space Complexity: O(N) because in the worst case, all the elements of the array can be unique and it will take O(N) space. Here N represents the size of the array.
    int removeDuplicates(vector<int>& nums){
        set<int> s;
        for(int val: nums){
            s.insert(val);
        }
        int k = s.size();
        int j = 0;
        // copy unique elements back to the original array
        for(int val: s){
            nums[j++] = val;
        }
        return k;
    }

    // optimal approach
    // Time Complexity: O(N), where N is the size of the array. The function iterates through the array once.
    // Space Complexity: O(1), as it modifies the array in place without using any additional data structures that grow with the input size.
    int removeDuplicates2(vector<int>& nums){
        if(nums.empty()) return 0; // handle empty array case
        int i = 0; // count of unique elements
        for(int j=1;j<nums.size();j++){
            // if the current element is different from the last unique element
            if(nums[i] != nums[j]){
                // move to the next position in the vector for the unique element
                i++;
                // update the value at the new position with the current element
                nums[i] = nums[j];
            }
        }
        // return the count of unique elements
        return i + 1; // i is the index of the last unique element, so we add 1 to get the count
    }
};