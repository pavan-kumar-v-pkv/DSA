// Given an array arr of integers. A peak element is defined as an element 
// greater than both of its neighbors. Formally, if arr[i] is the peak element,
// arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based) of a 
// peak element in the array. If there are multiple peak numbers, return the 
// index of any peak number.

// Note: As there can be many peak values, 1 is given as output if the returned
// index is a peak number, otherwise 0.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n)
// space: O(1)
int findPeakElement(vector<int>& arr){
    int n = arr.size();
    if(n == 1) return 0; // if there is only one element, it is the peak
    if(arr[0] > arr[1]) return 0; // first element is a peak
    if(arr[n-1] > arr[n-2]) return n-1; // last element is a peak
    for(int i=1;i<=n-2;i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            return i; // return the index of the peak element
    }
    return -1; // no peak element found
}

// binary search approach
// time: O(log n)
// space: O(1)
int findPeakElement2(vector<int>& arr){
    int n = arr.size();
    // edge cases
    if(n == 1) return 0; // if there is only one element, it is the peak
    if(arr[0] > arr[1]) return 0; // first element is a peak
    if(arr[n-1] > arr[n-2]) return n-1; // last element is a peak   
    int low = 1, high = n - 2; // search in the range [1, n-2]
    while(low <= high){
        int mid = low + (high - low) / 2; // find the middle index
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid; // return the index of the peak element
        }
        else if(arr[mid] < arr[mid-1]){
            high = mid - 1; // search in the left half
        }
        else{

            low = mid + 1; // search in the right half
        }
    }
    return -1; // no peak element found
}