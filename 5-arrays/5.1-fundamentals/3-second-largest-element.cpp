// Given an array of integers nums, return the second-largest element in the array. 
// If the second-largest element does not exist, return -1.
#include<bits/stdc++.h>
using namespace std;    

// time complexity O(N) — The function iterates through the entire array once, where N is the number of elements in the array.
// space complexity O(1) — The function uses a constant amount of space for the variables maxi and secmax and does not use any additional data structures that grow with the input size.
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if(nums.size() < 2)
            return -1;

        int maxi = INT_MIN; int secmax = INT_MIN;

        for(int i=0;i<nums.size();++i){
            if(nums[i] > maxi){
                secmax = maxi;
                maxi = nums[i];
            }
            else if(nums[i] < maxi && nums[i] > secmax){
                secmax = nums[i];
            }
        }
        return secmax == INT_MIN ? -1 : secmax;
    }
};