#include<bits/stdc++.h>
using namespace std;

// Approach: Insertion Sort
// 1. Start from the second element and compare it with the elements before it.
// 2. If the current element is smaller than the previous elements, shift the larger elements to the right.
// 3. Insert the current element at its correct position.
// Time Complexity: O(N^2) where N is the length of the input array. The outer loop runs N times, and the inner loop can run up to N times in the worst case.
// Space Complexity: O(1) as it is an in-place sorting algorithm and does not require additional storage proportional to the input size.
class Solution { 
    public:
    vector<int> insertionSort(vector<int>& nums){
        int n = nums.size();

        for(int i=1;i<n;i++){
            int key = nums[i]; // current element to be inserted
            int j = i-1;

            // shift the elements of nums[0..i-1], that are greater than key, to one position ahead of their current position
            while(j >= 0 && nums[j] > key){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key; // insert the current element at its correct position
        }
        return nums;
    }
};