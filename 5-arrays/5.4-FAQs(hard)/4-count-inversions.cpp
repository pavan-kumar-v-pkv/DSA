// Given an integer array nums. Return the number of inversions in the array.
// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// It indicates how close an array is to being sorted.
// A sorted array has an inversion count of 0.
// An array sorted in descending order has maximum inversion.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2), where N is the number of elements in the array
// space: O(1), no extra space is used
int numberOfInversions(vector<int>& a, int n){
    // count the number of pairs
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[i] > a[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

// better approach using merge sort
// time: O(N log N), where N is the number of elements in the array
// space: O(N), where N is the number of elements in the array
// approach: https://takeuforward.org/data-structure/count-inversions-in-an-array/
int merge(vector<int>& a, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int cnt = 0; // count of inversions
    while(left <= mid && right <=high){
        if(a[left] <= a[right]){
            temp.push_back(a[right]);
            left++;
        }
        else{
            // a[left] > a[right], so all elements from left to mid are greater than a[right]
            cnt += (mid - left + 1); // count inversions
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        a[i] = temp[i-low]; // copy back to original array
    }
    return cnt; // return the count of inversions
}
int mergeSort(vector<int>& a, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt; // base case, no inversions in a single element
    int mid = low + (high-low)/2;
    cnt += mergeSort(a, low, mid); // count inversions in left half
    cnt += mergeSort(a, mid+1, high); // count inversions in right half
    cnt += merge(a, low, mid, high);
    return cnt;
}
int numberOfInversions2(vector<int>& a, int n){
    return mergeSort(a, 0, n-1);
}
