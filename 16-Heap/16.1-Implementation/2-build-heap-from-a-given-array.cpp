// Given an array of integers nums, convert it in-place into a min-heap.

// A binary min-heap is a complete binary tree where the key at the root is the
// minimum among all keys present in a binary min-heap and the same property is 
// recursively true for all nodes in a Binary Tree.
#include<bits/stdc++.h>
using namespace std;

// time: O(N)
// space: O(log2N)
void heapifyDown(vector<int>& nums, int ind){
    int smallest = ind;
    int leftChild_ind = 2*ind+1;
    int rightChild_ind = 2*ind+2;
    int n = nums.size();

    if(leftChild_ind < n && nums[leftChild_ind] < nums[smallest]){
        smallest = leftChild_ind;
    }
    if(rightChild_ind < n && nums[rightChild_ind] < nums[smallest]){
        smallest = rightChild_ind;
    }

    if(smallest != ind){
        swap(nums[smallest], nums[ind]);
        heapifyDown(nums, smallest);
    }
    return;
}
void buildMinHeap(vector<int>& nums){
    int n = nums.size();

    // iterate backwards on the non-leaf nodes
    for(int i=n/2-1;i>=0;i--){
        // heapify each node downwards
        heapifyDown(nums, i);
    }

    return;

}