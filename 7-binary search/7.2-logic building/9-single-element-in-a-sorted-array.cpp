// Given an array nums sorted in non-decreasing order. Every number in the array
// except one appears twice. Find the single number in the array.

#include <bits/stdc++.h>
using namespace std;

// brute force approach
// Time Complexity: O(N)
// Space Complexity: O(1)
int singleNonSuplicate(vector<int>& arr){
    int n = arr.size();
    if(n == 1) return arr[0];

    for(int i=0;i<n;i++){
        // check out first index
        if(i == 0){
            if(arr[i] != arr[i+1])
                return arr[i];
        }
        // check out last index:
        else if(i == n-1){
            if(arr[i] != arr[i-1])
                return arr[i];
        }
        else{
            if(arr[i] != arr[i-1] && arr[i] != arr[i+1])
                return arr[i];
        }
    }
    return -1;
}

// brute force approach using XOR
// Time Complexity: O(N)
// Space Complexity: O(1)
int singleNonDuplicate2(vector<int>& arr){
    int n = arr.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

// binary search approach
// If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
// If arr[0] != arr[1]: This means the very first element of the array is the single element. So, we will return arr[0].
// If arr[n-1] != arr[n-2]: This means the last element of the array is the single element. So, we will return arr[n-1].
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers excluding index 0 and n-1 like this: low will point to index 1, and high will point to index n-2 i.e. the second last index.
// Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
//      mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Check if arr[mid] is the single element:
// If arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the single element. We will return arr[mid].
// If (mid % 2 == 0 and arr[mid] == arr[mid+1])
//      or (mid%2 == 1 and arr[mid] == arr[mid-1]): This means we are in the left half and we should eliminate it as our single element appears on the right. So, we will do this:
//      low = mid+1.
// Otherwise, we are in the right half and we should eliminate it as our single element appears on the left. So, we will do this: high = mid-1;
// time: O(log N)
// space: O(1)
int singleNonDuplicate3(vector<int>& arr){
    int n = arr.size();
    // edge cases
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low)/2;
        // if arr[mid] is the single element
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1])
            return arr[mid];

        // we are in the left half:
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])){
            // eliminate the left half:
            low = mid + 1;
        }
        else{
            // we are in the right half
            high = mid - 1;
        }
    }
    return -1; // this line should never be reached if the input is valid
}

