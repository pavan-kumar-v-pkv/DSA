// Given an array nums where each integer in nums appears thrice except one. 
// Find out the number that has appeared only once.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N) where N is the size of the array
// space: O(N) for the Hash Map
int singleNumberII(vector<int>& nums) {
    unordered_map<int, int> mpp;
    
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }

    for(auto it: mpp){
        if(it.second == 1){
            return it.first; // return the unique number
        }
    }

    return -1; // return -1 if no unique number is found
}

// better approach using bit manipulation
// time: O(32*N) for every 32-bit position, all the elements of the array are traversed
// space: O(1) since we are using a single integer to store the result
int singleNumberIIbetter1(vector<int>& nums) {
    // variable to store the size
    int n = nums.size();
    // variable to store the result
    int result = 0;

    // checking every bit position
    for(int bitIndex=0;bitIndex<32;bitIndex++){
        int cnt = 0; // variable to count the number of set bits at the current bit position
        for(int i=0;i<n;i++){
            // counting elements having set bits at bitIndex position
            if(nums[i] & (1<<bitIndex)){
                cnt++;
            }
        }

        // updating bits in answer
        if(cnt%3 != 0){
            result |= (1<<bitIndex);
        }
    }
    return result; // return the unique number
}

// optimal approach using grouping all identical elements
// which can be done by sorting the aray
// time: O(NlogN) for sorting the array
// space: O(1) since we are using a single integer to store the result
int singleNumberIIoptimal(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i=1;i<nums.size();i+=3){
        // checking the elements in the bucket
        if(nums[i] != nums[i-1]){
            return nums[i-1]; // return the unique number
        }
    }

    // if not found in the loop, return the last element
    return nums[n-1];
}