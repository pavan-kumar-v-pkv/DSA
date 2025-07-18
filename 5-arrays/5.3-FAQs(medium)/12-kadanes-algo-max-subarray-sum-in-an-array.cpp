// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2), where N is the number of elements in the array
// space: O(1), no extra space is used
// This approach checks all possible subarrays and calculates their sums.
int maxSubarraySum(int arr[], int n){
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            // current subarray = arr[i...j]
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// optimal approach using Kadane's Algorithm
// the intuition of the algorithm is not to consider the subarray as a part of the answer if
// its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer
// and so this type of subarray is not considered.
long long maxSubarraySumKadane(int arr[], int n){
    long long maxi = LONG_MIN;
    long long sum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        // if sum < 0, reset it to 0
        if(sum < 0){
            sum = 0;
        }
    }
    // to consider the sum of the empty subarray
    // if(maxi < 0) {
    //     return 0;
    // }
    return maxi;
}

// follow-up question: We need to print the subarray with the maximum sum.
long long maxSubarraySum2(int arr[], int n){
    long long maxi = LONG_MIN;
    long long sum = 0;
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for(int i=0;i<n;i++){
        if(sum == 0) start = i; // reset start index when sum is 0
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    // printing the subarray
    cout<<"The subarray is: [";
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return maxi;
}