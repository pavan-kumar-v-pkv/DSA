// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integers.
// More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted order.
// If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).
// You must rearrange the numbers in-place and use only constant extra memory.

#include <bits/stdc++.h>
using namespace std;

// using cpp built-in function next_permutation
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

// optimal approach
// Approach

// * Start from the end of the array.
// * Find the first index where a smaller number is followed by a larger one.
// * If no such index is found, the array is the last permutation.
// * In that case, reverse the entire array and return.
// * Otherwise, find the first number from the end that is greater than the number at the found index.
// * Swap these two numbers.
// * Reverse the subarray after the swapped index.
// * This gives the next lexicographically greater permutation.
vector<int>  nextGreaterPermutation(vector<int>& nums){
    int n = nums.size();

    // step 1: Find the break point
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }
    // if break point does not exist, reverse the array
    if(ind == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    }
    // step 2: Find the next greater element and swap it with arr[ind]
    for(int i=n-1;i>ind;i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }
    // step 3: reverse the right half
    reverse(nums.begin()+ind+1, nums.end());
    return nums;
}


