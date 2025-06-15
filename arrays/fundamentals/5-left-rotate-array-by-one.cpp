// Given an integer array nums, rotate the array to the left by one.
// Note: There is no need to return anything, just modify the given array.

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) where N is the length of the input array. The function iterates through the entire array once.
// Space Complexity: O(1) as it uses a constant amount of space for the variable firstElement and does not use any additional data structures that grow with the input size.
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int firstElement = nums[0];
        for(int i=1;i<nums.size();++i){
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = firstElement;
    }
};
