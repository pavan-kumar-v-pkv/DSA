// Given two sorted arrays a and b of size m and n respectively. Find the kth
// element of the final sorted array.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(n1+n2)
// space: O(n1+n2)
int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    vector<int> merged;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            merged.push_back(a[i]);
            i++;
        } else {
            merged.push_back(b[j]);
            j++;
        }
    }
    while(i < n1) {
        merged.push_back(a[i]);
        i++;
    }
    while(j < n2) {
        merged.push_back(b[j]);
        j++;
    }
    return merged[k - 1]; // k is 1-based index
}

// better approach
// time: O(n1+n2)
// space: O(1)
int kthElement2(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    int ele = -1;
    int cnt = 0;
    int i=0, j=0;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            if(cnt == k - 1) ele = a[i];
            i++;
        } else {
            if(cnt == k - 1) ele = b[j];
            j++;
        }
        cnt++;
    }
    while(i < n1){
        if(cnt == k - 1) ele = a[i];
        i++;
        cnt++;
    }
    while(j < n2){
        if(cnt == k - 1) ele = b[j];
        j++;
        cnt++;
    }
    return ele;
}

// optimal approach: binary search
// time: O(log(min(n1, n2)))
// space: O(1)
int kthElement3(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2) {
        return kthElement3(b, a, k); // ensure n1 <= n2
    }
    // Now n1 <= n2
    // Binary search range: how many elements to take from 'a'
    // minimum we can take from 'a' = max(0, k-n2) (if 'b' has less than k elements)
    // maximum we can take from 'a' = min(k, n1) (can't take more than k elements or more than n1 elements)
    int low = max(0, k-n2);
    int high = min(k, n1);
    while(low <= high){
        int mid1 = low + (high-low)/2;
        int mid2 = k - mid1;
        // boundary elements
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 > n1) r1 = a[mid1];
        if(mid2 > n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1-1];
        if(mid2 - 1 >= 0) l2 = b[mid2-1];

        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2); // found the kth element
        }
        else if(l1 > r2){
            // we need to take fewer elements from 'a'
            high = mid1 - 1;
        } else {
            // we need to take more elements from 'a'
            low = mid1 + 1;
        }
    }
    return -1;    
}