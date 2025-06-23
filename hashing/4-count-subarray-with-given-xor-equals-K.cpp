// Given an array of integers nums and an integer k, return the total number 
// of subarrays whose XOR equals to k.
#include <bits/stdc++.h>
using namespace std;

// brute force solution
// time complexity: O(n^2)
// space complexity: O(1)
int countSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    int cnt = 0;

    for(int i=0;i<n;i++){
        int xorr = 0;
        for(int j=i;j<n;j++){
            xorr = xorr ^ arr[j];
            if(xorr == k){
                cnt++;
            }
        }
    }
    return cnt;
}

// optimized solution using hashing
// time complexity: O(n) or O(nlogn) depending on the implementation of the unordered_map
// space complexity: O(n)
int countSubarraysOptimized(vector<int>& arr, int k){
    int n = arr.size();
    // map <prefix XOR, count of occurrences>
    unordered_map<int, int> preXorMap;
    int preXor = 0;
    int cnt = 0;
    preXorMap[0] = 1; // to handle the case when prefix XOR equals k at some index
    for(int i=0;i<n;i++){
        // add current element to prefix XOR
        preXor = preXor ^ arr[i];
        // calculate the remaining part of the prefix XOR
        int rem = preXor ^ k; // XOR with k to find the required prefix XOR
        // add the number of subarrays to be removed
        cnt += preXorMap[rem];
        // update the count of prefix XOR in the map
        preXorMap[preXor]++;
    }
    return cnt;
}