// Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.
#include<bits/stdc++.h>
using namespace std;    

// time complexity O(N) where N is the length of the input array. The function iterates through the entire array once.
// space complexity O(K) for the temporary vector used to store the first k elements.
class Solution{
    public:
    void rotateArray(vector<int>& nums, int k){
        int n = nums.size();
        k = k % n; // handle cases where k is greater than n
        if(k == 0) return; // no rotation is needed

        // store the first k elements in a temporary vector
        vector<int> temp(nums.begin(), nums.begin() + k);
        // shift the remaining elements to the left
        for(int i = k; i < n; ++i){
            nums[i - k] = nums[i];
        }
        // copy the temporary vector back to the end of the original array
        for(int i = 0; i < k; ++i){
            nums[n - k + i] = temp[i];
        }   
    }
    // time complexity O(N) where N is the length of the input array. The function iterates through the entire array three times, each time taking O(N) time.
    // space complexity O(1) as it modifies the array in place without using any additional data structures that grow with the input size.
    void rotateArray2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // handle cases where k is greater than n
        if(k == 0) return; // no rotation is needed

        reverse(nums.begin(), nums.end()); // reverse the entire array
        reverse(nums.begin(), nums.begin() + n - k); // reverse the first n-k elements
        reverse(nums.begin() + n - k, nums.end()); // reverse the last k elements
    }
};
