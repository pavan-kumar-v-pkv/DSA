// Given an integer array nums of even length consisting of an equal number 
//of positive and negative integers.
//Return the answer array in such a way that the given conditions are met:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
#include <bits/stdc++.h>
using namespace std;    

class Solution {
    public:
    // time: O(N+N/2), where N is the size of the nums array.
    // space: O(N/2+N/2)=O(N), where N is the size of the nums array.
    vector<int> rearrangeArray(vector<int>& nums){
        int n = nums.size();
        vector<int> pos, neg;
        for(int i=0;i<n;i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        for(int i=0;i<n/2;i++){
            nums[2*i] = pos[i]; // Place positive integers at even indices
            nums[2*i+1] = neg[i]; // Place negative integers at odd indices
        }

        return nums;
    }
    // optimized version
    vector<int> rearrangeArray2(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;

        for(int i=0;i<n;i++){
            if(nums[i] < 0){
                // Place negative integers at odd indices
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};