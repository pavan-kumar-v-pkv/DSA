// Given an array nums representing a min-heap and two integers ind and val, 
// set the value at index ind (0-based) to val and perform the heapify 
// algorithm such that the resulting array follows the min-heap property.

// Modify the original array in-place, no need to return anything.
#include<bits/stdc++.h>
using namespace std;

// time: O(log2N), where N is the number of elements of array, worst case heapify is full tree height
// space: O(log2N)

// function to recursively heapify the array downwards
void heapifyDown(vector<int>& nums, int ind){
    int n = nums.size();

    // index of the smallest element
    int smallest_ind = ind;

    // indices of left and right child
    int leftChild_ind = 2*ind+1, rightChild_ind = 2*ind+2;

    // if the left child holds smaller value, update the smallest index
    if(leftChild_ind < n && nums[leftChild_ind] < nums[smallest_ind]){
        smallest_ind = leftChild_ind;
    }
    // if the right child holds smallest value, update the smallest index
    if(rightChild_ind < n && nums[rightChild_ind] < nums[smallest_ind]){
        smallest_ind = rightChild_ind;
    }

    // if the smallest element index is updated
    if(smallest_ind != ind){
        //swap the smallest element with the current index
        swap(nums[smallest_ind], nums[ind]);
        // recursively heapify the lower subtree
        heapifyDown(nums, smallest_ind);
    }

    return;
}
// function to recursively heapify the array upwards
void heapifyUp(vector<int>& nums, int ind){
    int parent_ind = (ind-1)/2;

    // if the current index holds smaller vlaue than the parent
    if(ind > 0 && nums[ind] < nums[parent_ind]){
        // swap the values at the two indices
        swap(nums[ind], nums[parent_ind]);
        // recursively heapify the upper nodes
        heapifyUp(nums, parent_ind);
    }
    return;
}
// function to implement heapify algo for a min heap
void heapify(vector<int>& nums, int ind, int val){
    // if the current value is replaced with a smaller value
    if(nums[ind] > val){
        nums[ind] = val;
        heapifyUp(nums, ind);
    }
    // else if the current value is replaced with a larger value
    else{
        nums[ind] = val;
        heapifyDown(nums, ind);
    }
    return;
}