// Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.
// Merge both the arrays into a single array sorted in non-decreasing order.
// The final sorted array should be stored inside the array nums1 and it should be done in-place.
// nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.
// nums2 has a length of n.
#include <bits/stdc++.h>
using namespace std;    

// brute force approach
// time: O(n+m) + O(n+m) where n and m are the sizes of the given arrays.
// space: O(n+m), where n and m are the sizes of the given arrays
void merge(long long arr1[], long long arr2[], int n, int m){
    long long arr3[n+m];
    int left = 0, right = 0, index = 0;

    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            left++;
            right++;
        }
        else{
            arr3[index] = arr2[right];
            right++;
            index++;
        }
    }
    while(left < n){
        arr3[index] = arr1[left];
        left++;
        index++;
    }
    while(right < m){
        arr3[index] = arr2[right];
        right++;
        index++;
    }
    for(int i=0;i<n+m;i++){
        if(i < n)
            arr1[i] = arr3[i];
        else
            arr2[i-n] = arr3[i];
    }
}

// optimal approach
// time: O(min(n, m)) + O(n*logn) + O(m*logm) where n and m are the sizes of the given arrays.
// space: O(1), no extra space is used
void merge2(long long arr1[], long long arr2[], int n, int m){
    // declare 2 pointers
    int left = n-1;
    int right = 0;

    // swap the elements until arr1[left] <= arr2[right]
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break; // no need to swap, as arr1 is already sorted
        }
    }
    sort(arr1, arr1+n); // sort the first array
    sort(arr2, arr2+m); // sort the second array
}

// optimal approach using gap method
// time: O(n*logn) + O(m*logm) where n and m are the sizes of the given arrays.
// space: O(1), no extra space is used
// approach:
// Steps:
// Initialize the Gap:
// gap = ceil((n + m) / 2) where n and m are the sizes of arr1 and arr2.
// Loop until gap becomes 0:
//  Set two pointers: left = 0 and right = left + gap.
//  Compare elements at left and right across:
//   Same array (arr1 or arr2): Compare and swap directly.
//   Different arrays: Adjust indices (e.g., arr1[left] vs arr2[right - n]) and swap if needed.
// Increment both pointers and continue until right reaches n + m.
// After the loop, update: gap = ceil(gap / 2).
// Result:
//  After the final iteration, all elements will be in the correct sorted order across both arrays.
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}
void merge3(long long arr1[], long long arr2[], int n, int m){
    int len = n+m;
    // initialize gap
    int gap = (len/2) + (len%2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            // case 1: left in arr1[]
            // and right in arr2[]
            if(left < n && right >= n){
                swapIfGreater(arr1, arr2, left, right-n);
            }
            // case 2: both pointers in arr2[]
            else if(left >= n){
                swapIfGreater(arr2, arr2, left-n, right-n);
            }
            // case 3: both pointers in arr1[]:
            else{
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if(gap == 1)
            break;
        gap = (gap/2) + (gap%2);
    }
}