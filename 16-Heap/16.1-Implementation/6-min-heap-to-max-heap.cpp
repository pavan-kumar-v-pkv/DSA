// Given a min-heap in array representation named nums, convert it into a 
// max-heap and return the resulting array.

// A min-heap is a complete binary tree where the key at the root is the 
// minimum among all keys present in a binary min-heap and the same property 
// is recursively true for all nodes in the Binary Tree.

// A max-heap is a complete binary tree where the key at the root is the 
// maximum among all keys present in a binary max-heap and the same property 
// is recursively true for all nodes in the Binary Tree.

// Since there can be multiple answers, the compiler will return true if 
// it's correct, else false.
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) (where N is the number of elements in the array)
// Each heapify call has a time complexity of O(h), where h is the height 
// of the subtree, h = log(N). The heapify operation is performed for 
// approximately N/2 non-leaf nodes.
// Due the variable height for all the subtrees, summing the total work done
// for all the nodes results in an overall time complexity of O(N) for 
// building a heap.

// Space Complexity: O(logN)
// The recursive calls during heapify require stack space proportional to the height of the heap which will be of the order of log(N) in the worst-case.
void heapifyDown(vector<int>& nums, int ind){
    int n = nums.size();

    int largestInd = ind;
    int leftChildInd = 2*ind+1;
    int rightChildInd = 2*ind+2;

    if(leftChildInd < n && nums[leftChildInd] > nums[largestInd])
        largestInd = leftChildInd;

    if(rightChildInd < n && nums[rightChildInd] > nums[largestInd])
        largestInd = rightChildInd;

    if(largestInd != ind){
        swap(nums[largestInd], nums[ind]);
        heapifyDown(nums, largestInd);
    }
    return;
}
vector<int> minToMaxHeap(vector<int> nums){
    int n = nums.size();

    // ierate backwards on the non-leaf nodes
    for(int i=n/2-1;i>=0;i--){
        //heapify each node downwards
        heapifyDown(nums, i);
    }
    return nums;
}