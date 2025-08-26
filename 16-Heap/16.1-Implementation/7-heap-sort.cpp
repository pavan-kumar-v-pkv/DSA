// Given an array of integers nums, sort the array in non-decreasing order 
// using the heap sort algorithm. Sort the given array itself, there is no need
// to return anything.
// A sorted array in non-decreasing order is one in which each element is 
// either greater than or equal to all the elements to its left in the array.
#include<bits/stdc++.h>
using namespace std;

// Approach:

// 1.Rearrange the elements of the array and build a max-heap.
// 2.Start iterating with the whole array being unsorted initially.
// 3.Swap the element at index 0 (the largest) with the element at the last 
// position in the unsorted portion of the array. The largest element is now at
// the end, in its correct sorted position.
// 4.Reduce the size of unsorted portion of the array by one from the back 
// (since the very last element is now sorted).
// 5.Re-heapify from the top (index 0) downwards to restore the Max Heap 
// property for the remaining unsorted portion (the sorted portion of the array 
// must be kept undisturbed).

// time: O(N*logN)
// space: O(logN)
void heapifyDown(vector<int>& arr, int last, int ind){
    int largest = ind;
    int leftChildInd = 2*ind+1;
    int rightChildInd = 2*ind+2;

    if(leftChildInd <= last && arr[leftChildInd] > arr[largest])
        largest = leftChildInd;

    if(rightChildInd <= last && arr[rightChildInd] > arr[largest]) 
        largest = rightChildInd;

    if(largest != ind){
        swap(arr[largest], arr[ind]);
        heapifyDown(arr, last, largest);
    }
    return;
}
void buildMaxHeap(vector<int>& nums){
    int n = nums.size();

    for(int i=n/2-1;i>=0;i--){
        heapifyDown(nums, n-1, i);
    }
    return;
}
void heapSort(vector<int>& nums){
    // function call tp build a max-heap from the given array
    buildMaxHeap(nums);

    // to store the last index
    int last = nums.size()-1;

    // until there are elements left to sort in the array
    while(last > 0){
        // swap the greatest element to the currrent last index
        swap(nums[0], nums[last]);
        last--;

        if(last > 0){
            heapifyDown(nums, last, 0);
        }
    }
    return;
}