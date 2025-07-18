// Given an array of nums of n integers. Every integer in the array appears 
// twice except one integer. Find the number that appeared once in the array.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N) where N is the size of the array
// traversing the array to update the Hash Map - O(N)
// traversing the Hash Map to find the unique number - O(N)
// space: O(N) for the Hash Map
int singleNumber(vector<int>& nums){
    unordered_map<int, int> mpp;

    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }

    for(auto it: mpp){
        // if frequency is
        if(it.second == 1){
            return it.first; // return the unique number
        }
    }

    return -1; // return -1 if no unique number is found
}

// optimized approach using bit manipulation
// time: O(N) where N is the size of the array
// space: O(1) since we are using a single integer to store the result
int singleNumberOptimized(vector<int>& nums){
    int result = 0;

    for(int i=0;i<nums.size();i++){
        result ^= nums[i]; // XOR operation
    }

    return result; // return the unique number
}