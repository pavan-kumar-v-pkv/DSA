// Given an array nums and an integer k. An array is called nice if and only if 
// it contains k odd numbers. Find the number of nice subarrays in the given 
// array nums.
// A subarray is continuous part of the array.
#include<bits/stdc++.h>
using namespace std;

// Here, the idea is to use two-pointers approach to optimize the solution. 
// As, this problem is a slight variation of the problem of finding count of 
// subarrays with given sum in binary array, the thought process would be very 
// similar. Take the modulo 2 of the elements and if the element is even it will
// become 0 , else it will become 1, thus the array would be converted into a 
// binary subarray. So, basically instead of finding the count of substrings 
// which have exactly k odd elements, try to find out count of subarrays where 
// the number of odd elements is less than or equal to k and the count of 
// subarrays with odd elements less than or equal to goal-1. The difference of 
// both the counts will provide the required result in linear time.

// Time Complexity:O(2*2N), where N is the size of the string. The outer loop runs for N time and the inner while loop might be running for N time throughout the program. So it becomes O(2N), also the helper function is being called twice so overall time complexity is O(2*2N).

// Space Complexity: O(1). There is no extra space being used.

int helper(vector<int>& nums, int goal){
    if(goal < 0) return 0;
    int l = 0, r = 0;
    int count = 0;
    int sum = 0;

    while(r < nums.size()){
        sum += (nums[r] % 2);

        while(sum > goal){
            sum -= nums[l] % 2;
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}
int numberOfOddSubarrays(vector<int>& nums, int k){
    return helper(nums, k) - helper(nums, k-1);
}





