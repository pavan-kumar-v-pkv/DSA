// Given an integer array nums of size N, sorted in ascending order with distinct
//  values,and then rotated an unknown number of times (between 1 and N), find 
//  the minimum element in the array.
#include<bits/stdc++.h>
using namespace std;   

// brute force approach
// Time Complexity: O(N)
// Space Complexity: O(1)
int findMin(vector<int>& arr){
    int n = arr.size();
    int minElement = arr[0];
    for(int i=0;i<n;i++){
        minElement = min(minElement, arr[i]);
    }
    return minElement;
}

// binary search approach
// Time Complexity: O(log N)
// Space Complexity: O(1)
// approach:
// Initialize:
//   low = 0, high = n - 1
//  ans = Integer.MAX_VALUE
// Binary Search Loop (while low <= high):
//  Compute mid = low + (high - low) / 2
//  If left part (arr[low] to arr[mid]) is sorted:
//      Update ans = min(ans, arr[low])
//      Search right: low = mid + 1
//  Else (right part is sorted):
//      Update ans = min(ans, arr[mid])
//      Search left: high = mid - 1
// Return ans — it will hold the smallest element.
int findMin2(vector<int>& arr){
    int low = 0, high = arr.size()-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[high]){ // array is not rotated
            ans = min(ans, arr[low]);
            break; // exit the loop as we found the minimum
        }
        if(arr[low] <= arr[mid]){ // left part is sorted
            // keep the minimum of left part
            ans = min(ans, arr[low]);
            // eliminate the lest half
            low = mid + 1;
        }
        else{ // right part is sorted
            // keep the minimum of right part
            ans = min(ans, arr[mid]);
            // eliminate the right half
            high = mid - 1;
        }
    }
    return ans;
}