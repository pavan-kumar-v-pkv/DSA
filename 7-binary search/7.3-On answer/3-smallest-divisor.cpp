// Given an array of integers nums and an integer limit as the threshold value,
// find the smallest positive integer divisor such that upon dividing all the 
// elements of the array by this divisor, the sum of the division results is less
// than or equal to the threshold value.

// Each result of the division is rounded up to the nearest integer greater
// than or equal to that element.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(max(arr[]) * n)
// space: O(1)
int smallestDivisor(vector<int>& arr, int limit){
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());

    // find the smallest divisor
    for(int d=1;d<=maxi;d++){
        // find the summation result
        long long sum = 0;
        for(int i=0;i<n;i++)
            sum += ceil((double)arr[i] / (double)d);
        if(sum <= limit)
            return d;
    }
    return -1;
}

// binary search approach
// time: O(n * log(max(arr[])))
// space: O(1)
int sumByD(vector<int>& arr, int div){
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += ceil((double)arr[i] / (double)div);
    }
    return sum;
}
int smallestDivisor2(vector<int>& arr, int limit){
    int n = arr.size();
    if (n > limit) 
        return -1; // if limit is less than n, no divisor can satisfy the condition
    int low = 1, high = *max_element(arr.begin(), arr.end());
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(sumByD(arr, mid) <= limit){
            ans = mid;
            high = mid - 1; // search in the left half
        }
        else{
            low = mid + 1; // search in the right half
        }
    }
    return ans; // return the smallest divisor found
}