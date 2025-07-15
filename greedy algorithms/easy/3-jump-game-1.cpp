// Given an array of integers nums, each element in the array represents the 
// maximum jump length at that position. Initially starting at the first index 
// of the array, determine if it is possible to reach the last index. Return 
// true if the last index can be reached, otherwise return false.
#include<bits/stdc++.h>
using namespace std;

// time: O(N) where N is the length of the nums array
// space: O(1) since we are using a constant amount of extra space
bool canJump(vector<int>& jumps){
    int maxReachable = 0; // maximum index that can be reached
    int n = jumps.size();

    // iterate through each index in the jumps array
    for(int i=0;i<n;i++){
        // if the current index is greater then the maximum
        // reachable index, it means we cannot move forward and should return false
        if(i > maxReachable){
            return false;
        }
        // update the maximum reachable index
        maxReachable = max(maxReachable, i + jumps[i]);
        // if the maximum reachable index is greater than or equal to the last index,
        // we can reach the end of the array
        if(maxReachable >= n - 1){
            return true;
        }
    }
    return true; // if we finish the loop return true 
}