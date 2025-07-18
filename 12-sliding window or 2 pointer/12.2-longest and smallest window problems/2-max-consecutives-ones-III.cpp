// Given a binary array nums and an integer k, flip at most k 0's.
// Return the maximum number of consecutive 1's after performing the flipping 
// operation.

// Also can be said as: longest subarray with at most k 0's.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2) where N is the length of the array
// space: O(1) for constant space usage
int longestOnes(vector<int>& nums, int k){
    int n = nums.size();
    int maxLen = 0;
    int zeros = 0; // count of zeros in the current window
    for(int i=0;i<n;i++){
        zeros = 0; // reset zeros count for each starting point
        for(int j=i;j<n;j++){
            if(nums[j] == 0) zeros++; // count zeros in the current window
            if(zeros > k) break; // if zeros exceed k, break the loop
            maxLen = max(maxLen, j-i+1); // update maximum length
        }
    }
    return maxLen;
}

// better approach using sliding window technique
// time: O(2N) where N is the length of the array
// space: O(1) for constant space usage
int longestOnes2(vector<int>& nums, int k){
    int n = nums.size();
    int l=0, r=0;
    int zeros = 0; // count of zeros in the current window
    int maxLen = 0;

    while(r < n){
        if(nums[r] == 0)
            zeros++; // increment zeros count if current element is 0
        while(zeros > k){ // if zeros exceed k, move the left pointer
            if(nums[l] == 0)
                zeros--;
            l++;
        }
        maxLen = max(maxLen, r-l+1); // update maximum length
        r++;
    }
    return maxLen; // return the maximum length found
}

// optimal approach using sliding window technique with two pointers
// time: O(N) where N is the length of the array
// space: O(1) for constant space usage
int longestOnes3(vector<int>& nums, int k){
    int n = nums.size();
    int l = 0, r = 0;
    int zeros = 0;
    int maxlen = 0;

    while(r < n){
        if(nums[r] == 0){
            zeros++; // increment zeros count if current element is 0
        }
        if(zeros > k){
            if(nums[l] == 0){
                zeros--;
            }
            l++; // move the left pointer to reduce zeros count
        }
        maxlen = max(maxlen, l-r+1);
        r++;
    }
    return maxlen; // return the maximum length found
}