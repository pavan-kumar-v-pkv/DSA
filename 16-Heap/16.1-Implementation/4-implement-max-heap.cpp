// You need to implement the Max Heap with the following given methods.

// insert (x) -> insert value x to the max heap
// getMax -> Output the maximum value from the max heap
// exctractMax -> Remove the maximum element from the heap
// heapSize -> return the current size of the heap
// isEmpty -> returns if heap is empty or not
// changeKey (ind, val) -> update the value at given index to val (index will 
//     be given 0-based indexing)
// initializeHeap -> Initialize the heap
#include<bits/stdc++.h>
using namespace std;

// Time Complexity:

// Insert(val): Inserting and Heapifying upwards contribute to O(logN) time.
// Get Maximum(): Constant time operation, i.e., O(1).
// Extract Maximum(): Involves Heapifying downwards contributing to O(logN) time.
// Heap Size(): Constant time operation, i.e., O(1).
// Is Empty(): Constant time operation, i.e., O(1).
// Change Key(ind, val): Involves heapifying which takes O(logN) time.

// Space Complexity: O(N), because of the array used to store the elements.
class Solution{
    private:
    vector<int> arr;
    int count;

    void heapifyUp(int ind){
        int parentInd = (ind-1)/2;

        if(ind > 0 && arr[ind] > arr[parentInd]){
            swap(arr[ind], arr[parentInd]);
            heapifyUp(parentInd);
        }
        return;
    }

    void heapifyDown(int ind){
        int n = arr.size();
        int largest = ind;
        int leftChildInd = 2*ind+1;
        int rightChildInd = 2*ind+2;

        if(leftChildInd < n && arr[leftChildInd] > arr[largest])
            largest = leftChildInd;

        if(rightChildInd < n && arr[rightChildInd] > arr[largest])
            largest = rightChildInd;

        if(largest != ind){
            swap(arr[largest], arr[ind]);
            heapifyDown(largest);
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
        heapifyUp(count);
        count = count + 1;
        return;
    }

    void changeKey(int index, int new_val){
        if(arr[index] < new_val){
            arr[index] = new_val;
            heapifyUp(index);
        }
        else{
            arr[index] = new_val;
            heapifyDown(index);
        }
        return;
    }

    void extractMax(){
        int ele = arr[0];

        swap(arr[0], arr[count-1]);
        arr.pop_back();
        count = count - 1;
        heapifyDown(0);
    }
    bool isEmpty(){
        return count == 0;
    }
    int getMax(){
        return arr[0];
    }
    int heapSize(){
        return count;
    }
};
