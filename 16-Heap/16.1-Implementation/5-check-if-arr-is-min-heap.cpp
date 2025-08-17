// Given an array of integers nums. Check whether the array represents a 
// binary min-heap or not. Return true if it does, otherwise return false.
// A binary min-heap is a complete binary tree where the key at the root is the
//  minimum among all keys present in a binary min-heap and the same property 
//  is recursively true for all nodes in a Binary Tree.

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) (where N represents the number of elements in the array)
// Iterating on all the non-leaf nodes will take N/2 iterations which is of the order of O(N) (Constant factors like 1/2 are ignored while following the Big-O notation).

// Space Complexity: O(1), as there is no extra space used.
bool isMinHeap(vector<int>& nums){
    int n = nums.size();

    // iterate on the non-leaf nodes from the back
    for(int i=n/2-1;i>=0;i--){
        int leftChildInd = 2*i+1;
        int rightChildInd = 2*i+2;

        // if left child has a smaller value than the parent
        if(leftChildInd < n && nums[leftChildInd] < nums[i])
            return false;

        if(rightChildInd < n && nums[rightChildInd] < nums[i])
            return false;
    }
    return true;;
}
