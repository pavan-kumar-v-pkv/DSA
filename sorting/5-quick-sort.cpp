#include<bits/stdc++.h>
using namespace std;

// Approach: quick sort
// 1. Choose a pivot element from the array.   
// 2. Partition the array into two halves: elements less than the pivot and elements greater than the pivot.
// 3. Recursively apply the same logic to the left and right halves of the array.
// Time Complexity: O(N log N) on average, O(N^2) in the worst case (when the pivot is the smallest or largest element repeatedly).
// Space Complexity: O(log N) for the recursion stack in the average case, O(N) in the worst case due to the depth of recursion.
class Solution{
    public:
    int partition(vector<int> &nums, int low, int high) {
        int pivot = nums[low];
        int i = low;
        int j = high;

        while(i < j){
            while(nums[i] <= pivot &&i <= high-1){
                i++;
            }
            while(nums[j] > pivot && j >= low+1){
                j--;
            }
            if(i<j)
                swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    void quickSortHelper(vector<int> &nums, int low, int high) {
        if(low >= high)
            return;

        int pIndex = partition(nums, low, high);
        quickSortHelper(nums, low, pIndex-1);
        quickSortHelper(nums, pIndex+1, high);
    }
    vector<int> quickSort(vector<int>& nums){
        int n = nums.size();
        quickSortHelper(nums, 0, n-1);
        return nums;
    }

};