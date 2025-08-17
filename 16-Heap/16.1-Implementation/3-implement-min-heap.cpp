// You need to implement the Min Heap with the following given methods.

// insert (x) -> insert value x to the min heap
// getMin -> Output the minimum value from min heap
// exctractMin -> Remove the minimum element from the heap
// heapSize -> return the current size of the heap
// isEmpty -> returns if heap is empty or not
// changeKey (ind, val) -> update the value at given index to val (index will 
//     be given 0-based indexing)
// initializeHeap -> Initialize the heap
#include<bits/stdc++.h>
using namespace std;

// Time Complexity:

// Insert(val): Inserting and Heapifying upwards contribute to O(logN) time.
// Get Minimum(): Constant time operation, i.e., O(1).
// Extract Minimum(): Involves Heapifying downwards contributing to O(logN) time.
// Heap Size(): Constant time operation, i.e., O(1).
// Is Empty(): Constant time operation, i.e., O(1).
// Change Key(ind, val): Involves heapifying which takes O(logN) time.

// Space Complexity: O(N), because of the array used to store the elements.

class Solution {
    private:
    vector<int> arr; // list to store the min-heap
    int count; // to store the count of element in min-heap

    void heapifyUp(vector<int>& arr, int ind){
        int parentInd = (ind-1)/2;

        // if the current index holds smaller values than the parent
        if(ind > 0 && arr[ind] < arr[parentInd]){
            swap(arr[ind], arr[parentInd]);

            // recursively heapify the upper nodes
            heapifyUp(arr, parentInd);
        }
        return;
    }

    void heapifyDown(vector<int>& arr, int ind){
        int n = arr.size();

        int smallestInd = ind;
        int leftChildInd = 2*ind+1;
        int rightChildInd = 2*ind+2;

        // if the left child holds smaller value, update the smallest index
        if(leftChildInd < n && arr[leftChildInd] < arr[smallestInd])
            smallestInd = leftChildInd;
        // if the right child holds smaller value, update the smallest index
        if(rightChildInd < n && arr[rightChildInd] < arr[smallestInd])
            smallestInd = rightChildInd;

        if(smallestInd != ind){
            swap(arr[smallestInd], arr[ind]);

            // recursively heapify the lower subtree
            heapifyDown(arr, smallestInd);
        }
        return;
    }

    public:
    void initializeHeap(){
        arr.clear();
        count = 0;
    }

    void insert(int key){
        arr.push_back(key);
        // heapify upwards
        heapifyUp(arr, count);
        count = count + 1;
        return;
    }

    // method to change the value at a given index in min-heap
    void changeKey(int index, int new_val){
        // if the cuurent value is replaced with smaller value
        if(arr[index] > new_val){
            arr[index] = new_val;
            heapifyUp(arr, index);
        }
        else{
            // else if the current values is replaced with a larger value
            arr[index] = new_val;
            heapifyDown(arr, index);
        }
        return;
    }

    void extractMin(){
        int ele = arr[0];
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        count = count - 1;

        heapifyDown(arr, 0);
    }

    bool isEmpty(){
        return (count == 0);
    }

    int getMin(){
        return arr[0];
    }

    int heapSize(){
        return count;
    }
};