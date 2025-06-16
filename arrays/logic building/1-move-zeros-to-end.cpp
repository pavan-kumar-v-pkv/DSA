#include<bits/stdc++.h>
using namespace std;
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note: You must do this in-place without making a copy of the array.

class Solution {
    public:
    // Brute force approach
    // time complexity O(N) where N is the length of the input array. The function iterates through the entire array once.
    // space complexity O(N) for the temporary vector used to store non-zero elements.
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        // copy all non-zero elements to temp
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                temp.push_back(nums[i]);
        }
        // count number of zeros in the original array
        int cnt = nums.size() - temp.size();
        for(int i=0;i<temp.size();i++){
            nums[i] = temp[i];
        }
        // fill the remaining elements with zeros
        for(int i=0;i<cnt;i++){
            nums[temp.size()+i] = 0;
        }
    }
    // optimal approach
    // time complexity O(N) where N is the length of the input array. The function iterates through the entire array once.
    // space complexity O(1) as it modifies the array in place without using any additional data structures that grow with the input size.
    void moveZeroes2(vector<int>& nums){
        int j = -1;
        int n = nums.size();

        // find the first zero element
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        // if no zero element is found, return
        if(j == -1) return;
        // iterate through the array
        for(int i=j+1;i<n;i++){
            // if the current element is non-zero, swap it with the first zero element found
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++; // move the index of the first zero element to the right
            }
        }
    }
};