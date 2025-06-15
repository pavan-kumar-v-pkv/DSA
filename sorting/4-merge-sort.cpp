#include<bits/stdc++.h>
using namespace std;

// Approach: merge sort
// 1. Divide the array into two halves until each half contains a single element.
// 2. Merge the two halves back together in sorted order.
// Time Complexity: O(N log N): At each step, we divide the whole array, which takes O(log N) time, and merging two halves takes O(N) time.
// Space Complexity: O(N): We use additional space for the temporary arrays during the merge process.
class Solution {
    public:
    void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }
    }
    void mergeSortHelper(vector<int> &nums, int low, int high) {
        if(low >= high)
            return;
        int mid = low + (high - low)/2;
        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> mergeSort(vector<int>& nums){
        int n = nums.size();
        mergeSortHelper(nums, 0, n-1);
        return nums;
    }

};