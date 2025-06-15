#include<bits/stdc++.h>
using namespace std;

// Approach: Bubble sort
// 1. Run a loop i from n-1 to 0;
// 2. Run a nested loop from j from 0 to i-1;
// 3. If the current element is greater than the next element, swap them.
// 4. Repeat until no swaps are made in a complete pass through the array.
// Time Complexity: O(N^2) where N is the length of the input array. The outer loop runs N times, and the inner loop runs up to N times in the worst case.
// Space Complexity: O(1) as it is an in-place sorting algorithm and does not require additional storage proportional to the input size.
class Solution { 
    public:
    vector<int> bubbleSort(vector<int>& nums){
        int n = nums.size();
        bool swapped;
        for(int i=n-1;i >= 0;i--){
            swapped=false;
            for(int j=0;j<=i-1;j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    swapped = true; // a swap was made
                }
            }
            if(!swapped) {
                break; // no swaps means the array is sorted
            }   
        }
        return nums;
    }
};