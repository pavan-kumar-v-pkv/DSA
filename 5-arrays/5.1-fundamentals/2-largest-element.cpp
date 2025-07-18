// Given an array of integers nums, return the value of the largest element in the array
#include<bits/stdc++.h>
using namespace std;    

// time complexity O(N) — The function iterates through the entire array once, where N is the number of elements in the array.
// space complexity O(1) — The function uses a constant amount of space for the variable maxElement and does not use any additional data structures that grow with the input size.
class Solution {
public:
    int largestElement(vector<int>& nums) {
        return *max_element(nums.begin(), nums.end());
    }
    int largestElement2(vector<int>& nums) {
        int maxi = nums[0];
        for(int i=1;i<nums.size();i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
};
