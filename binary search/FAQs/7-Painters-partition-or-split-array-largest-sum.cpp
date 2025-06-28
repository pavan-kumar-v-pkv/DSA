// Given an integer array a of size n and an integer k. Split the array a into k
// non-empty subarrays such that the largest sum of any subarray is minimized. 
// Return the minimized largest sum of the split.

/// Painters Partition Problem or // Split Array Largest Sum Problem
// is similar to Book Allocation Problem.
#include <bits/stdc++.h>
using namespace std;    

// brute force approach
// time: O(n * (sum(arr) - max(arr))+1)
// space: O(1)
int cntPartitions(vector<int>& a, int maxSum){
    int n = a.size();
    int partitions = 1;
    long long sum = 0; // current sum of the subarray
    for(int i=0;i<n;i++){
        if(sum + a[i] <= maxSum){
            sum += a[i];
        }
        else{
            partitions++;
            sum = a[i];
        }
    }
    return partitions;
}
int largestSubarraySumMinimised(vector<int>& a, int k){
    int low = *max_element(a.begin(), a.end()); // minimum possible largest sum
    int high = accumulate(a.begin(), a.end(), 0); // maximum possible largest sum

    for(int maxSum = low;maxSum<=high;maxSum++){
        if(cntPartitions(a, maxSum) == k)
            return maxSum;
    }
    return low; // if no partition is possible
}

// better approach: binary search
// time: O(n * log(sum(arr) - max(arr)))
// space: O(1)
int cntPartitions2(vector<int>& a, int maxSum){
    int n = a.size();
    int partitions = 1;
    long long sum = 0; // current sum of the subarray
    for(int i=0;i<n;i++){
        if(sum + a[i] <= maxSum){
            sum += a[i];
        }
        else{
            partitions++;
            sum = a[i];
        }
    }
    return partitions;
}
int largestSubarraySumMinimised2(vector<int>& a, int k){
    int low = *max_element(a.begin(), a.end()); // minimum possible largest sum
    int high = accumulate(a.begin(), a.end(), 0); // maximum possible largest sum   
    int ans = -1; // to store the answer
    while(low <= high){
        int mid = low + (high - low) / 2; // mid is the largest sum of the subarray
        if(cntPartitions2(a, mid) <= k){
            ans = mid;
            high = mid-1; // try to minimize the largest sum
        }
        else{
            low = mid + 1; // increase the largest sum
        }
    }
    return ans;
}
