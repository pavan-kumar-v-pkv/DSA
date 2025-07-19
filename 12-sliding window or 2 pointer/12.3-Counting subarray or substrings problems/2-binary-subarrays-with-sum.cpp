// Given a binary array nums and an integer goal. Return the number of non-empty
// subarrays with a sum goal.
// A subarray is a continuous part of the array.
#include<bits/stdc++.h>
using namespace std;

// Here, the idea is to use two-pointers approach to optimize the solution. 
// So, basically instead of finding the count of substrings which have sum 
// exactly equal to goal, try to find out count of subarrays whose sum is less 
// than or equal to goal and the count of subarrays whose sum is less than or 
// equal to goal-1. The difference of both the counts will provide the required 
// result in linear time.

// Time Complexity:O(2*2N), where N is the size of the string. The outer loop
// runs for N time and the inner while loop might be running for N time 
// throughout the program. So it becomes O(2N), also the helper function is 
// being called twice so overall time complexity is O(2*2N).
// Space Complexity: O(1). There is no extra space being used.
int numSubarraysWithSumLessEqualToGoal(vector<int>& nums, int goal){
    // if. goal is negative, there can't be any valid subarray sum
    if(goal < 0)
        return 0;

    int l = 0, r = 0;
    int sum = 0;
    int count = 0;

    while(r < nums.size()){
        sum += nums[r];

        while(sum > goal){
            sum -= nums[l];
            l++;
        }

        count += (r-l+1);
        r++;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal){
    return numSubarraysWithSumLessEqualToGoal(nums, goal) - numSubarraysWithSumLessEqualToGoal(nums, goal-1);
}



