// Given two sorted arrays arr1 and arr2 of size m and n respectively, return 
// the median of the two sorted arrays.
// The median is defined as the middle value of a sorted list of numbers. In 
// case the length of the list is even, the median is the average of the two 
// middle elements.
#include <bits/stdc++.h>
using namespace std;    

// brute force approach
// time: O(n1+n2)
// space: O(n1+n2)
double median(vector<int>& a, vector<int>& b){
    int n1 = a.size(), n2 = b.size();
    vector<int> merged;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }
    }
    // copy remaining elements
    while(i<n1){
        merged.push_back(a[i]);
        i++;
    }
    while(j<n2){
        merged.push_back(b[j]);
        j++;
    }
    // find the median
    int n = n1+n2;
    if(n%2==1)
        return (double)merged[n/2];
    double median = ((double)merged[n/2] + (double)merged[(n/2)-1]) / 2.0;
    return median;
}

// better approach
// time: O(n1+n2)
// space: O(1)
double median2(vector<int>& a, vector<int>& b){
    int n1= a.size(), n2 = b.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int el1 = -1, el2 = -1;

    // apply the merge step of merge sort
    int i=0, j=0;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            if(cnt == ind1) el1 = a[i];
            if(cnt == ind2) el2 = a[i];
            i++;
        }
        else{
            if(cnt == ind1) el1 = b[j];
            if(cnt == ind2) el2 = b[j];
            j++;
        }
    }
    while(i < n1){
        if(cnt == ind1) el1 = a[i];
        if(cnt == ind2) el2 = a[i];
        i++;
    }
    while(j < n2){
        if(cnt == ind1) el1 = b[j];
        if(cnt == ind2) el2 = b[j];
        j++;    
    }
    // find the median
    if(n % 2 == 1)
        return (double)el2;
    return ((double)el1 + (double)el2) / 2.0;
}

// optimal approach
// time: O(log(min(n1, n2)))
// space: O(1)
// approach: binary search
// Ensure arr1 is the smaller array. If not, swap arr1 and arr2.
// Set pointers:
//  low = 0
//  high = n1 (size of smaller array)
// Binary Search Loop:
//  Compute the partition indices:
//      mid1 = (low + high) // 2
//      mid2 = (n1 + n2 + 1) // 2 - mid1
//  Get boundary elements:
//      l1 = arr1[mid1 - 1] or -∞ if mid1 == 0
//      l2 = arr2[mid2 - 1] or -∞ if mid2 == 0
//      r1 = arr1[mid1] or +∞ if mid1 == n1
//      r2 = arr2[mid2] or +∞ if mid2 == n2
// Check valid partition:
//  If l1 ≤ r2 and l2 ≤ r1:
//      If total length is odd: return max(l1, l2)
//      If even: return (max(l1, l2) + min(r1, r2)) / 2
// Adjust search:
//  If l1 > r2: move left → high = mid1 - 1
//  If l2 > r1: move right → low = mid1 + 1
// Final step: Add a dummy return at the end to avoid compile errors.
double median3(vector<int>& a, vector<int>& b){
    int n1 = a.size(), n2 = b.size();
    // if n1 is bigger than n2, swap them
    if(n1 > n2) return median3(b, a);
    int n = n1 + n2;
    int left = (n + 1)/2; // length of left partition
    // binary search on smaller array
    int low = 0, high = n1;
    while(low <= high){
        int mid1 = low + (high-low)/2; // partition index for a
        int mid2 = left - mid1; // partition index for b
        // get boundary elements
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2)))/2.0;        
        }
        // eliminate the halves:
        else if(l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0.0;
}