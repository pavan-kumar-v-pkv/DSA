#include<bits/stdc++.h>
using namespace std;

// Approach:
// 1. Select the starting index of the unsorted array.
// 2. Find the minimum element in the unsorted array.
// 3. Swap the minimum element with the first element of the unsorted array.
// 4. Move the starting index to the next element.
// 5. Repeat steps 2-4 until the entire array is sorted.

// Time Complexity: O(N2) where N is the length of the input array. The outer loop runs through each element, and the inner loop finds the smallest element in the unsorted portion of the array.
// Space Complexity: O(1) as it is an in-place sorting algorithm and does not require additional storage proportional to the input size.

class Solution {
    public:
    vector<int> selectionSort(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++){
            int minIndex = i; // assume the current index is the smallest
            // find the index of the minimum element in the unsorted part of the array
            for(int j=i+1;j<nums.size();j++){
                if(nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            // swap only if minIndex is changed
            if(minIndex != i){
                swap(nums[i], nums[minIndex]);
            }
        }
        return nums;
    }
};