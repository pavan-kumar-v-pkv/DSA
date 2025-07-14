// Given an array nums of length n, every integer in the array appears twice 
// except for two integers. Identify and return the two integers that appear 
// only once in the array. Return the two numbers in ascending order.
// For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not
// [5, 3].
#include <bits/stdc++.h>
using namespace std;    

// brute force approach
// time: O(N) where N is the size of the array
// space: O(N) for the Hash Map
vector<int> singleNumberIII(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int, int> mpp;

    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }

    for(auto it: mpp){
        if(it.second == 1){
            ans.push_back(it.first);
        }
    }
    sort(ans.begin(), ans.end()); // sort the result in ascending order
    return ans; // return the two unique numbers
}

// better approach using bit manipulation
// time: O(N), traversing the array twice results in O(2N) which is O(N).
// space: O(1) since we are using a single integer to store the result
vector<int> singleNumberIIIbetter(vector<int>& nums) {
    int n = nums.size();
    int xorr = 0;

    for(int i=0;i<n;i++){
        xorr ^= nums[i];
    }

    // variable to store the rightmost set bit
    int rightmostSetBit = (xorr & (xorr-1)) ^ xorr;
    // variables to store XOR of elements in bucket 1 and 2
    int bucket1 = 0, bucket2 = 0;
    // traverse the array again to separate the numbers into two buckets
    for(int i=0;i<n;i++){
        if(nums[i] & rightmostSetBit){
            bucket1 ^= nums[i]; // if the rightmost set bit is set, put it int bucket1
        }
        else{
            bucket2 ^= nums[i]; // if the rightmost set bit is not set, put it in bucket2
        }
    }
    if(bucket1 < bucket2){
        return {bucket1, bucket2}; // return the two unique numbers in ascending order
    }
    else{
        return {bucket2, bucket1}; // return the two unique numbers in ascending order
    }
}