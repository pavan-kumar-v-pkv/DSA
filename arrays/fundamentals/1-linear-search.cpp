// Given an array of integers nums and an integer target, 
// find the smallest index (0 based indexing) where the target appears in the array. 
// If the target is not found in the array, return -1

#include<bits/stdc++.h>
using namespace std;

// time complexity O(N) — The function iterates through the entire array once, where N is the number of elements in the array.
// space complexity O(1) — The function uses a constant amount of space for the variable ans and does not use any additional data structures that grow with the input size.
class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        //your code goes here
        int ans = -1;
        for(int i=0;i<nums.size();++i){
            if(nums[i] == target)
                return i;
        }
        return ans;
    }
};